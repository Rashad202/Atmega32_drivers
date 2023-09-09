/*
 *<<<<<<<<<<<    DIO_Program.c  >>>>>>>>>>>>
 *
 *  Author : Rashad
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"



void DIO_voidSetPinDirection (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Direction )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD || Copy_u8PinNumber > DIO_PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Direction)
        {
            case INPUT :    switch(Copy_u8PortNumber)
                            {
                                case DIO_PORTA :    CLR_BIT( DDRA_REG ,Copy_u8PinNumber );    break;       
                                case DIO_PORTB :    CLR_BIT( DDRB_REG ,Copy_u8PinNumber );    break;
                                case DIO_PORTC :    CLR_BIT( DDRC_REG ,Copy_u8PinNumber );    break;
                                case DIO_PORTD :    CLR_BIT( DDRD_REG ,Copy_u8PinNumber );    break;
                                default    :                                                break;
                            }
                            break;
            case OUTPUT :   switch(Copy_u8PortNumber)
                            {
                                case DIO_PORTA :    SET_BIT( DDRA_REG ,Copy_u8PinNumber );      break;
                                case DIO_PORTB :    SET_BIT( DDRB_REG ,Copy_u8PinNumber );      break;
                                case DIO_PORTC :    SET_BIT( DDRC_REG ,Copy_u8PinNumber );      break;
                                case DIO_PORTD :    SET_BIT( DDRD_REG ,Copy_u8PinNumber );      break;
                                default    :                                                break; 
                            }
                            break;
            default :       break;
                            
        }
    }
}

void DIO_voidSetDIO_PORTDirection (u8 Copy_u8PortNumber, u8 Copy_u8Direction )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Direction)
        {
            case INPUT :    switch(Copy_u8PortNumber)
                            {
                                case DIO_PORTA :    DDRA_REG = 0x00 ;   break;
                                case DIO_PORTB :    DDRB_REG = 0x00 ;   break;
                                case DIO_PORTC :    DDRC_REG = 0x00 ;   break;
                                case DIO_PORTD :    DDRD_REG = 0x00 ;   break;
                                default    :                        break;
                            }
                            break;
            case OUTPUT :   switch(Copy_u8PortNumber)
                            {
                                case DIO_PORTA :    DDRA_REG = 0xff ;   break;
                                case DIO_PORTB :    DDRB_REG = 0xff ;   break;
                                case DIO_PORTC :    DDRC_REG = 0xff ;   break;
                                case DIO_PORTD :    DDRD_REG = 0xff ;   break;
                                default    :                        break;
                            }
                            break;
            default :       break;
                            
        }
    }
}


void DIO_voidSetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Value )
{
        /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Value)
        {
            case LOW :    switch(Copy_u8PortNumber)
                            {
                                case DIO_PORTA :    CLR_BIT( PORTA_REG ,Copy_u8PinNumber );   break;
                                case DIO_PORTB :    CLR_BIT( PORTB_REG ,Copy_u8PinNumber );   break;
                                case DIO_PORTC :    CLR_BIT( PORTC_REG ,Copy_u8PinNumber );   break;
                                case DIO_PORTD :    CLR_BIT( PORTD_REG ,Copy_u8PinNumber );   break;
                                default    :                                                break; 
                            }
                            break;
            case HIGH :   switch(Copy_u8PortNumber)
                            {
                                case DIO_PORTA :    SET_BIT( PORTA_REG ,Copy_u8PinNumber );     break;
                                case DIO_PORTB :    SET_BIT( PORTB_REG ,Copy_u8PinNumber );     break;
                                case DIO_PORTC :    SET_BIT( PORTC_REG ,Copy_u8PinNumber );     break;
                                case DIO_PORTD :    SET_BIT( PORTD_REG ,Copy_u8PinNumber );     break;
                                default    :                                                break; 
                            }
                            break;
            default :       break;
                            
        }
    }
}

void DIO_voidSetPortValue (u8 Copy_u8PortNumber, u8 Copy_u8Value )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case DIO_PORTA: PORTA_REG = Copy_u8Value;
                        break;
    
            case DIO_PORTB: PORTB_REG = Copy_u8Value;
                        break;
    
            case DIO_PORTC: PORTC_REG = Copy_u8Value;
                        break;
    
            case DIO_PORTD: PORTD_REG = Copy_u8Value;
                        break;
            default:
                        break;
        }
    }
}

u8 DIO_u8GetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    u8 Local_u8Variable;
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case DIO_PORTA :    Local_u8Variable = GET_BIT( PINA_REG ,Copy_u8PinNumber );   break;   
            case DIO_PORTB :    Local_u8Variable = GET_BIT( PINB_REG ,Copy_u8PinNumber );   break;
            case DIO_PORTC :    Local_u8Variable = GET_BIT( PINC_REG ,Copy_u8PinNumber );   break;
            case DIO_PORTD :    Local_u8Variable = GET_BIT( PIND_REG ,Copy_u8PinNumber );   break;
            default :                                                                   break;
        }
    }
    return Local_u8Variable ;
}


u8 DIO_u8GetPortValue (u8 Copy_u8PortNumber )
{
    u8 Local_u8Variable;
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case DIO_PORTA :    Local_u8Variable = PINA_REG ;   break;  
            case DIO_PORTB :    Local_u8Variable = PINB_REG ;   break;
            case DIO_PORTC :    Local_u8Variable = PINC_REG ;   break;
            case DIO_PORTD :    Local_u8Variable = PIND_REG ;   break;
            default    :                                    break;
        }
    }
    return Local_u8Variable ;
}


void DIO_voidTogglePinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case DIO_PORTA :    TOG_BIT( PORTA_REG, Copy_u8PinNumber );     break;
            case DIO_PORTB :    TOG_BIT( PORTB_REG, Copy_u8PinNumber );     break;
            case DIO_PORTC :    TOG_BIT( PORTC_REG, Copy_u8PinNumber );     break;
            case DIO_PORTD :    TOG_BIT( PORTD_REG, Copy_u8PinNumber );     break;
            default :                                                      break;
        }
    }
}


void DIO_voidTogglePortValue (u8 Copy_u8PortNumber )
{
        /* i/p validation */
    if ( Copy_u8PortNumber > DIO_PORTD )
    {
        // Do Nothing
    }
    else 
    {
        switch(Copy_u8PortNumber)
        {
            case DIO_PORTA :    PORTA_REG ^= 0xff ;     break;           
            case DIO_PORTB :    PORTB_REG ^= 0xff ;     break;          
            case DIO_PORTC :    PORTC_REG ^= 0xff ;     break; 
            case DIO_PORTD :    PORTD_REG ^= 0xff ;     break; 
            default    :                            break;
        }
    }
}
