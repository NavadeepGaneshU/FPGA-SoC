/*******************************************************************************
* File Name: CLK_in.h  
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

#if !defined(CY_PINS_CLK_in_ALIASES_H) /* Pins CLK_in_ALIASES_H */
#define CY_PINS_CLK_in_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CLK_in_0			(CLK_in__0__PC)
#define CLK_in_0_PS		(CLK_in__0__PS)
#define CLK_in_0_PC		(CLK_in__0__PC)
#define CLK_in_0_DR		(CLK_in__0__DR)
#define CLK_in_0_SHIFT	(CLK_in__0__SHIFT)
#define CLK_in_0_INTR	((uint16)((uint16)0x0003u << (CLK_in__0__SHIFT*2u)))

#define CLK_in_INTR_ALL	 ((uint16)(CLK_in_0_INTR))


#endif /* End Pins CLK_in_ALIASES_H */


/* [] END OF FILE */
