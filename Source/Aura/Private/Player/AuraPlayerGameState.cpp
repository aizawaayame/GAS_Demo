


#include "Player/AuraPlayerGameState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerGameState::AAuraPlayerGameState()
{
	// Default 500.f is too low
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAuraPlayerGameState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
