/**************************************************************************/
/* FILE NAME:                              COPYRIGHT (c) Freescale 2016   */
/* MPC57xx__Interrupt_Init.c                      All Rights Reserved     */
/*                                                                        */
/* DESCRIPTION:                                                           */
/* This is the interrupt controller configuration file.                   */
/*=========================================================================*/
/*                                                                        */
/*========================================================================*/
/* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE               */
/* ---   -----------    ----------    ---------------------               */
/* 0.1    R. Moran       10/12/2008    Initial Version                    */
/* 1.1    K. Zemskov     24/02/2016    GHS support                        */
/**************************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "compiler_api.h"

#define GetCoreID() ((uint16_t) MFSPR(286))

/* Hardware vector mode bit */
#define INTC_BCR_HVEN(coreId)   ( (uint32_t) (0x1UL << ((coreId) << 3UL)) )  /* coreId - hw coreId (value that is read from PIR) */

/*========================================================================*/
/*                      GLOBAL VARIABLES                                  */
/*========================================================================*/
extern const uint32_t IntcIsrVectorTable[];

/*========================================================================*/
/*                      EXTERNAL PROTOTYPES                               */
/*========================================================================*/
extern void VTABLE (void);

/*========================================================================*/
/*                          FUNCTIONS                                     */
/*========================================================================*/
/**************************************************************************/
/* FUNCTION     : SetIVPR                                                 */
/* PURPOSE      : Initialise Core IVPR                                    */
/**************************************************************************/
void SetIVPR (register unsigned int x)
{
    MTSPR(63, x);
}

/**************************************************************************/
/* FUNCTION     : InitINTC                                                */
/* PURPOSE      : This function intializes the INTC for software vector   */
/*                mode.                                                   */
/**************************************************************************/
void InitINTC(void) 
{
    uint16_t coreId = GetCoreID ();

    /* Choose software (HVEN=0) or hardware (HVEN=1) vector mode */
    INTC.BCR.R  &= ~(INTC_BCR_HVEN( coreId ));     /* Software vector mode   */
    /* Set INTC ISR vector table base addr. */
    INTC.IACKR[coreId].R = (uint32_t) &IntcIsrVectorTable[0];
}


/**************************************************************************/
/* FUNCTION     : enableIrq                                               */
/* PURPOSE      : This function sets INTC's current priority to 0.        */
/*                External interrupts to the core are enabled.            */
/**************************************************************************/
void enableIrq(void) 
{
    uint16_t coreId = GetCoreID ();

    /* Ensure INTC's current priority is 0 */
    /* Ensure INTC's current priority is 0 */
    INTC.CPR[coreId].R = 0U;
    /* Enable external interrupts */
    PPCASM (" wrteei 1 ");
}


/**************************************************************************/
/* FUNCTION     : xcptn_xmpl                                              */
/* PURPOSE      : This function sets up the necessary functions to raise  */
/*                and handle a Interrupt in software vector mode          */
/**************************************************************************/
void xcptn_xmpl(void) 
{
    /* Initialise Core IVPR */
    SetIVPR ((unsigned int) &VTABLE);
    /* Initialize INTC for SW vector mode */
    InitINTC();               
    /* Enable interrupts */
    enableIrq();
}
