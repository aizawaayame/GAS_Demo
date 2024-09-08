


#include "UI/HUD/AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AuraOverlayWidgetController.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
}

UAuraOverlayWidgetController* AAuraHUD::GetOrCreateOverlayWidgetController(const FWidgetControlerParams& Params)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UAuraOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAuraAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass uninitialized, please fill it in BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass uninitialized, please fill it in BP_AuraHUD"));
	
	const auto Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	FWidgetControlerParams Params(PC, PS, ASC, AS);
	UAuraOverlayWidgetController* Controller = GetOrCreateOverlayWidgetController(Params);
	
	OverlayWidget->SetWidgetController(Controller);
	Controller->BroadcastInitialization();
	Widget->AddToViewport();
}
