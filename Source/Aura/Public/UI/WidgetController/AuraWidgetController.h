

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAbilitySystemComponent;
class UAuraAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControlerParams
{
	GENERATED_BODY()
public:
	FWidgetControlerParams()
		: PlayerController(nullptr)
		, PlayerState(nullptr)
		, AbilitySystemComponent(nullptr)
		, AttributeSet(nullptr){ }

	FWidgetControlerParams(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent,
		UAuraAttributeSet* AttributeSet)
		: PlayerController(PlayerController),
		  PlayerState(PlayerState),
		  AbilitySystemComponent(AbilitySystemComponent),
		  AttributeSet(AttributeSet)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAuraAttributeSet> AttributeSet;
};

class UAuraAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControlerParams& Params);

	UFUNCTION()
	virtual void BroadcastInitialization();

protected:
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<UAuraAttributeSet> AttributeSet;
};
