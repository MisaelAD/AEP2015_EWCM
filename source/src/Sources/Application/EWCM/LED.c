/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         LED.c
* Instance:         RPL_1
* %version:         1.2
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the external LED control functions  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |C file template implementation | Misael AD        */
/*  1.2      | 22/07/2015  |LED_[UP & DOWN] function update| Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LED.h"
#include "MPC5606B.h"

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


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

#define LEDB SIU.GPDO[10].R
#define LEDG SIU.GPDO[11].R


#define ON	1
#define OFF 0
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
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	LED_WindowLifter
 *  Description          :	Indicates window position using a
 *							10 LED bar.
 *  Parameters           :  [Input: position]
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LED_WindowLifter(T_SBYTE position)
{
	T_SBYTE p;				 /*Pointer to control the LED bar position(p)*/
	for(p=0; p<position; p++)	 /*Turn ON LEDs from 0 to actual position*/
	{
		SIU.GPDO[p].R = ON;
	}
	for(p=p; p<10; p++)		/*Turn OFF LEDs from position to fully closed*/
	{
		SIU.GPDO[p].R = OFF;
	}
}

/**************************************************************
 *  Name                 :	LED_UP
 *  Description          :	Turns on moving UP LED
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LED_UP(void)
{
	LEDB = ON;
	LEDG = OFF;
}

/**************************************************************
 *  Name                 :	LED_DOWN
 *  Description          :	Turns on moving DOWN LED
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LED_DOWN(void)
{
	LEDB = OFF;
	LEDG = ON;
}

/**************************************************************
 *  Name                 :	LEDs_Off
 *  Description          :	Turns off movement indicating LEDS
 *  Parameters           :	None
 *  Return               :
 *  Critical/explanation :	No
 **************************************************************/
void LEDs_Off(void)
{
	LEDB = OFF;
	LEDG = OFF;
}
