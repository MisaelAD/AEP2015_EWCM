/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         switch.c
* Instance:         RPL_1
* %version:         1.1
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the external switches reading       */
/*                    functions                                               */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |C file template implementation | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "switch.h"
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
/* Push buttons pins */
#define S1 SIU.GPDI[64].R
#define S2 SIU.GPDI[65].R
#define S3 SIU.GPDI[66].R
#define S4 SIU.GPDI[67].R

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
 *  Name                 :	Switch_UP
 *  Description          :	Reads the switch UP input
 *  Parameters           :	None
 *  Return               :	Inverted value from On-board S3
 *  Critical/explanation :	No
 **************************************************************/
 uint8_t Switch_UP(void)
{
	return !S3;
}

/**************************************************************
 *  Name                 :	Switch_DOWN
 *  Description          :	Reads the switch DOWN input
 *  Parameters           :	None
 *  Return               :	Inverted value from On-board S4
 *  Critical/explanation :	No
 **************************************************************/
uint8_t Switch_DOWN(void)
{
	return !S4;
}

/**************************************************************
 *  Name                 :	Switch_Pinch
 *  Description          :	Reads the switch PINCH input
 *  Parameters           :	None
 *  Return               :	Inverted value from On-board S1
 *  Critical/explanation :	No
 **************************************************************/
uint8_t Switch_Pinch(void)
{
	return !S1;
}

/**************************************************************
 *  Name                 :	Switch_Combination
 *  Description          :	Reads UP & DOWN input
 *  Parameters           :	None
 *  Return               :	AND of UP input and DOWN input
 *  Critical/explanation :	No
 **************************************************************/
uint8_t Switch_Combination(void)
{
	uint8_t SC;
	SC = (Switch_UP()) & (Switch_DOWN());
	return SC;
}
