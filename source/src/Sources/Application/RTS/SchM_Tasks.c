/*============================================================================*/
/*                        Continental AEP 2015                                */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler_Tasks.c
* Instance:         RPL_1
* %version:         1.6
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file allocates the periodic tasks executed by the  */
/*                    scheduler				                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |File added to complete 		   | Misael AD        */
/*        	 |   		   |scheduler structure 		   |  				  */
/*  1.2      | 16/07/2015  |Periodic tasks                 | Misael AD        */
/*  1.3      | 21/07/2015  |Buttons & EWCM state machines  | Misael AD        */
/*  1.4      | 21/07/2015  |Operation modes issue fixed	   | Misael AD        */
/*  1.5      | 22/07/2015  |AntiPinch functionality finish | Misael AD        */
/*  1.6      | 22/07/2015  |MISRA issues fixing			   | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Tasks.h"
#include "SchM_Types.h"

#include "windowlifter.h"
#include "LED.h"
#include "switch.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */

/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */
T_SBYTE	rsb_WindowState = WINDOW_IDLE;

static T_SBYTE	rsb_ButtonState = SWITCH_IDLE;

extern T_SBYTE  rsw_WindowPosition;

static T_UBYTE rub_PinchTimer= CLEAR;

static T_UBYTE	rub_PinchFlag = CLEAR;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define	TICKS(ticks)	(ticks)

/* Private functions prototypes */
/* ---------------------------- */
static void VerifyPinch(void);
static void TriggerAntiPinch(void);

/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 :	VerifyPinch
 *  Description          :	Verufies if a PINCH signal is valid
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :	No
 **************************************************************/
void VerifyPinch(void)
{
	if(rub_PinchTimer >= TICKS(4))
	{
		rub_PinchFlag = SET_FLAG;
		rub_PinchTimer=	CLEAR;
	}
	else
	{
		/* Do nothing */
	}
}

/**************************************************************
 *  Name                 :	TriggerAntiPinch
 *  Description          :	Starts AntiPinch functionality if 
 *								flag has been SET
 *  Parameters           :  None
 *  Return               :	None
 *  Critical/explanation :	No
 **************************************************************/
void TriggerAntiPinch(void)
{
	if(rub_PinchFlag == SET_FLAG)
	{
		windowlifter_PINCH();
		rsb_WindowState=PINCH_OPEN;
	}
	else
	{
		/* Do nothing */
	}
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Task1p25ms
 *  Description          :	Task activated every 1.25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task1p25ms(void)
{
	static T_UWORD	rwb_ValidationTime;
	switch(rsb_ButtonState)
	{
		case SWITCH_IDLE:
				if(Switch_Combination())
				{
					/* None pressed or both pressed */
				}
				else if(Switch_Read(UP))
				{
					rsb_ButtonState = SWITCH_VALID_UP;
				}
				else if(Switch_Read(DOWN))
				{
					rsb_ButtonState = SWITCH_VALID_DOWN;
				}
				else
				{
					/* Do nothing */
				}
			break;
		case SWITCH_VALID_UP:
				if(Switch_Read(UP))
				{
					rwb_ValidationTime++;
					if(rwb_ValidationTime == TICKS(8))
					{
						rsb_WindowState=WINDOW_AUTO_UP;
					}
					else if(rwb_ValidationTime >= TICKS(400))
					{
						rsb_WindowState=WINDOW_MANUAL_UP;
						rsb_ButtonState=SWITCH_MOVING;
					}
					else
					{
						/* Do nothing */
					}
				}
				else
				{
					if((rwb_ValidationTime < TICKS(8)) || (rsb_WindowState == WINDOW_AUTO_UP))
					{
						rsb_ButtonState=SWITCH_IDLE;
					}
					else
					{
						rsb_ButtonState=SWITCH_MOVING;
					}
					rwb_ValidationTime=CLEAR;
				}
			break;
		case SWITCH_VALID_DOWN:
				if(Switch_Read(DOWN))
				{
					rwb_ValidationTime++;
					if(rwb_ValidationTime == TICKS(8))
					{
						rsb_WindowState=WINDOW_AUTO_DOWN;
					}
					else if(rwb_ValidationTime >= TICKS(400))
					{
						rsb_WindowState=WINDOW_MANUAL_DOWN;
						rsb_ButtonState=SWITCH_MOVING;
					}
					else
					{
						/* Do nothing */
					}
				}
				else
				{
					if((rwb_ValidationTime < TICKS(8)) || (rsb_WindowState == WINDOW_AUTO_DOWN))
					{
						rsb_ButtonState=SWITCH_IDLE;
					}
					else
					{
						rsb_ButtonState=SWITCH_MOVING;
					}
					rwb_ValidationTime=CLEAR;
				}
			break;
		case SWITCH_MOVING:
				rwb_ValidationTime=CLEAR;
			break;
		default:
		break;
	}
}

/**************************************************************
 *  Name                 :	SchM_Task2p5ms
 *  Description          :	Task activated every 2.5ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task2p5ms(void)
{
	if(Switch_Read(PINCH))
	{
		rub_PinchTimer++;
		VerifyPinch();
	}
	else
	{
		VerifyPinch();
		rub_PinchTimer=CLEAR;
	}
}

/**************************************************************
 *  Name                 :	SchM_Task5ms
 *  Description          :	Task activated every 5ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task5ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task10ms
 *  Description          :	Task activated every 10ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task10ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task20ms
 *  Description          :	Task activated every 20ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task20ms(void)
{
	LED_WindowLifter(rsw_WindowPosition);
}

/**************************************************************
 *  Name                 :	SchM_Task40ms
 *  Description          :	Task activated every 40ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task40ms(void)
{
	static T_UBYTE	rub_Period;
	rub_Period++;
	switch(rsb_WindowState)
	{
		case WINDOW_IDLE:
				rub_Period=0;
				rsb_ButtonState=SWITCH_IDLE;
				LEDs_Off();
		break;
			
		case WINDOW_AUTO_UP:
				if(rub_Period==TICKS(10))
				{
					rub_Period=CLEAR;
					windowlifter_UP();
					TriggerAntiPinch();
				}
				else
				{
					/* Do nothing */
				}
		break;
			
		case WINDOW_AUTO_DOWN:
				if(rub_Period==TICKS(10))
				{
					rub_Period=CLEAR;
					windowlifter_DOWN();
				}
				else
				{
					/* Do nothing */
				}
		break;
			
		case WINDOW_MANUAL_UP:
				if(rub_Period==TICKS(10))
				{
					rub_Period=CLEAR;
					if(Switch_Read(UP))
					{
						windowlifter_UP();
						TriggerAntiPinch();
					}
					else
					{
						rsb_WindowState=WINDOW_IDLE;
					}
				}
				else
				{
					/* Do nothing */
				}
		break;
			
		case WINDOW_MANUAL_DOWN:
				if(rub_Period==TICKS(10))
				{
					rub_Period=CLEAR;
					if(Switch_Read(DOWN))
					{
						windowlifter_DOWN();
					}
					else
					{
						rsb_WindowState=WINDOW_IDLE;
					}
				}
				else
				{
					/* Do nothing */
				}
		break;
			
		case PINCH_OPEN:
				if(rub_Period==TICKS(10))
				{
					rub_Period=CLEAR;
					windowlifter_PINCH();
				}
				else
				{
					/* Do nothing */
				}
		break;
			
		case PINCH_IDLE:
				if(rub_Period>=TICKS(125))
				{
					rub_Period=CLEAR;
					rub_PinchFlag=CLEAR;
					rsb_WindowState=WINDOW_IDLE;
				}
				else
				{
					/* Do nothing */
				}
		break;
			
		default:
		break;
	}	
}
