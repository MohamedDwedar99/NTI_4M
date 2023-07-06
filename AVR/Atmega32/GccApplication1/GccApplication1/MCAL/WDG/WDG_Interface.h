/*
 * WDG_Interface.h
 *
 * Created: 6/26/2023 3:42:24 PM
 *  Author: es-MohamedHAbdelAziz
 */ 


#ifndef WDG_INTERFACE_H_
#define WDG_INTERFACE_H_


#define WDG_16ms
#define WDG_32ms
#define WDG_65ms
#define WDG_140ms
#define WDG_270ms
#define WDG_550ms
#define WDG_1000ms
#define WDG_2100ms

void WDG_SET(u8 WDG_TIME);
void WDG_Sleep(void);
void WDG_Stop(void);



#endif /* WDG_INTERFACE_H_ */