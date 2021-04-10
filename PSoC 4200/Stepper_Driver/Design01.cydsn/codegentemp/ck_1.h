/*******************************************************************************
* File Name: ck_1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ck_1_H)
#define CY_CLOCK_ck_1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ck_1_StartEx(uint32 alignClkDiv);
#define ck_1_Start() \
    ck_1_StartEx(ck_1__PA_DIV_ID)

#else

void ck_1_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ck_1_Stop(void);

void ck_1_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ck_1_GetDividerRegister(void);
uint8  ck_1_GetFractionalDividerRegister(void);

#define ck_1_Enable()                         ck_1_Start()
#define ck_1_Disable()                        ck_1_Stop()
#define ck_1_SetDividerRegister(clkDivider, reset)  \
    ck_1_SetFractionalDividerRegister((clkDivider), 0u)
#define ck_1_SetDivider(clkDivider)           ck_1_SetDividerRegister((clkDivider), 1u)
#define ck_1_SetDividerValue(clkDivider)      ck_1_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ck_1_DIV_ID     ck_1__DIV_ID

#define ck_1_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ck_1_CTRL_REG   (*(reg32 *)ck_1__CTRL_REGISTER)
#define ck_1_DIV_REG    (*(reg32 *)ck_1__DIV_REGISTER)

#define ck_1_CMD_DIV_SHIFT          (0u)
#define ck_1_CMD_PA_DIV_SHIFT       (8u)
#define ck_1_CMD_DISABLE_SHIFT      (30u)
#define ck_1_CMD_ENABLE_SHIFT       (31u)

#define ck_1_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ck_1_CMD_DISABLE_SHIFT))
#define ck_1_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ck_1_CMD_ENABLE_SHIFT))

#define ck_1_DIV_FRAC_MASK  (0x000000F8u)
#define ck_1_DIV_FRAC_SHIFT (3u)
#define ck_1_DIV_INT_MASK   (0xFFFFFF00u)
#define ck_1_DIV_INT_SHIFT  (8u)

#else 

#define ck_1_DIV_REG        (*(reg32 *)ck_1__REGISTER)
#define ck_1_ENABLE_REG     ck_1_DIV_REG
#define ck_1_DIV_FRAC_MASK  ck_1__FRAC_MASK
#define ck_1_DIV_FRAC_SHIFT (16u)
#define ck_1_DIV_INT_MASK   ck_1__DIVIDER_MASK
#define ck_1_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ck_1_H) */

/* [] END OF FILE */
