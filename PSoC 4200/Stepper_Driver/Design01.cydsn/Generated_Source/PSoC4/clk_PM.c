/*******************************************************************************
* File Name: clk.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "clk.h"

static clk_BACKUP_STRUCT  clk_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: clk_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet clk_SUT.c usage_clk_Sleep_Wakeup
*******************************************************************************/
void clk_Sleep(void)
{
    #if defined(clk__PC)
        clk_backup.pcState = clk_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            clk_backup.usbState = clk_CR1_REG;
            clk_USB_POWER_REG |= clk_USBIO_ENTER_SLEEP;
            clk_CR1_REG &= clk_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(clk__SIO)
        clk_backup.sioState = clk_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        clk_SIO_REG &= (uint32)(~clk_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: clk_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to clk_Sleep() for an example usage.
*******************************************************************************/
void clk_Wakeup(void)
{
    #if defined(clk__PC)
        clk_PC = clk_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            clk_USB_POWER_REG &= clk_USBIO_EXIT_SLEEP_PH1;
            clk_CR1_REG = clk_backup.usbState;
            clk_USB_POWER_REG &= clk_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(clk__SIO)
        clk_SIO_REG = clk_backup.sioState;
    #endif
}


/* [] END OF FILE */
