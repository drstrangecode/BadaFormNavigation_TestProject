#ifndef _FORM2_H_
#define _FORM2_H_

#include <FBase.h>
#include <FUi.h>

#include "Forms/FormNavigationManager.h"
#include "Forms/StackBasedNavigationForm.h"

class Form2 : public DSBadaUtilityLib::StackBasedNavigationForm,
              public Osp::Ui::IActionEventListener
{

// Construction
public:
	Form2(void);
	virtual ~Form2(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_NEXT = 101;
	static const int ID_BUTTON_PREV = 102;

	Osp::Ui::Controls::Button *__pButtonNext;
	Osp::Ui::Controls::Button *__pButtonPrev;
	Osp::Ui::Controls::Label *__pLabel;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	// IStackBasedNavigationForm
	virtual void FormWillAppear();
	virtual void FormWillDisappear();
	virtual void ReceivedLowMemoryAlert();
	virtual void ReceivedLowBatteryAlert();

};

#endif	//_FORM1_H_
