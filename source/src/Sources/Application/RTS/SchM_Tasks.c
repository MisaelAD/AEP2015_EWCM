/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler_Tasks.c
* Instance:         RPL_1
* %version:         1.3
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
T_SBYTE	rsb_ButtonState = SWITCH_IDLE;
extern T_SBYTE  rsw_WindowPosition;

T_UBYTE	rub_Period;

/* WORD RAM variables */
T_UWORD	rwb_ValidationTime;

/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
#define CLEAR		0
#define Ticks_8		8
#define Ticks_400	400
#define TICKS_125	125

/* Private functions prototypes */
/* ---------------------------- */


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


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Task1p25ms
 *  Description          :	Task activated every 3.125ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task1p25ms(void)
{
	switch(rsb_ButtonState)
	{
		case SWITCH_IDLE:
				if(!Switch_Combination())
				{
					/* None pressed or both pressed */
				}
				else if(Switch_UP())
				{
					rsb_WindowState = SWITCH_VALID_UP;
				}
				else if(Switch_DOWN())
				{
					rsb_WindowState = SWITCH_VALID_DOWN;
				}
				else
				{
					/* Do nothing */
				}
			break;
		case SWITCH_VALID_UP:
				if(Switch_UP())
				{
					rwb_ValidationTime++;
					if(rwb_ValidationTime == Ticks_8)
					{
						rsb_WindowState=WINDOW_AUTO_UP;
					}
					else if(rwb_ValidationTime >= Ticks_400)
					{
						rsb_WindowState=WINDOW_MANUAL_UP;
						rsb_ButtonState=SWITCH_EXIT;
					}
					else
					{
						/* Do nothing */
					}
				}
				else
				{
					if(rwb_ValidationTime < Ticks_8)
					{
						rsb_ButtonState=SWITCH_IDLE;
					}
					else
					{
						rsb_ButtonState=SWITCH_EXIT;
					}
					rwb_ValidationTime=CLEAR;
				}
			break;
		case SWITCH_VALID_DOWN:
				if(Switch_DOWN())
				{
					rwb_ValidationTime++;
					if(rwb_ValidationTime == Ticks_8)
					{
						rsb_WindowState=WINDOW_AUTO_DOWN;
					}
					else if(rwb_ValidationTime >= Ticks_400)
					{
						rsb_WindowState=WINDOW_MANUAL_DOWN;
						rsb_ButtonState=SWITCH_EXIT;
					}
					else
					{
						/* Do nothing */
					}
				}
				else
				{
					if(rwb_ValidationTime < Ticks_8)
					{
						rsb_ButtonState=SWITCH_IDLE;
					}
					else
					{
						rsb_ButtonState=SWITCH_EXIT;
					}
					rwb_ValidationTime=CLEAR;
				}
			break;
		case SWITCH_EXIT:
				if(Switch_Pinch())
				{
					rwb_ValidationTime++;
				}
				else if(rwb_ValidationTime>=Ticks_8)
				{
					rsb_WindowState=PINCH_OPEN;
					rwb_ValidationTime=CLEAR;
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

/**************************************************************
 *  Name                 :	SchM_Task2p5ms
 *  Description          :	Task activated every 6.25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task2p5ms(void)
{
	LED_WindowLifter(rsw_WindowPosition);
}

/**************************************************************
 *  Name                 :	SchM_Task5ms
 *  Description          :	Task activated every 12.25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task5ms(void)
{

}

/**************************************************************
 *  Name                 :	SchM_Task10ms
 *  Description          :	Task activated every 25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task10ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task20ms
 *  Description          :	Task activated every 50ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task20ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task40ms
 *  Description          :	Task activated every 100ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task40ms(void)
{
	rub_Period++;
	switch(rsb_WindowState)
	{
		case WINDOW_IDLE:
				rub_Period=0;
				rsb_ButtonState=SWITCH_IDLE;
			break;
		case WINDOW_AUTO_UP:
				if(rub_Period==Ticks_8)
				{
					windowlifter_UP();
					rub_Period=CLEAR;
				}
				else
				{
					/* Do nothing */
				}
			break;
		case WINDOW_AUTO_DOWN:
				if(rub_Period==Ticks_8)
				{
					windowlifter_DOWN();
					rub_Period=CLEAR;
				}
				else
				{
					/* Do nothing */
				}
			break;
		case WINDOW_MANUAL_UP:
				if(rub_Period==Ticks_8)
				{
					rub_Period=CLEAR;
					if(Switch_UP())
					{
						windowlifter_UP();
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
				if(rub_Period==Ticks_8)
				{
					rub_Period=CLEAR;
					if(Switch_DOWN())
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
				if(rub_Period==Ticks_8)
				{
					windowlifter_PINCH();
					rub_Period=CLEAR;
				}
				else
				{
					/* Do nothing */
				}
			break;
		case PINCH_IDLE:
				if(rub_Period>=TICKS_125)
				{
					rub_Period=CLEAR;
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
