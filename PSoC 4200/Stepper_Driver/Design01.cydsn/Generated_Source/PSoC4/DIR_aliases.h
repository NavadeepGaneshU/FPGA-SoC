/*******************************************************************************
* File Name: DIR.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DIR_ALIASES_H) /* Pins DIR_ALIASES_H */
#define CY_PINS_DIR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIR_0			(DIR__0__PC)
#define DIR_0_PS		(DIR__0__PS)
#define DIR_0_PC		(DIR__0__PC)
#define DIR_0_DR		(DIR__0__DR)
#define DIR_0_SHIFT	(DIR__0__SHIFT)
#define DIR_0_INTR	((uint16)((uint16)0x0003u << (DIR__0__SHIFT*2u)))

#define DIR_INTR_ALL	 ((uint16)(DIR_0_INTR))


#endif /* End Pins DIR_ALIASES_H */


/* [] END OF FILE */
