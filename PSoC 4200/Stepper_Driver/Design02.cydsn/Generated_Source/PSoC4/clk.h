/*******************************************************************************
* File Name: clk.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_clk_H) /* Pins clk_H */
#define CY_PINS_clk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "clk_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} clk_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   clk_Read(void);
void    clk_Write(uint8 value);
uint8   clk_ReadDataReg(void);
#if defined(clk__PC) || (CY_PSOC4_4200L) 
    void    clk_SetDriveMode(uint8 mode);
#endif
void    clk_SetInterruptMode(uint16 position, uint16 mode);
uint8   clk_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void clk_Sleep(void); 
void clk_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(clk__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define clk_DRIVE_MODE_BITS        (3)
    #define clk_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - clk_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the clk_SetDriveMode() function.
         *  @{
         */
        #define clk_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define clk_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define clk_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define clk_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define clk_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define clk_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define clk_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define clk_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define clk_MASK               clk__MASK
#define clk_SHIFT              clk__SHIFT
#define clk_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in clk_SetInterruptMode() function.
     *  @{
     */
        #define clk_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define clk_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define clk_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define clk_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(clk__SIO)
    #define clk_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(clk__PC) && (CY_PSOC4_4200L)
    #define clk_USBIO_ENABLE               ((uint32)0x80000000u)
    #define clk_USBIO_DISABLE              ((uint32)(~clk_USBIO_ENABLE))
    #define clk_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define clk_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define clk_USBIO_ENTER_SLEEP          ((uint32)((1u << clk_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << clk_USBIO_SUSPEND_DEL_SHIFT)))
    #define clk_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << clk_USBIO_SUSPEND_SHIFT)))
    #define clk_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << clk_USBIO_SUSPEND_DEL_SHIFT)))
    #define clk_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(clk__PC)
    /* Port Configuration */
    #define clk_PC                 (* (reg32 *) clk__PC)
#endif
/* Pin State */
#define clk_PS                     (* (reg32 *) clk__PS)
/* Data Register */
#define clk_DR                     (* (reg32 *) clk__DR)
/* Input Buffer Disable Override */
#define clk_INP_DIS                (* (reg32 *) clk__PC2)

/* Interrupt configuration Registers */
#define clk_INTCFG                 (* (reg32 *) clk__INTCFG)
#define clk_INTSTAT                (* (reg32 *) clk__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define clk_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(clk__SIO)
    #define clk_SIO_REG            (* (reg32 *) clk__SIO)
#endif /* (clk__SIO_CFG) */

/* USBIO registers */
#if !defined(clk__PC) && (CY_PSOC4_4200L)
    #define clk_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define clk_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define clk_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define clk_DRIVE_MODE_SHIFT       (0x00u)
#define clk_DRIVE_MODE_MASK        (0x07u << clk_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins clk_H */


/* [] END OF FILE */
