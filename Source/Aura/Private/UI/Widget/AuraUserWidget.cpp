


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* WidgetController0)
{
	this->WidgetController = WidgetController0;
	OnWidgetControllerSet();
}
