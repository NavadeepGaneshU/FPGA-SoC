/*******************************************************************************
* File Name: ck.h  
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

#if !defined(CY_PINS_ck_H) /* Pins ck_H */
#define CY_PINS_ck_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ck_aliases.h"


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
} ck_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ck_Read(void);
void    ck_Write(uint8 value);
uint8   ck_ReadDataReg(void);
#if defined(ck__PC) || (CY_PSOC4_4200L) 
    void    ck_SetDriveMode(uint8 mode);
#endif
void    ck_SetInterruptMode(uint16 position, uint16 mode);
uint8   ck_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ck_Sleep(void); 
void ck_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ck__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ck_DRIVE_MODE_BITS        (3)
    #define ck_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ck_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ck_SetDriveMode() function.
         *  @{
         */
        #define ck_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ck_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ck_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ck_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ck_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ck_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ck_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ck_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ck_MASK               ck__MASK
#define ck_SHIFT              ck__SHIFT
#define ck_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ck_SetInterruptMode() function.
     *  @{
     */
        #define ck_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ck_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ck_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ck_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ck__SIO)
    #define ck_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ck__PC) && (CY_PSOC4_4200L)
    #define ck_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ck_USBIO_DISABLE              ((uint32)(~ck_USBIO_ENABLE))
    #define ck_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ck_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ck_USBIO_ENTER_SLEEP          ((uint32)((1u << ck_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ck_USBIO_SUSPEND_DEL_SHIFT)))
    #define ck_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ck_USBIO_SUSPEND_SHIFT)))
    #define ck_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ck_USBIO_SUSPEND_DEL_SHIFT)))
    #define ck_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ck__PC)
    /* Port Configuration */
    #define ck_PC                 (* (reg32 *) ck__PC)
#endif
/* Pin State */
#define ck_PS                     (* (reg32 *) ck__PS)
/* Data Register */
#define ck_DR                     (* (reg32 *) ck__DR)
/* Input Buffer Disable Override */
#define ck_INP_DIS                (* (reg32 *) ck__PC2)

/* Interrupt configuration Registers */
#define ck_INTCFG                 (* (reg32 *) ck__INTCFG)
#define ck_INTSTAT                (* (reg32 *) ck__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ck_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ck__SIO)
    #define ck_SIO_REG            (* (reg32 *) ck__SIO)
#endif /* (ck__SIO_CFG) */

/* USBIO registers */
#if !defined(ck__PC) && (CY_PSOC4_4200L)
    #define ck_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ck_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ck_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ck_DRIVE_MODE_SHIFT       (0x00u)
#define ck_DRIVE_MODE_MASK        (0x07u << ck_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ck_H */


/* [] END OF FILE */
