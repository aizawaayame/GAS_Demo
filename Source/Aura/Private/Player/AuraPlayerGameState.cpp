


#include "Player/AuraPlayerGameState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraPlayerGameState::AAuraPlayerGameState()
{
	// Default 500.f is too low
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAuraPlayerGameState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
