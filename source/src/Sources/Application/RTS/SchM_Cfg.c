/*============================================================================*/
/*                        Continental AEP 2015                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         scheduler_Cfg.c
* Instance:         RPL_1
* %version:         1.2
* %created_by:      Misael Alvarez Domínguez
* %date_created:    Monday, July 13, 2015
*=============================================================================*/
/* DESCRIPTION : C source scheduler_Cfg file                                  */
/*============================================================================*/
/* FUNCTION COMMENT : This file provides the task configuration table		  */
/*                                                   						  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/*  1.1      | 13/07/2015  |File added to complete 		   | Misael AD        */
/*        	 |   		   |scheduler structure 		   |  				  */
/*  1.2      | 16/07/2015  |Scheduler config. constants    | Misael AD        */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Cfg.h"
#include "SchM_Tasks.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
//void SchM_Cfg_GlobalPtr(void);
/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */
const SchTaskDescriptorType SchTaskDescConfig[] = 
{
	  /* Offset / Mask / Task ID / Function Ptr */
	{	0,	MASK_3P125MS,	TASK_3P125MS,	&SchM_Task3p125ms	},
	{	1, 	MASK_6P25MS,  	TASK_6P25MS, 	&SchM_Task6p25ms	},
	{	2, 	MASK_12P5MS,  	TASK_12P5MS, 	&SchM_Task12p25ms	},
	{	3, 	MASK_25MS, 	 	TASK_25MS,		&SchM_Task25ms		},
	{	5, 	MASK_50MS, 	 	TASK_50MS, 		&SchM_Task50ms		},
	{	6, 	MASK_100MS, 	TASK_100MS, 	&SchM_Task100ms		}
};

const SchConfigType SchConfig = 
{
	(sizeof(SchTaskDescConfig)/sizeof(SchTaskDescConfig[0])),
	SchTaskDescConfig
};

/*SchTaskDescriptorType *SchPtr[(sizeof(SchTaskDescConfig)/sizeof(SchTaskDescConfig[0]))];

void SchM_Cfg_GlobalPtr(void)
{
	T_UBYTE Pindex;
	for(Pindex=0; Pindex<SchConfig.SchNumberOfTasks; Pindex++)
	{
		SchPtr[Pindex] = (SchTaskDescriptorType*)&SchTaskDescConfig[Pindex];
	}
}*/

const SchTaskDescriptorType *SchPtr[] = 
{
	&SchTaskDescConfig[0],
	&SchTaskDescConfig[1],
	&SchTaskDescConfig[2],
	&SchTaskDescConfig[3],
	&SchTaskDescConfig[4],
	&SchTaskDescConfig[5]
};

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
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
