// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/Highlight.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlight
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
	
	virtual void Highlight() override;
	virtual void Unhighlight() override;
};
