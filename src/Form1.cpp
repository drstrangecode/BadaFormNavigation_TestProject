#include "Form1.h"
#include "Form2.h"
#include "Forms/FormNavigationManager.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace DSBadaUtilityLib;

Form1::Form1(void) {
}

Form1::~Form1(void) {
}

bool Form1::Initialize() {
    Construct(L"IDF_FORM_1");
    return true;
}

result Form1::OnInitializing(void) {
    result r = E_SUCCESS;

    __pButtonPrev = static_cast<Button *> (GetControl(L"IDC_BUTTON_PREV"));
    if (__pButtonPrev != null)
    {
        __pButtonPrev->SetActionId(ID_BUTTON_PREV);
        __pButtonPrev->AddActionEventListener(*this);
    }

    __pButtonNext = static_cast<Button *>(GetControl(L"IDC_BUTTON_NEXT"));
    if (__pButtonNext != null)
    {
        __pButtonNext->SetActionId(ID_BUTTON_NEXT);
        __pButtonNext->AddActionEventListener(*this);
    }

    __pLabel = static_cast<Label *> (GetControl(L"IDC_LABEL_FORM"));

    int formNumber = FormNavigationManager::GetInstance()->NumberOfFormsInCurrentStack();
    String labelText;
    labelText.Format(150, L"%d forms in navigation stack", formNumber);
    __pLabel->SetText(labelText);

    if (formNumber == 1) {
        __pButtonPrev->SetEnabled(false);
        __pButtonNext->SetEnabled(true);
    }
    else if (formNumber == 8) {
        __pButtonPrev->SetEnabled(true);
        __pButtonNext->SetEnabled(false);
    }
    else {
        __pButtonPrev->SetEnabled(true);
        __pButtonNext->SetEnabled(true);
    }

    return r;
}

result Form1::OnTerminating(void) {
    AppLog("Form1::OnTerminating()");
    result r = E_SUCCESS;
    return r;
}

void Form1::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
    switch (actionId) {
        case ID_BUTTON_PREV:
            FormNavigationManager::GetInstance()->PopForm();
            break;
        case ID_BUTTON_NEXT: {
            Form2 * form = new Form2();
            form->Initialize();
            FormNavigationManager::GetInstance()->PushForm(form);
        }
        break;

        default:
            break;
    }
}

void Form1::FormWillAppear() {
    AppLog("Form1::FormWillAppear()");
}

void Form1::FormWillDisappear() {
    AppLog("Form1::FormWillDisappear()");
}

void Form1::ReceivedLowMemoryAlert() {
    AppLog("Form1::ReceivedLowMemoryAlert()");
}

void Form1::ReceivedLowBatteryAlert() {
    AppLog("Form1::ReceivedLowBatteryAlert()");
}
