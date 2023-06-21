/*
 * LCD_Interface.h
 *
 * Created: 6/11/2023 9:11:29 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*Commands*/

#define LCD_CLR                   0x01

#define LCD_RETURN                0x02

#define LCD_CURSER_INCREMENT      0x06
#define LCD_CURSER_DECREMENT      0x04

#define LCD_DISPLAY_ON            0x0C
#define LCD_DISPLAY_ON_C_BLINK    0x0E

#define LCD_DIS_SHIFT_RIGHT       0x1C
#define LCD_DIS_SHIFT_LEFT        0x18
#define LCD_CURS_SHIF_RIGHT       0x10
#define LCD_CURS_SHIF_LEFT		  0x14

#define LCD_SET_4MODE             0x28
#define LCD_SET_8MODE             0x38

#define LCD_SET_CURSER_L1         0x80
#define LCD_SET_CURSER_L2         0xC0





void LCD_Init(void);
void LCD_SendCommand(u8 Command_Copy);
void LCD_WriteData(u8 Data_Copy);
void LCD_WriteString(u8 * String);
void LCD_GOTO(u8 x, u8 y);
void LCD_SaveCustomChar(u8 character[],u8 Location);

#endif /* LCD_INTERFACE_H_ */