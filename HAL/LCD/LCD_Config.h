/*
 *   			--- LCD_Config.h----
 *
 *  Author : Rashad
 *  Layer  : HAL
 *  SWC    : LCD
 *
 */
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* LCD Hardware Configration with atmega PORTS & PINS */

#define LCD_CONTROL_PORT         DIO_PORTD
#define LCD_DATA_PORT            DIO_PORTC

#define RS_PIN                   DIO_PIN5
#define RW_PIN                   DIO_PIN6
#define E_PIN                    DIO_PIN7


#endif
