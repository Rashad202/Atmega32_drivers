/*
 *   			--- LCD_Interface.h----
 *
 *  Author : Rashad
 *  Layer  : HAL
 *  SWC    : LCD
 *
 */
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LINE_1       0
#define LINE_2       1

#define    PATTERN_0        0b01000000    // address of First Byte at Sequence 0 at CGRAM            
#define    PATTERN_1        0b01001000    // address of First Byte at Sequence 1 at CGRAM            
#define    PATTERN_2        0b01010000    // address of First Byte at Sequence 2 at CGRAM
#define    PATTERN_3        0b01011000    // address of First Byte at Sequence 3 at CGRAM
#define    PATTERN_4        0b01100000    // address of First Byte at Sequence 4 at CGRAM
#define    PATTERN_5        0b01101000    // address of First Byte at Sequence 5 at CGRAM
#define    PATTERN_6        0b01110000    // address of First Byte at Sequence 6 at CGRAM
#define    PATTERN_7        0b01111000    // address of First Byte at Sequence 7 at CGRAM


void LCD_voidInit (void);


void LCD_voidWriteCommand ( u8 Copy_u8Command );


void LCD_voidWriteChar ( u8 Copy_u8Char );


void LCD_voidWriteString (u8 *Copy_u8Arr );


void LCD_voidWrite_u32Number ( u32 Copy_u32Number);


void LCD_voidGoTo_XY ( u8 Copy_u8Line , u8 Copy_u8Position );


void LCD_voidDrawPattern ( u8 Copy_u8Pattern_Number , u8 *Copy_u8Arr_Pattern );


void LCD_voidWritePattern ( u8 Copy_u8Pattern , u8 Copy_u8Line , u8 Copy_u8Position );


void LCD_voidClearDisplay (void);


void LCD_voidShiftLeft (void);


void LCD_voidShiftRight (void);




#endif
