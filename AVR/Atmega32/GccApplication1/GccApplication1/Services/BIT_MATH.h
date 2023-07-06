/*
 * BIT_MATH.h
 *
 * Created: 6/10/2023 2:35:38 AM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) = (VAR)|(1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) = (VAR) & ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) = (VAR) ^ (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#define CONC_BIT(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0) CONC_HELP(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)
#define CONC_HELP(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0) 0b##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0


#endif /* BIT_MATH_H_ */