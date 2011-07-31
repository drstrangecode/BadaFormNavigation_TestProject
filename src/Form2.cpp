#include "Form1.h"
#include "Form2.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace DSBadaUtilityLib;

Form2::Form2(void) {
}

Form2::~Form2(void) {
}

bool Form2::Initialize() {
    Construct(L"IDF_FORM_2");
    return true;
}

result Form2::OnInitializing(void) {
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

result Form2::OnTerminating(void) {
    AppLog("Form2::OnTerminating()");
    result r = E_SUCCESS;
    return r;
}

void Form2::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {
    switch (actionId) {
        case ID_BUTTON_PREV:
            FormNavigationManager::GetInstance()->PopForm();
            break;
        case ID_BUTTON_NEXT: {
            Form1 * form = new Form1();
            form->Initialize();
            FormNavigationManager::GetInstance()->PushForm(form);
        }
        break;

        default:
            break;
    }
}

void Form2::FormWillAppear() {
    AppLog("Form2::FormWillAppear()");
}

void Form2::FormWillDisappear() {
    AppLog("Form2::FormWillDisappear()");
}

void Form2::ReceivedLowMemoryAlert() {
    AppLog("Form2::ReceivedLowMemoryAlert()");
}

void Form2::ReceivedLowBatteryAlert() {
    AppLog("Form2::ReceivedLowBatteryAlert()");
}
