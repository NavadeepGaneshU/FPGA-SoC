/*******************************************************************************
* File Name: clock.h  
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

#if !defined(CY_PINS_clock_H) /* Pins clock_H */
#define CY_PINS_clock_H

#include "cytypes.h"
#include "cyfitter.h"
#include "clock_aliases.h"


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
} clock_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   clock_Read(void);
void    clock_Write(uint8 value);
uint8   clock_ReadDataReg(void);
#if defined(clock__PC) || (CY_PSOC4_4200L) 
    void    clock_SetDriveMode(uint8 mode);
#endif
void    clock_SetInterruptMode(uint16 position, uint16 mode);
uint8   clock_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void clock_Sleep(void); 
void clock_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(clock__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define clock_DRIVE_MODE_BITS        (3)
    #define clock_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - clock_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the clock_SetDriveMode() function.
         *  @{
         */
        #define clock_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define clock_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define clock_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define clock_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define clock_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define clock_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define clock_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define clock_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define clock_MASK               clock__MASK
#define clock_SHIFT              clock__SHIFT
#define clock_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in clock_SetInterruptMode() function.
     *  @{
     */
        #define clock_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define clock_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define clock_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define clock_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(clock__SIO)
    #define clock_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(clock__PC) && (CY_PSOC4_4200L)
    #define clock_USBIO_ENABLE               ((uint32)0x80000000u)
    #define clock_USBIO_DISABLE              ((uint32)(~clock_USBIO_ENABLE))
    #define clock_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define clock_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define clock_USBIO_ENTER_SLEEP          ((uint32)((1u << clock_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << clock_USBIO_SUSPEND_DEL_SHIFT)))
    #define clock_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << clock_USBIO_SUSPEND_SHIFT)))
    #define clock_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << clock_USBIO_SUSPEND_DEL_SHIFT)))
    #define clock_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(clock__PC)
    /* Port Configuration */
    #define clock_PC                 (* (reg32 *) clock__PC)
#endif
/* Pin State */
#define clock_PS                     (* (reg32 *) clock__PS)
/* Data Register */
#define clock_DR                     (* (reg32 *) clock__DR)
/* Input Buffer Disable Override */
#define clock_INP_DIS                (* (reg32 *) clock__PC2)

/* Interrupt configuration Registers */
#define clock_INTCFG                 (* (reg32 *) clock__INTCFG)
#define clock_INTSTAT                (* (reg32 *) clock__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define clock_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(clock__SIO)
    #define clock_SIO_REG            (* (reg32 *) clock__SIO)
#endif /* (clock__SIO_CFG) */

/* USBIO registers */
#if !defined(clock__PC) && (CY_PSOC4_4200L)
    #define clock_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define clock_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define clock_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define clock_DRIVE_MODE_SHIFT       (0x00u)
#define clock_DRIVE_MODE_MASK        (0x07u << clock_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins clock_H */


/* [] END OF FILE */
