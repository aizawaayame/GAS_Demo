

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* WidgetController0);
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetControllerSet();
public:

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
};
