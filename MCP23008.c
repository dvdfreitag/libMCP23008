#include <avr/io.h>

#include "TWI.h"

#define MCP23008_OPCODE		0x40

#define IODIR				0x00
#define IPOL				0x01
#define GPINTEN				0x02
#define DEFVAL				0x03
#define INTCON				0x04
#define IOCON				0x05
#define GPPU				0x06
#define INTF				0x07
#define INTCAP				0x08
#define GPIO				0x09
#define OLAT				0x0A

TWI_t *TWI;
uint8_t Address;

uint8_t mcp23008_value_write(uint8_t addr, uint8_t value)
{	// Sanity check
	if (!TWI) return TWI_NACK;
	
	TWI_Start(TWI);

	if (TWI_WriteByte(MCP23008_OPCODE | Address) != TWI_ACK) goto error;
	if (TWI_WriteByte(addr) != TWI_ACK) goto error;
	if (TWI_WriteByte(value) != TWI_ACK) goto error;

	TWI_Stop(TWI_ACK);
	return TWI_ACK;

error:
	// Error occurred, terminate communication
	TWI_Stop(TWI_NACK);
	return TWI_NACK;
}

uint8_t mcp23008_value_read(uint8_t addr, uint8_t *value)
{	// Sanity check
	if (!TWI || !value) return TWI_NACK;

	TWI_Start(TWI);

	if (TWI_WriteByte(MCP23008_OPCODE | Address) != TWI_ACK) goto error;
	if (TWI_WriteByte(addr) != TWI_ACK) goto error;

	TWI_Restart();

	if (TWI_WriteByte(MCP23008_OPCODE | Address | 0x01) != TWI_ACK) goto error;
	*value = TWI_ReadByte(TWI_NACK);

	TWI_Stop(TWI_NACK);
	return TWI_ACK;

error:
	// There was an error, NACK the slave and terminate communication
	TWI_Stop(TWI_NACK);
	return TWI_NACK;
}

void MCP23008_Init(TWI_t *twi, uint8_t address)
{
	TWI = twi;
	Address = (address & 0x07) << 1;
}

uint8_t MCP23008_GetIODIR(uint8_t *iodir)
{
	return mcp23008_value_read(IODIR, iodir);
}

uint8_t MCP23008_SetIODIR(uint8_t iodir)
{
	return mcp23008_value_write(IODIR, iodir);
}

uint8_t MCP23008_GetIPOL(uint8_t *ipol)
{
	return mcp23008_value_read(IPOL, ipol);
}

uint8_t MCP23008_SetIPOL(uint8_t ipol)
{
	return mcp23008_value_write(IPOL, ipol);
}

uint8_t MCP23008_GetGPINTEN(uint8_t *gpinten)
{
	return mcp23008_value_read(GPINTEN, gpinten);
}

uint8_t MCP23008_SetGPINTEN(uint8_t gpinten)
{
	return mcp23008_value_write(GPINTEN, gpinten);
}

uint8_t MCP23008_GetDEFVAL(uint8_t *defval)
{
	return mcp23008_value_read(DEFVAL, defval);
}

uint8_t MCP23008_SetDEFVAL(uint8_t defval)
{
	return mcp23008_value_write(DEFVAL, defval);
}

uint8_t MCP23008_GetINTCON(uint8_t *intcon)
{
	return mcp23008_value_read(INTCON, intcon);
}

uint8_t MCP23008_SetINTCON(uint8_t intcon)
{
	return mcp23008_value_write(INTCON, intcon);
}

uint8_t MCP23008_GetIOCON(uint8_t *iocon)
{
	return mcp23008_value_read(IOCON, iocon);
}

uint8_t MCP23008_SetIOCON(uint8_t iocon)
{
	return mcp23008_value_write(IOCON, iocon);
}

uint8_t MCP23008_GetGPPU(uint8_t *gppu)
{
	return mcp23008_value_read(GPPU, gppu);
}

uint8_t MCP23008_SetGPPU(uint8_t gppu)
{
	return mcp23008_value_write(GPPU, gppu);
}

uint8_t MCP23008_GetINTF(uint8_t *intf)
{
	return mcp23008_value_read(INTF, intf);
}

uint8_t MCP23008_SetINTF(uint8_t intf)
{
	return mcp23008_value_write(INTF, intf);
}

uint8_t MCP23008_GetINTCAP(uint8_t *intcap)
{
	return mcp23008_value_read(INTCAP, intcap);
}

uint8_t MCP23008_GetGPIO(uint8_t *gpio)
{
	return mcp23008_value_read(GPIO, gpio);
}

uint8_t MCP23008_SetGPIO(uint8_t gpio)
{
	return mcp23008_value_write(GPIO, gpio);
}

uint8_t MCP23008_GetOLAT(uint8_t *olat)
{
	return mcp23008_value_read(OLAT, olat);
}

uint8_t MCP23008_SetOLAT(uint8_t olat)
{
	return mcp23008_value_write(OLAT, olat);
}
