/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler_Tasks.c
* Instance:         RPL_1
* %version:         1.2
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
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Tasks.h"
#include "LED.h"
#include "SchM_Types.h"

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
 *  Name                 : scheduler_5ms
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void scheduler_5ms(void)	/* Each 5ms */
{
	
}

/**************************************************************
 *  Name                 : scheduler_10ms
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void scheduler_10ms(void)	/* Each 10ms */
{
	
}

/**************************************************************
 *  Name                 : scheduler_50ms
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void scheduler_50ms(void)	/* Each 50ms */
{
	
}

/**************************************************************
 *  Name                 : scheduler_100ms
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void scheduler_100ms(void)	/* Each 100ms */
{
	LED_T(LED4);
}


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	SchM_Task3p125ms
 *  Description          :	Task activated every 3.125ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task3p125ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task6p25ms
 *  Description          :	Task activated every 6.25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task6p25ms(void)
{
	
}

/**************************************************************
 *  Name                 :	SchM_Task12p25ms
 *  Description          :	Task activated every 12.25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task12p25ms(void)
{
	LED_T(LED1);
}

/**************************************************************
 *  Name                 :	SchM_Task25ms
 *  Description          :	Task activated every 25ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task25ms(void)
{
	LED_T(LED2);
}

/**************************************************************
 *  Name                 :	SchM_Task50ms
 *  Description          :	Task activated every 50ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task50ms(void)
{
	LED_T(LED3);
}

/**************************************************************
 *  Name                 :	SchM_Task100ms
 *  Description          :	Task activated every 100ms
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Task100ms(void)
{
	LED_T(LED4);
}
