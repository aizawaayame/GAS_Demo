


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControlerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState	= Params.PlayerState;
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AuraAttributeSet = Params.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialization()
{
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
