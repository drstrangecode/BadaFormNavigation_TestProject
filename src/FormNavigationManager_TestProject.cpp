/**
 * Name        : FormNavigationManager_TestProject
 * Version     : 
 * Vendor      : 
 * Description : 
 */

#include "FormNavigationManager_TestProject.h"
#include "Form1.h"

#include "Forms/FormNavigationManager.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

using namespace DSBadaUtilityLib;

FormNavigationManager_TestProject::FormNavigationManager_TestProject() {
}

FormNavigationManager_TestProject::~FormNavigationManager_TestProject() {
}

Application* FormNavigationManager_TestProject::CreateInstance(void) {
    // Create the instance through the constructor.
    return new FormNavigationManager_TestProject();
}

bool FormNavigationManager_TestProject::OnAppInitializing(AppRegistry& appRegistry) {

    Form1 * form = new Form1();
    form->Initialize();

    FormNavigationManager::GetInstance()->SetRootForm(form);

    return true;
}

bool FormNavigationManager_TestProject::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination) {
    FormNavigationManager::GetInstance()->Terminate();
    return true;
}

void FormNavigationManager_TestProject::OnForeground(void) {
    FormNavigationManager::GetInstance()->Foreground();
}

void FormNavigationManager_TestProject::OnBackground(void) {
    FormNavigationManager::GetInstance()->Background();
}

void FormNavigationManager_TestProject::OnLowMemory(void) {
    FormNavigationManager::GetInstance()->LowMemoryAlert();
}

void FormNavigationManager_TestProject::OnBatteryLevelChanged(BatteryLevel batteryLevel) {
    if (batteryLevel == BATTERY_LOW || batteryLevel == BATTERY_CRITICAL) {
        FormNavigationManager::GetInstance()->LowBatteryAlert();
    }
}

void FormNavigationManager_TestProject::OnScreenOn(void) {
    // TODO:
    // Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void FormNavigationManager_TestProject::OnScreenOff(void) {
    // TODO:
    //  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
    // Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
    // Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
