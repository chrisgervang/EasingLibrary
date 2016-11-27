/*
 * Easing Functions: Copyright (c) 2010 Andy Brown
 * http://www.andybrown.me.uk
 *
 * This work is licensed under a Creative Commons
 * Attribution-ShareAlike 3.0 Unported License.
 * http://creativecommons.org/licenses/by-sa/3.0/
 */

#include <stdint.h>
#include <wiring.h>
#include "Tester.h"
#include "EasingLibrary.h"


/*
 * Map of height to the characters to show in the column for bar chart
 */

static const uint8_t VerticalBarColumnDataMap[33][4]=
{
		{ 32,32,32,32 },

		{ 32,32,32, 0 },
		{ 32,32,32, 1 },
		{ 32,32,32, 2 },
		{ 32,32,32, 3 },
		{ 32,32,32, 4 },
		{ 32,32,32, 5 },
		{ 32,32,32, 6 },
		{ 32,32,32, 7 },

		{ 32,32, 0, 7 },
		{ 32,32, 1, 7 },
		{ 32,32, 2, 7 },
		{ 32,32, 3, 7 },
		{ 32,32, 4, 7 },
		{ 32,32, 5, 7 },
		{ 32,32, 6, 7 },
		{ 32,32, 7, 7 },

		{ 32, 0, 7, 7 },
		{ 32, 1, 7, 7 },
		{ 32, 2, 7, 7 },
		{ 32, 3, 7, 7 },
		{ 32, 4, 7, 7 },
		{ 32, 5, 7, 7 },
		{ 32, 6, 7, 7 },
		{ 32, 7, 7, 7 },

		{  0, 7, 7, 7 },
		{  1, 7, 7, 7 },
		{  2, 7, 7, 7 },
		{  3, 7, 7, 7 },
		{  4, 7, 7, 7 },
		{  5, 7, 7, 7 },
		{  6, 7, 7, 7 },
		{  7, 7, 7, 7 }
};


static const uint8_t VerticalLineColumnDataMap[33][4]=
{
		{ 32,32,32,32 },

		{ 32,32,32, 0 },
		{ 32,32,32, 1 },
		{ 32,32,32, 2 },
		{ 32,32,32, 3 },
		{ 32,32,32, 4 },
		{ 32,32,32, 5 },
		{ 32,32,32, 6 },
		{ 32,32,32, 7 },

		{ 32,32, 0, 32 },
		{ 32,32, 1, 32 },
		{ 32,32, 2, 32 },
		{ 32,32, 3, 32 },
		{ 32,32, 4, 32 },
		{ 32,32, 5, 32 },
		{ 32,32, 6, 32 },
		{ 32,32, 7, 32 },

		{ 32, 0, 32, 32 },
		{ 32, 1, 32, 32 },
		{ 32, 2, 32, 32 },
		{ 32, 3, 32, 32 },
		{ 32, 4, 32, 32 },
		{ 32, 5, 32, 32 },
		{ 32, 6, 32, 32 },
		{ 32, 7, 32, 32 },

		{  0, 32, 32, 32 },
		{  1, 32, 32, 32 },
		{  2, 32, 32, 32 },
		{  3, 32, 32, 32 },
		{  4, 32, 32, 32 },
		{  5, 32, 32, 32 },
		{  6, 32, 32, 32 },
		{  7, 32, 32, 32 }
};


/*
 * Easing parameters for a back-ease, scale values to be in range
 */

static const EasingParameterSet backVerticalParams=
{
	{ 3.0,0.91429 },
	{ 0.0,0.91429 },
	{ 3,0.84211 }
}, backHorizontalParams=
{
	{ 10.0,0.90909 },
	{ 0.0,0.90909 },
	{ 10.0,0.83333 }
};


/*
 * Easing parameters for an elastic ease
 */

static const EasingParameterSet elasticVerticalParams=
{
	{ 12.0,0.72727 },
	{ 0.0,0.72727 },
	{ 4.0,0.8 }
},elasticHorizontalParams=
{
	{ 37.0,0.72993 },
	{ 0.0,0.72993 },
	{ 12,0.80645 }
};


/*
 * Constructor
 */

Tester::Tester()
	: _lcd(2,3,4,5,6,7)
{
// this is a 20x4 display

	_lcd.begin(20,4);
}



/*
 * Create custom chars for a bar chart
 */

void Tester::createVerticalBarCharacters()
{
	uint8_t charData[8],*ptr;
	int i;

	memset(charData,0,sizeof(charData));
	ptr=&charData[7];
	i=0;
	do
	{
		*ptr--=0xff;
  	_lcd.createChar(i++,charData);
  } while(i<=7);
}


/*
 * Create custom chars for a horizontal bar chart
 */

void Tester::createHorizontalBarCharacters()
{
	uint8_t charData[8];

	memset(charData,16,sizeof(charData));
	_lcd.createChar(0,charData);
	memset(charData,24,sizeof(charData));
	_lcd.createChar(1,charData);
	memset(charData,28,sizeof(charData));
	_lcd.createChar(2,charData);
	memset(charData,30,sizeof(charData));
	_lcd.createChar(3,charData);
	memset(charData,31,sizeof(charData));
	_lcd.createChar(4,charData);
}


/*
 * Create custom chars for a line chart
 */

void Tester::createVerticalLineCharacters()
{
	uint8_t charData[8],*ptr;
	int i;

	memset(charData,0,sizeof(charData));
	ptr=&charData[7];
	i=0;
	do
	{
		*ptr=0xff;

		if(i>0)
			ptr[1]=0;

		ptr--;
  	_lcd.createChar(i++,charData);
  } while(i<=7);
}


/*
 * Run the tests
 */

void Tester::run()
{
	BackEase back;
	BounceEase bounce;
	CircularEase circular;
	CubicEase cubic;
	ElasticEase elastic;
	ExponentialEase exponential;
	LinearEase linear;
	QuadraticEase quadratic;
	QuarticEase quartic;
	QuinticEase quintic;
	SineEase sine;

// run each test animation. Back and Elastic generate positions outside of the
// normal range so we scale those values back to within the range on the LCD.

	runTest(back,"Back",&backVerticalParams,&backHorizontalParams);
	runTest(circular,"Circular");
	runTest(bounce,"Bounce");
	runTest(cubic,"Cubic");
	runTest(elastic,"Elastic",&elasticVerticalParams,&elasticHorizontalParams);
	runTest(exponential,"Exponent");
	runTest(linear,"Linear");
	runTest(quadratic,"Quadratic");
	runTest(quartic,"Quartic");
	runTest(quintic,"Quintic");
	runTest(sine,"Sine");
}


/*
 * Run the test
 */

void Tester::runTest(
		EasingBase& easingMethod_,
		const char *method_,
		const EasingParameterSet *verticalParams_,
		const EasingParameterSet *horizontalParams_)
{
// demonstrate the three types

	runTest(easingMethod_,&EasingBase::easeIn,
					method_,
					"Ease in",
					verticalParams_==NULL ? NULL : &verticalParams_->_inParams,
					horizontalParams_==NULL ? NULL : &horizontalParams_->_inParams);

	runTest(easingMethod_,
					&EasingBase::easeOut,
					method_,
					"Ease out",
					verticalParams_==NULL ? NULL : &verticalParams_->_outParams,
					horizontalParams_==NULL ? NULL : &horizontalParams_->_outParams);

	runTest(easingMethod_,
					&EasingBase::easeInOut,
					method_,
					"Ease both",
					verticalParams_==NULL ? NULL : &verticalParams_->_inOutParams,
					horizontalParams_==NULL ? NULL : &horizontalParams_->_inOutParams);
}


/*
 * Run the test on an easing method (in,out,inout)
 */

void Tester::runTest(
		EasingBase& easingMethod_,
		NUMBER(EasingBase::*easer_)(NUMBER) const,
		const char *method_,
		const char *type_,
		const EasingParameters *verticalParams_,
		const EasingParameters *horizontalParams_)
{
	int i;
	NUMBER t,easedPosition;
	int heights[61];
	char buffer[21];

// show type of easing

	_lcd.clear();
	lcdPrint(0,0,method_);
	lcdPrint(1,0,type_);

// generate the heights for the vertical bars (4 chars * 8 lines per char)

	easingMethod_.setDuration(2);				// 2 units, which we will interpret as seconds
	easingMethod_.setTotalChangeInPosition(32);

	t=0;
	for(i=0;i<=40;i++)
	{
		easedPosition=(easingMethod_.*easer_)(t);

		if(verticalParams_==NULL)
			heights[i]=static_cast<int>(round(easedPosition));
		else
			heights[i]=static_cast<int>((round(easedPosition)+verticalParams_->_offset)*verticalParams_->_scale);

		t+=0.05;				// add on 5/100 second
	}

// animate the vertical bars

	animateVertically(heights);
	delay(1000);

// now horizontal
// show the type of easing

	_lcd.clear();
	sprintf(buffer,"%s - %s",method_,type_);
	lcdPrint(0,0,buffer);

// generate the heights for the horizontal bars

	t=0;
	easingMethod_.setDuration(3);									// 3 units for this one (units = seconds)
	easingMethod_.setTotalChangeInPosition(100);

	t=0;
	for(i=0;i<=60;i++)
	{
		easedPosition=(easingMethod_.*easer_)(t);

		if(horizontalParams_==NULL)
			heights[i]=static_cast<int>(round(easedPosition));
		else
			heights[i]=static_cast<int>((round(easedPosition)+horizontalParams_->_offset)*horizontalParams_->_scale);

		t+=0.05;
	}

// animate the vertical bars

	animateHorizontally(heights);
	delay(1000);
}


/*
 * Animate the bars horizontally
 */

void Tester::animateHorizontally(int *heights_)
{
	int i,j,first,last;

// set custom LCD chars

	createHorizontalBarCharacters();

// advance along a timeline of 66 where each of the 3 bars start at 0,2,4 units
// on the timeline and last for 60 units. 1 unit equals the time to show the row
// on the LCD plus 40ms.

	for(i=0;i<=66;i++)
	{
		for(j=0;j<3;j++)
		{
			first=j*2;
			last=first+60;

			if(i>=first && i<=last)
				showRow(j+1,heights_[i-first]);
		}

		delay(40);
	}
}


/*
 * Show a row
 */

void Tester::showRow(int row_,int height_)
{
	int i;
	uint8_t b;

// overwrite the entire column because we want this function to execute in constant time.

	for(i=0;i<20;i++)
	{
	// pick out the correct character for this column (32 = blank space)

		if(i<height_/5)
			b=4;
		else if(i==height_/5)
			b=height_ % 5;
		else
			b=32;

		_lcd.setCursor(i,row_);
		_lcd.write(b);
	}
}


/*
 * Animate the bars vertically
 */

void Tester::animateVertically(int *heights_)
{
	int i;

// bars first

	createVerticalBarCharacters();
	animateVerticalBars(heights_,VerticalBarColumnDataMap);

// wait for a second

	delay(1000);

// clear bars area

	for(i=0;i<4;i++)
		lcdPrint(i,10,"          ");

// now lines

	createVerticalLineCharacters();
	animateVerticalBars(heights_,VerticalLineColumnDataMap);
}


/*
 * animate vertically
 */


void Tester::animateVerticalBars(int *heights_,const uint8_t columnDataMap[][4])
{
	int i,j,first,last;

// advance along a timeline of 60 where each of the 10 bars start at 0,2,4,6,8,10,12,14,16,18 units
// on the timeline and last for 40 units. 1 unit equals the time to show the row
// on the LCD plus 40ms.

	for(i=0;i<=60;i++)
	{
		for(j=0;j<10;j++)
		{
			first=j*2;
			last=first+40;

			if(i>=first && i<=last)
				showColumn(j+10,heights_[i-first],columnDataMap);
		}

		delay(40);
	}
}



/*
 * Show a single column of results
 */

void Tester::showColumn(uint8_t col_,int height_,const uint8_t columnDataMap[][4])
{
	uint8_t b;
	int i;

// we do this one using a table that maps the height (0-32) to the custom
// LCD character

	for(i=0;i<4;i++)
	{
		b=columnDataMap[height_][i];
		_lcd.setCursor(col_,i);
		_lcd.write(b);
	}
}



/*
 * Print to the LCD - helper function
 */

void Tester::lcdPrint(uint8_t row_,uint8_t col_,const char *text_)
{
	_lcd.setCursor(col_,row_);
	_lcd.print(text_);
}
