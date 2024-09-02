// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayer.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerGameState.h"

AAuraPlayer::AAuraPlayer()	
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}


void AAuraPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void AAuraPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

void AAuraPlayer::InitAbilityActorInfo()
{
	AAuraPlayerGameState* AuraPlayerGameState = GetPlayerState<AAuraPlayerGameState>();
	check(AuraPlayerGameState);
	AuraPlayerGameState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerGameState, this);
	AbilitySystemComponent = AuraPlayerGameState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerGameState->GetAttributeSet();
}