/*
 * KEYPAD_Config.h
 *
 * Created: 6/12/2023 9:20:52 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_



#define ROW1_PIN        PINC5
#define ROW2_PIN        PINC4
#define ROW3_PIN        PINC3
#define ROW4_PIN        PINC2

#define COL1_PIN        PIND7
#define COL2_PIN        PIND6
#define COL3_PIN        PIND5
#define COL4_PIN        PIND3


u8 KEY_GIT[4][4] = {
	{0,7,14,21},
	{28,35,42,49},
	{56,63,70,77},
	{84,91,96,100}
};



#endif /* KEYPAD_CONFIG_H_ */