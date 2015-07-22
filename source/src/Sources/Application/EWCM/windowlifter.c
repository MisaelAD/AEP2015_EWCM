/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         windowlifter.c
* Instance:         RPL_1
* %version:         1.2
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Wednesday, July 1, 2015
*=============================================================================*/
/* DESCRIPTION : Window Lifter state functions                                */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*	1.1		 |	2/07/2015  |Buttons interface updated	   |Misael AD         */
/*	1.2		 | 13/07/2015  |Functions update for scheduler |Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "windowlifter.h"

#include "LED.h"

/* Functions macros, constants, types and datas		    */
/* ---------------------------------------------------- */
#define CLOSED (T_SBYTE)10			/* WindowPosition fully closed value */
#define OPENED (T_SBYTE)0			/* WindowPosition fully opened value */

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
T_SBYTE  rsw_WindowPosition = CLOSED;		/* Initial window state: CLOSED */
extern T_SBYTE	rsb_WindowState;
/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

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

/* Special types and datas								*/
/* ---------------------------------------------------- */

/* Private functions */
/* ----------------- */

/**************************************************************
 *  Name                 : windowlifter_UP
 *  Description          :	Moves up the window
 *  Parameters           :  Void
 *  Return               :	Void
 *  Critical/explanation :  No
 **************************************************************/
void windowlifter_UP(void)
{
	LED_UP();
	rsw_WindowPosition++;
	if(rsw_WindowPosition >= CLOSED)
	{
		LEDs_Off();
		rsw_WindowPosition = CLOSED;
		rsb_WindowState = WINDOW_IDLE;
	}
	else
	{
		/* Do nothing */
	}
}

/**************************************************************
 *  Name                 : windowlifter_DOWN
 *  Description          :	Moves down the window
 *  Parameters           :  Void
 *  Return               :	Void
 *  Critical/explanation :  No
 **************************************************************/
void windowlifter_DOWN(void)
{
	LED_DOWN();
	rsw_WindowPosition--;
	if(rsw_WindowPosition <= OPENED)
	{
		LEDs_Off();
		rsw_WindowPosition = OPENED;
		rsb_WindowState = WINDOW_IDLE;
	}
	else
	{
		/* Do nothing */
	}
}

/**************************************************************
 *  Name                 : windowlifter_PINCH
 *  Description          :	Moves down the window
 *  Parameters           :  Void
 *  Return               :	Void
 *  Critical/explanation :  No
 **************************************************************/
void windowlifter_PINCH(void)
{
	LED_DOWN();
	rsw_WindowPosition--;
	if(rsw_WindowPosition <= OPENED)
	{
		LEDs_Off();
		rsw_WindowPosition = OPENED;
		rsb_WindowState = PINCH_IDLE;
	}
	else
	{
		/* Do nothing */
	}
}

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
