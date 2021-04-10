/*******************************************************************************
* File Name: clock.h  
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

#if !defined(CY_PINS_clock_ALIASES_H) /* Pins clock_ALIASES_H */
#define CY_PINS_clock_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define clock_0			(clock__0__PC)
#define clock_0_PS		(clock__0__PS)
#define clock_0_PC		(clock__0__PC)
#define clock_0_DR		(clock__0__DR)
#define clock_0_SHIFT	(clock__0__SHIFT)
#define clock_0_INTR	((uint16)((uint16)0x0003u << (clock__0__SHIFT*2u)))

#define clock_INTR_ALL	 ((uint16)(clock_0_INTR))


#endif /* End Pins clock_ALIASES_H */


/* [] END OF FILE */
