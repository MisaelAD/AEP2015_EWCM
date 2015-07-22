/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        windowlifter.h
* Instance:         RPL_1
* %version:         1.1
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Wednesday, July 2, 2015
*=============================================================================*/
/* DESCRIPTION : Header file window lifter driver                             */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      |  2/07/2015 | Creation of header file       | Misael AD     	  */
/*  1.1      | 13/07/2015 | No more use of task struct    | Misael AD     	  */
/*============================================================================*/

#ifndef _WINDOWLIFTER_H        /*prevent duplicated includes*/
#define _WINDOWLIFTER_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */
void windowlifter_UP(void);
void windowlifter_DOWN(void);
void windowlifter_PINCH(void);

/* Functions prototypes */


/* Functions macros */


/* Exported defines */
#define WINDOW_IDLE			0
#define WINDOW_AUTO_UP 		1
#define WINDOW_AUTO_DOWN 	2
#define WINDOW_MANUAL_UP 	3
#define WINDOW_MANUAL_DOWN 	4
#define PINCH_OPEN			5
#define PINCH_IDLE			6

#endif

