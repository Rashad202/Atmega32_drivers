/*
 *<<<<<<<<<<    SPI_program.c    >>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : SPI
 *
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* Include My own Header Files*/
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

/* Include Header Files From MCAL */
#include"../DIO/DIO_Interface.h"

/* Global Pointer to Function */
void (*Global_PF_Vector_12)(u8 *Copy_u8RecivedData) = NULL ;


void SPI_voidMasterInit (void)
{

/*        Master I/O DIO_PIN Mode           */
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);         // MOSI DIO_OUTPUT in Master Mode
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);          // MISO DIO_INPUT  in Master Mode
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);         // CLOK DIO_OUTPUT in Master Mode
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);          // SS Slave Select DIO_INPUT in Master Mode if we have one Slave only


/*          Select Master  Mode         */
    
        SET_BIT(SPCR_REG,SPCR_MSTR);


/*    Select MSB or LSB Send at First   */
   
    #if ( DATA_ORDER == MSB_FIRST )
        CLR_BIT(SPCR_REG,SPCR_DORD);                  // select MSB to be send first
    #elif ( DATA_ORDER == LSB_FIRST )
        SET_BIT(SPCR_REG,SPCR_DORD);                    // select LSB to be send first
    #endif


/*  Select Clock Polarity Raisinr or Falling */
     
    #if ( CLK_POLARITY == RAISING_Leading_Edge )    
        CLR_BIT(SPCR_REG,SPCR_CPOL);                  // Select Raising at Leading edge & Falling at Tralling Edge
    #elif ( CLK_POLARITY == FALLING_Leading_Edge )     
        SET_BIT(SPCR_REG,SPCR_CPOL);                    // Select Falling at Leading edge & Raising at Tralling Edge
    #endif


/*  Select Clock Phase Sample or setup on Leading */
  
    #if ( CLK_PHASE == SAMPLE_Leading_Edge )     
        CLR_BIT(SPCR_REG,SPCR_CPHA);                  // Select Sampling at leadding edge & Setup at Trailling Edge
    #elif ( CLK_PHASE == SETUP_Leading_Edge )    
        SET_BIT(SPCR_REG,SPCR_CPHA);                    // Select Setup at leadding edge & Sampling at Trailling Edge
    #endif


/*            SPI Prescaler Selection            */

    #if(PRESCALER == PRESCALER_DIVISION_BY_4)
        CLR_BIT(SPCR_REG,SPCR_SPR0);
        CLR_BIT(SPCR_REG,SPCR_SPR1);
        CLR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_16)
          SET_BIT(SPCR_REG,SPCR_SPR0);
        CLR_BIT(SPCR_REG,SPCR_SPR1);
        CLR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_64)
        CLR_BIT(SPCR_REG,SPCR_SPR0);
          SET_BIT(SPCR_REG,SPCR_SPR1);
        CLR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_128)
          SET_BIT(SPCR_REG,SPCR_SPR0);
          SET_BIT(SPCR_REG,SPCR_SPR1);
        CLR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_2)
        CLR_BIT(SPCR_REG,SPCR_SPR0);
        CLR_BIT(SPCR_REG,SPCR_SPR1);
          SET_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_8)
          SET_BIT(SPCR_REG,SPCR_SPR0);
        CLR_BIT(SPCR_REG,SPCR_SPR1);
          SET_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_32)
        CLR_BIT(SPCR_REG,SPCR_SPR0);
          SET_BIT(SPCR_REG,SPCR_SPR1);
          SET_BIT(SPSR_REG,SPSR_SPI2X);
    #endif


/*              Enable SPI              */
        
    SET_BIT(SPCR_REG,SPCR_SPE);                     // Enable SPI

}


void SPI_voidSlaveInit (void)
{

/*          Slave I/O DIO_PIN Mode          */
    DIO_voidSetPinDirection (DIO_PORTB,DIO_PIN5,DIO_INPUT);         // MOSI  DIO_INPUT in Slave Mode
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);         // MISO DIO_OUTPUT in Slave Mode
    DIO_voidSetPinDirection (DIO_PORTB,DIO_PIN7,DIO_INPUT);         // CLOK  DIO_INPUT in Slave Mode
    DIO_voidSetPinDirection (DIO_PORTB,DIO_PIN4,DIO_INPUT);         // SS Slave Select DIO_INPUT in Slave Mode
    DIO_voidSetPinValue (DIO_PORTB,DIO_PIN4,DIO_LOW);               // Set LOW on SS Always if we have one Slave

/*          Select Slave  Mode          */
    
    CLR_BIT(SPCR_REG,SPCR_MSTR);

/*    Select MSB or LSB Send at First   */              // Same With Master Configration.   
    #if ( DATA_ORDER == MSB_FIRST )
        CLR_BIT(SPCR_REG,SPCR_DORD);                  // select MSB to be send first
    #elif ( DATA_ORDER == LSB_FIRST )
        SET_BIT(SPCR_REG,SPCR_DORD);                    // select LSB to be send first
    #endif


/*  Select Clock Polarity Raisinr or Falling */         // Same With Master Configration.
     
    #if ( CLK_POLARITY == RAISING_Leading_Edge )    
        CLR_BIT(SPCR_REG,SPCR_CPOL);                  // Select Raising at Leading edge & Falling at Tralling Edge
    #elif ( CLK_POLARITY == FALLING_Leading_Edge )     
        SET_BIT(SPCR_REG,SPCR_CPOL);                    // Select Falling at Leading edge & Raising at Tralling Edge
    #endif


/*  Select Clock Phase Sample or setup on Leading */    // Same With Master Configration.
  
    #if ( CLK_PHASE == SAMPLE_Leading_Edge )     
        CLR_BIT(SPCR_REG,SPCR_CPHA);                  // Select Sampling at leadding edge & Setup at Trailling Edge
    #elif ( CLK_PHASE == SETUP_Leading_Edge )    
        SET_BIT(SPCR_REG,SPCR_CPHA);                    // Select Setup at leadding edge & Sampling at Trailling Edge
    #endif

/*              Enable SPI              */        
    SET_BIT(SPCR_REG,SPCR_SPE);                     // Enable SPI
     
}

u8 SPI_u8TranceiveData (u8 Copy_u8Data)
{
    /* Transmit */
    // set the data to REG
    SPDR_REG = Copy_u8Data ;
    // polling
    while( (GET_BIT(SPSR_REG,SPSR_SPIF)) == 0 );
    // clear the flag
    SET_BIT(SPSR_REG,SPSR_SPIF);

    /* Recieve */
    return SPDR_REG ;

}


void SPI_voidTransmitData (u8 Copy_u8Data)
{
    // set the data to REG
    SPDR_REG = Copy_u8Data ;
    // polling
    while( (GET_BIT(SPSR_REG,SPSR_SPIF)) == 0 );
    // clear the flag
    SET_BIT(SPSR_REG,SPSR_SPIF);
}



u8 SPI_voidRecieveData (void)
{
    return SPDR_REG ;
}


void SPI_voidTranceiveString (u8 *Copy_Au8TransmitString , u8 *Copy_u8RecieveString )
{
    for ( u8 iter=0 ; Copy_Au8TransmitString[iter] != '\0' ; iter++ )
    {
        /* Send Data */
        // set the data to REG
        SPDR_REG = Copy_Au8TransmitString[iter] ;
        // polling
        while( (GET_BIT(SPSR_REG,SPSR_SPIF)) == 0 );
        // clear the flag
        SET_BIT(SPSR_REG,SPSR_SPIF);

        /* Recieve Data */
        Copy_u8RecieveString[iter] = SPDR_REG ;
    }
}

void SPI_u8AsynTranceiveData (u8 Copy_u8Data)
{
 
    SET_BIT(SPCR_REG,SPCR_SPIE);            // Enable SPI Interrupt
    /* Transmit */
    SPDR_REG = Copy_u8Data ;                // set the data to REG
}



void SPI_voidSetCallBack (  void (*Local_PointerToFunction) (u8 *Copy_u8RecivedData) )
{
    Global_PF_Vector_12 = Local_PointerToFunction ;
}



void __vector_12 (void)    __attribute__((signal));
void __vector_12 (void)
{
    u8 Local_u8Data ;
    // Recieve Data
    Local_u8Data = SPDR_REG ;
    u8 *Local_Pu8Data = &Local_u8Data ;
    Global_PF_Vector_12 ( Local_Pu8Data );      // Call Back Application Function
    CLR_BIT(SPCR_REG,SPCR_SPIE);              // Disable SPI Interrupt
}
