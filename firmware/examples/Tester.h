/*
 * Easing Functions: Copyright (c) 2010 Andy Brown
 * http://www.andybrown.me.uk
 *
 * This work is licensed under a Creative Commons
 * Attribution_ShareAlike 3.0 Unported License.
 * http://creativecommons.org/licenses/by_sa/3.0/
 */

#ifndef __1E7213A1_22C1_461c_A944_BFDCA5DEE887
#define __1E7213A1_22C1_461c_A944_BFDCA5DEE887

#include "EasingBase.h"
#include "LiquidCrystal.h"
#include "EasingParameterSet.h"


/*
 * Test class
 */

class Tester
{
private:
	LiquidCrystal _lcd;

private:
	void createVerticalBarCharacters();
	void createVerticalLineCharacters();
	void createHorizontalBarCharacters();

	void runTest(EasingBase& easingMethod_,const char *method_,const EasingParameterSet *verticalParams_=NULL,const EasingParameterSet *horizontalParams_=NULL);
	void runTest(EasingBase& easingMethod_,NUMBER(EasingBase::*easer)(NUMBER) const,const char *method_,const char *type_,const EasingParameters *verticalParams_,const EasingParameters *horizontalParams_);

	void lcdPrint(uint8_t row_,uint8_t col_,const char *text_);
	void showColumn(uint8_t col_,int height_,const uint8_t columnDataMap[][4]);
	void animateVertically(int *heights_);
	void animateVerticalBars(int *heights_,const uint8_t columnDataMap[][4]);
	void showRow(int row_,int height_);
	void animateHorizontally(int *height_);

public:
	Tester();

	void run();
};


#endif
