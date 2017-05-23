#ifndef MCP23008_H_
#define MCP23008_H_

#include <avr/io.h>

void MCP23008_Init(TWI_t *twi, uint8_t address);

uint8_t MCP23008_GetIODIR(uint8_t *iodir);
uint8_t MCP23008_SetIODIR(uint8_t iodir);
uint8_t MCP23008_GetIPOL(uint8_t *ipol);
uint8_t MCP23008_SetIPOL(uint8_t ipol);
uint8_t MCP23008_GetGPINTEN(uint8_t *gpinten);
uint8_t MCP23008_SetGPINTEN(uint8_t gpinten);
uint8_t MCP23008_GetDEFVAL(uint8_t *defval);
uint8_t MCP23008_SetDEFVAL(uint8_t defval);
uint8_t MCP23008_GetINTCON(uint8_t *intcon);
uint8_t MCP23008_SetINTCON(uint8_t intcon);
uint8_t MCP23008_GetIOCON(uint8_t *iocon);
uint8_t MCP23008_SetIOCON(uint8_t iocon);
uint8_t MCP23008_GetGPPU(uint8_t *gppu);
uint8_t MCP23008_SetGPPU(uint8_t gppu);
uint8_t MCP23008_GetINTF(uint8_t *intf);
uint8_t MCP23008_SetINTF(uint8_t intf);
uint8_t MCP23008_GetINTCAP(uint8_t *intcap);
uint8_t MCP23008_GetGPIO(uint8_t *gpio);
uint8_t MCP23008_SetGPIO(uint8_t gpio);
uint8_t MCP23008_GetOLAT(uint8_t *olat);
uint8_t MCP23008_SetOLAT(uint8_t olat);

#endif
