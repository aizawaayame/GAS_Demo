


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CreateDefaultSubobject<USceneComponent>("SceneRoot");
}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (!TargetASC)
		return;
	
	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	FActiveGameplayEffectHandle ActiveGEHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	if (const auto GEDurationPolicy = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy;
		GEDurationPolicy == EGameplayEffectDurationType::Infinite)
	{
		ActiveEffectHandle2ASCPtrMap.Add(ActiveGEHandle, TargetASC);
	}
}

void AAuraEffectActor::RemoveEffectFromTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (!IsValid(TargetASC))
		return;
	
	TArray<FActiveGameplayEffectHandle> HandlesToRemove;
	for (const auto& Pair : ActiveEffectHandle2ASCPtrMap)
	{
		if (Pair.Value == TargetASC)
		{
			TargetASC->RemoveActiveGameplayEffect(Pair.Key);
			HandlesToRemove.Add(Pair.Key);
		}
	}
	
	for (const auto& Handle : HandlesToRemove)
	{
		ActiveEffectHandle2ASCPtrMap.FindAndRemoveChecked(Handle);
	}
}




