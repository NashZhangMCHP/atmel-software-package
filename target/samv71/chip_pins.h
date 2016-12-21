/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2016, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */
/*                                                                              */

#ifndef _CHIP_PINS_H_
#define _CHIP_PINS_H_

/*----------------------------------------------------------------------------
 *       PIOs Define
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * This pages lists all the pio definitions contained in chip.h.
 * The constants are named using the following convention: PIN_* for a constant
 * which defines a single Pin instance (but may include several PIOs sharing the
 * same controller), and PINS_* for a list of Pin instances.
 */

/* ========== Pio PIN definition for USART0 peripheral ========== */

#define PIN_USART0_RXD { PIO_GROUP_B, PIO_PB0C_RXD0, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_USART0_RTS { PIO_GROUP_B, PIO_PB3C_RTS0, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_USART0_TXD { PIO_GROUP_B, PIO_PB1C_TXD0, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_USART0_CTS { PIO_GROUP_B, PIO_PB2C_CTS0, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_USART0_DTR { PIO_GROUP_D, PIO_PD1D_DTR0, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART0_DSR { PIO_GROUP_D, PIO_PD2D_DSR0, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART0_DCD { PIO_GROUP_D, PIO_PD0D_DCD0, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART0_RI { PIO_GROUP_D, PIO_PD3D_RI0, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART0_SCK { PIO_GROUP_B, PIO_PB13C_SCK0, PIO_PERIPH_C, PIO_DEFAULT }

/** USART0 pins definition (RS232) */
#define PINS_USART0 {\
	PIN_USART0_RXD,\
	PIN_USART0_TXD,\
}

/** USART0 pins definition (RS232 with HW handshaking) */
#define PINS_USART0_HWHS {\
	PIN_USART0_RXD,\
	PIN_USART0_RTS,\
	PIN_USART0_TXD,\
	PIN_USART0_CTS,\
	PIN_USART0_SCK,\
}

/** USART0 pins definition (RS495) */
#define PINS_USART0_RS485 {\
	PIN_USART0_RXD,\
	PIN_USART0_TXD,\
	PIN_USART0_RTS,\
}

/** USART0 pins definition (Modem) */
#define PINS_USART0_MODEM {\
	PIN_USART0_TXD,\
	PIN_USART0_RTS,\
	PIN_USART0_DTR,\
	PIN_USART0_RXD,\
	PIN_USART0_CTS,\
	PIN_USART0_DSR,\
	PIN_USART0_DCD,\
	PIN_USART0_RI,\
}

/* ========== Pio PIN definition for USART1 peripheral ========== */

#define PIN_USART1_RXD { PIO_GROUP_A, PIO_PA21A_RXD1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_RTS { PIO_GROUP_A, PIO_PA24A_RTS1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_TXD { PIO_GROUP_B, PIO_PB4D_TXD1, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART1_CTS { PIO_GROUP_A, PIO_PA25A_CTS1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_DTR { PIO_GROUP_A, PIO_PA27A_DTR1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_DSR { PIO_GROUP_A, PIO_PA28A_DSR1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_DCD { PIO_GROUP_A, PIO_PA26A_DCD1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_RI { PIO_GROUP_A, PIO_PA29A_RI1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_SCK { PIO_GROUP_A, PIO_PA23A_SCK1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_USART1_LCOL { PIO_GROUP_A, PIO_PA3B_LONCOL1, PIO_PERIPH_B, PIO_DEFAULT }

/** USART2 pins definition (RS232) */
#define PINS_USART1 {\
	PIN_USART1_RXD,\
	PIN_USART1_TXD,\
}

/** USART1 pins definition (RS232 with HW handshaking) */
#define PINS_USART1_HWHS {\
	PIN_USART1_RXD,\
	PIN_USART1_RTS,\
	PIN_USART1_TXD,\
	PIN_USART1_CTS,\
	PIN_USART1_SCK,\
}

/** USART1 pins definition (RS485) */
#define PINS_USART1_RS485 {\
	PIN_USART1_RXD,\
	PIN_USART1_TXD,\
	PIN_USART1_RTS,\
}

/** USART1 pins definition (Modem) */
#define PINS_USART1_MODEM {\
	PIN_USART1_TXD,\
	PIN_USART1_RTS,\
	PIN_USART1_DTR,\
	PIN_USART1_RXD,\
	PIN_USART1_CTS,\
	PIN_USART1_DSR,\
	PIN_USART1_DCD,\
	PIN_USART1_RI,\
}

/* ========== Pio PIN definition for USART2 peripheral ========== */

#define PIN_USART2_RXD { PIO_GROUP_D, PIO_PD15B_RXD2, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_USART2_RTS { PIO_GROUP_D, PIO_PD18B_RTS2, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_USART2_TXD { PIO_GROUP_D, PIO_PD16B_TXD2, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_USART2_CTS { PIO_GROUP_D, PIO_PD19B_CTS2, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_USART2_DTR { PIO_GROUP_D, PIO_PD5D_DTR2, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART2_DSR { PIO_GROUP_D, PIO_PD6D_DSR2, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART2_DCD { PIO_GROUP_D, PIO_PD4D_DCD2, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART2_RI { PIO_GROUP_D, PIO_PD7D_RI2, PIO_PERIPH_D, PIO_DEFAULT }
#define PIN_USART2_SCK { PIO_GROUP_D, PIO_PD17_SCK2, PIO_PERIPH_B, PIO_DEFAULT }

/** USART2 pins definition (RS232) */
#define PINS_USART2 {\
	PIN_USART2_RXD,\
	PIN_USART2_TXD,\
}

/** USART2 pins definition (RS232 with HW handshaking) */
#define PINS_USART2_HWHS {\
	PIN_USART2_RXD,\
	PIN_USART2_RTS,\
	PIN_USART2_TXD,\
	PIN_USART2_CTS,\
	PIN_USART2_SCK,\
}

/** USART2 pins definition (RS485) */
#define PINS_USART2_RS485 {\
	PIN_USART2_RXD,\
	PIN_USART2_TXD,\
	PIN_USART2_RTS,\
}

/** USART2 pins definition (Modem) */
#define PINS_USART2_MODEM {\
	PIN_USART2_TXD,\
	PIN_USART2_RTS,\
	PIN_USART2_DTR,\
	PIN_USART2_RXD,\
	PIN_USART2_CTS,\
	PIN_USART2_DSR,\
	PIN_USART2_DCD,\
	PIN_USART2_RI,\
}

/* ========== Pio PIN definition for SPI0 peripheral ========== */

#define PIN_SPI0_SPCK { PIO_GROUP_D, PIO_PD22B_SPI0_SPCK, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_SPI0_MOSI { PIO_GROUP_D, PIO_PD21B_SPI0_MOSI, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_SPI0_MISO { PIO_GROUP_D, PIO_PD20B_SPI0_MISO, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_SPI0_NPCS0 { PIO_GROUP_B, PIO_PB2D_SPI0_NPCS0, PIO_PERIPH_D, PIO_PULLUP }
#define PIN_SPI0_NPCS1 { PIO_GROUP_A, PIO_PA31A_SPI0_NPCS1, PIO_PERIPH_A, PIO_PULLUP }
#define PIN_SPI0_NPCS1_ALT { PIO_GROUP_D, PIO_PD25B_SPI0_NPCS1, PIO_PERIPH_B, PIO_PULLUP }
#define PIN_SPI0_NPCS2 { PIO_GROUP_D, PIO_PD12C_SPI0_NPCS2, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI0_NPCS3 { PIO_GROUP_D, PIO_PD27B_SPI0_NPCS3, PIO_PERIPH_B, PIO_PULLUP }

/** SPI0 pins definition */
#define PINS_SPI0 {\
	PIN_SPI0_SPCK,\
	PIN_SPI0_MOSI,\
	PIN_SPI0_MISO,\
}

/** SPI0 pins definition (NPCS0) */
#define PINS_SPI0_NPCS0 {\
	PIN_SPI0_SPCK,\
	PIN_SPI0_MOSI,\
	PIN_SPI0_MISO,\
	PIN_SPI0_NPCS0,\
}

/** SPI0 pins definition (NPCS1) */
#define PINS_SPI0_NPCS1 {\
	PIN_SPI0_SPCK,\
	PIN_SPI0_MOSI,\
	PIN_SPI0_MISO,\
	PIN_SPI0_NPCS1,\
}

/** SPI0 pins definition (NPCS1, alternate) */
#define PINS_SPI0_NPCS1_ALT {\
	PIN_SPI0_SPCK,\
	PIN_SPI0_MOSI,\
	PIN_SPI0_MISO,\
	PIN_SPI0_NPCS1_ALT,\
}

/** SPI0 pins definition (NPCS2) */
#define PINS_SPI0_NPCS2 {\
	PIN_SPI0_SPCK,\
	PIN_SPI0_MOSI,\
	PIN_SPI0_MISO,\
	PIN_SPI0_NPCS2,\
}

/** SPI0 pins definition (NPCS3) */
#define PINS_SPI0_NPCS3 {\
	PIN_SPI0_SPCK,\
	PIN_SPI0_MOSI,\
	PIN_SPI0_MISO,\
	PIN_SPI0_NPCS3,\
}

/* ========== Pio PIN definition for SPI1 peripheral ========== */

#define PIN_SPI1_SPCK { PIO_GROUP_C, PIO_PC24C_SPI1_SPCK, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SPI1_MOSI { PIO_GROUP_C, PIO_PC27C_SPI1_MOSI, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SPI1_MISO { PIO_GROUP_C, PIO_PC26C_SPI1_MISO, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SPI1_NPCS0 { PIO_GROUP_C, PIO_PC25C_SPI1_NPCS0, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI1_NPCS1 { PIO_GROUP_C, PIO_PC28C_SPI1_NPCS1, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI1_NPCS1_ALT { PIO_GROUP_D, PIO_PD0C_SPI1_NPCS1, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI1_NPCS2 { PIO_GROUP_C, PIO_PC29C_SPI1_NPCS2, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI1_NPCS2_ALT { PIO_GROUP_D, PIO_PD1C_SPI1_NPCS2, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI1_NPCS3 { PIO_GROUP_C, PIO_PC30C_SPI1_NPCS3, PIO_PERIPH_C, PIO_PULLUP }
#define PIN_SPI1_NPCS3_ALT { PIO_GROUP_D, PIO_PD2C_SPI1_NPCS3, PIO_PERIPH_C, PIO_PULLUP }

/** SPI1 pins definition */
#define PINS_SPI1 {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
}

/** SPI1 pins definition (NPCS0) */
#define PINS_SPI1_NPCS0 {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS0,\
}

/** SPI1 pins definition (NPCS1) */
#define PINS_SPI1_NPCS1 {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS1,\
}

/** SPI1 pins definition (NPCS1, alternate) */
#define PINS_SPI1_NPCS1_ALT {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS1_ALT,\
}

/** SPI1 pins definition (NPCS2) */
#define PINS_SPI1_NPCS2 {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS2,\
}

/** SPI1 pins definition (NPCS2, alternate) */
#define PINS_SPI1_NPCS2_ALT {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS2_ALT,\
}

/** SPI1 pins definition (NPCS3) */
#define PINS_SPI1_NPCS3 {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS3,\
}

/** SPI1 pins definition (NPCS3, alternate) */
#define PINS_SPI1_NPCS3_ALT {\
	PIN_SPI1_SPCK,\
	PIN_SPI1_MOSI,\
	PIN_SPI1_MISO,\
	PIN_SPI1_NPCS3_ALT,\
}

/* ========== Pio PIN definition for TWI0 peripheral ========== */

#define PIN_TWI0_TWD { PIO_GROUP_A, PIO_PA3A_TWD0, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_TWI0_TWCK { PIO_GROUP_A, PIO_PA4A_TWCK0, PIO_PERIPH_A, PIO_DEFAULT }

/** TWI0 pins definition */
#define PINS_TWI0 {\
	PIN_TWI0_TWD,\
	PIN_TWI0_TWCK,\
}

/* ========== Pio PIN definition for TWI1 peripheral ========== */

#define PIN_TWI1_TWD { PIO_GROUP_B, PIO_PB4A_TWD1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_TWI1_TWCK { PIO_GROUP_B, PIO_PB5A_TWCK1, PIO_PERIPH_A, PIO_DEFAULT }

/** TWI1 pins definition */
#define PINS_TWI1 {\
	PIN_TWI1_TWD,\
	PIN_TWI1_TWCK,\
}

/* ========== Pio PIN definition for TWI2 peripheral ========== */

#define PIN_TWI2_TWD { PIO_GROUP_D, PIO_PD27C_TWD2, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_TWI2_TWCK { PIO_GROUP_D, PIO_PD28C_TWCK2, PIO_PERIPH_C, PIO_DEFAULT }

/** TWI2 pins definition */
#define PINS_TWI2 {\
	PIN_TWI2_TWD,\
	PIN_TWI2_TWCK,\
}

/* ========== Pio PIN definition for UART0 peripheral ========== */

#define PIN_UART0_URXD { PIO_GROUP_A, PIO_PA9A_URXD0, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_UART0_UTXD { PIO_GROUP_A, PIO_PA10A_UTXD0, PIO_PERIPH_A, PIO_DEFAULT }

/** UART0 pins definition */
#define PINS_UART0 {\
	PIN_UART0_URXD,\
	PIN_UART0_UTXD,\
}

/* ========== Pio PIN definition for UART1 peripheral ========== */

#define PIN_UART1_URXD { PIO_GROUP_A, PIO_PA5C_URXD1, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_UART1_UTXD { PIO_GROUP_A, PIO_PA4C_UTXD1, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_UART1_UTXD_ALT1 { PIO_GROUP_A, PIO_PA6C_UTXD1, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_UART1_UTXD_ALT2 { PIO_GROUP_D, PIO_PD26D_UTXD1, PIO_PERIPH_D, PIO_DEFAULT }

/** UART1 pins definition */
#define PINS_UART1 {\
	PIN_UART1_URXD,\
	PIN_UART1_UTXD,\
}

/** UART1 pins definition (alternate 1) */
#define PINS_UART1_ALT1 {\
	PIN_UART1_URXD,\
	PIN_UART1_UTXD_ALT1,\
}

/** UART1 pins definition (alternate 2) */
#define PINS_UART1_ALT2 {\
	PIN_UART1_URXD,\
	PIN_UART1_UTXD_ALT2,\
}

/* ========== Pio PIN definition for UART2 peripheral ========== */

#define PIN_UART2_URXD { PIO_GROUP_D, PIO_PD25C_URXD2, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_UART2_UTXD { PIO_GROUP_D, PIO_PD26C_UTXD2, PIO_PERIPH_C, PIO_DEFAULT }

/** UART2 pins definition */
#define PINS_UART2 {\
	PIN_UART2_URXD,\
	PIN_UART2_UTXD,\
}

/* ========== Pio PIN definition for UART3 peripheral ========== */

#define PIN_UART3_URXD { PIO_GROUP_D, PIO_PD28A_URXD3, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_UART3_UTXD { PIO_GROUP_D, PIO_PD30A_UTXD3, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_UART3_UTXD_ALT { PIO_GROUP_D, PIO_PD31A_UTXD3, PIO_PERIPH_A, PIO_DEFAULT }

/** UART3 pins definition */
#define PINS_UART3 {\
	PIN_UART3_URXD,\
	PIN_UART3_UTXD,\
}

/** UART3 pins definition (alternate) */
#define PINS_UART3_ALT {\
	PIN_UART3_URXD,\
	PIN_UART3_UTXD_ALT,\
}

/* ========== Pio PIN definition for UART4 peripheral ========== */

#define PIN_UART4_URXD { PIO_GROUP_D, PIO_PD18C_URXD4, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_UART4_UTXD { PIO_GROUP_D, PIO_PD3C_UTXD4, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_UART4_UTXD_ALT { PIO_GROUP_D, PIO_PD19C_UTXD4, PIO_PERIPH_C, PIO_DEFAULT }

/** UART4 pins definition */
#define PINS_UART4 {\
	PIN_UART4_URXD,\
	PIN_UART4_UTXD,\
}

/** UART4 pins definition (alternate) */
#define PINS_UART4_ALT {\
	PIN_UART4_URXD,\
	PIN_UART4_UTXD_ALT,\
}

/* ========== Pio PIN definition for QSPI0 peripheral ========== */

#define PIN_QSPI0_CS { PIO_GROUP_A, PIO_PA11A_QSPI0_CS, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_QSPI0_IO0 { PIO_GROUP_A, PIO_PA13A_QSPI0_IO0, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_QSPI0_IO1 { PIO_GROUP_A, PIO_PA12A_QSPI0_IO1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_QSPI0_IO2 { PIO_GROUP_A, PIO_PA17A_QSPI0_IO2, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_QSPI0_IO3 { PIO_GROUP_D, PIO_PD31A_QSPI0_IO3, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_QSPI0_SCK { PIO_GROUP_A, PIO_PA14A_QSPI0_SCK, PIO_PERIPH_A, PIO_DEFAULT }

/** QSPI0 pins definition */
#define PINS_QSPI0 {\
	PIN_QSPI0_CS,\
	PIN_QSPI0_IO0,\
	PIN_QSPI0_IO1,\
	PIN_QSPI0_IO2,\
	PIN_QSPI0_IO3,\
	PIN_QSPI0_SCK,\
}

/* ========== Pio PIN definition for GMAC0 peripheral ========== */

#define PIN_GMAC0_GTXCK { PIO_GROUP_D, PIO_PD0A_GTXCK, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GTXEN { PIO_GROUP_D, PIO_PD1A_GTXEN, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GTX0 { PIO_GROUP_D, PIO_PD2A_GTX0, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GTX1 { PIO_GROUP_D, PIO_PD3A_GTX1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRXDV { PIO_GROUP_D, PIO_PD4A_GRXDV, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRX0 { PIO_GROUP_D, PIO_PD5A_GRX0, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRX1 { PIO_GROUP_D, PIO_PD6A_GRX1, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRXER { PIO_GROUP_D, PIO_PD7A_GRXER, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GMDC { PIO_GROUP_D, PIO_PD8A_GMDC, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GMDIO { PIO_GROUP_D, PIO_PD9A_GMDIO, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GCRS { PIO_GROUP_D, PIO_PD10A_GCRS, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRX2 { PIO_GROUP_D, PIO_PD11A_GRX2, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRX3 { PIO_GROUP_D, PIO_PD12A_GRX3, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GCOL { PIO_GROUP_D, PIO_PD13A_GCOL, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GRXCK { PIO_GROUP_D, PIO_PD14A_GRXCK, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GTX2 { PIO_GROUP_D, PIO_PD15A_GTX2, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GTX3 { PIO_GROUP_D, PIO_PD16A_GTX3, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_GMAC0_GTXER { PIO_GROUP_D, PIO_PD17A_GTXER, PIO_PERIPH_A, PIO_DEFAULT }

#define PIN_GMAC0_GTSUCOMP { PIO_GROUP_B, PIO_PB1B_GTSUCOMP, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_GMAC0_GTSUCOMP_ALT1 { PIO_GROUP_B, PIO_PB12B_GTSUCOMP, PIO_PERIPH_B, PIO_DEFAULT }
#define PIN_GMAC0_GTSUCOMP_ALT2 { PIO_GROUP_D, PIO_PD11C_GTSUCOMP, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_GMAC0_GTSUCOMP_ALT3 { PIO_GROUP_D, PIO_PD20C_GTSUCOMP, PIO_PERIPH_C, PIO_DEFAULT }

/** GMAC0 pins definition (MII) */
#define PINS_GMAC0_MII {\
	PIN_GMAC0_GTXCK,\
	PIN_GMAC0_GTXEN,\
	PIN_GMAC0_GTX0,\
	PIN_GMAC0_GTX1,\
	PIN_GMAC0_GRXDV,\
	PIN_GMAC0_GRX0,\
	PIN_GMAC0_GRX1,\
	PIN_GMAC0_GRXER,\
	PIN_GMAC0_GMDC,\
	PIN_GMAC0_GMDIO,\
	PIN_GMAC0_GCRS,\
	PIN_GMAC0_GRX2,\
	PIN_GMAC0_GRX3,\
	PIN_GMAC0_GCOL,\
	PIN_GMAC0_GRXCK,\
	PIN_GMAC0_GTX2,\
	PIN_GMAC0_GTX3,\
	PIN_GMAC0_GTXER,\
}

/** GMAC0 pins definition (RMII) */
#define PINS_GMAC0_RMII {\
	PIN_GMAC0_GTXCK,\
	PIN_GMAC0_GTXEN,\
	PIN_GMAC0_GTX0,\
	PIN_GMAC0_GTX1,\
	PIN_GMAC0_GRXDV,\
	PIN_GMAC0_GRX0,\
	PIN_GMAC0_GRX1,\
	PIN_GMAC0_GRXER,\
	PIN_GMAC0_GMDC,\
	PIN_GMAC0_GMDIO,\
}

/* ========== Pio PIN definition for SDRAM peripheral ========== */

#define PIN_SDRAM_SDCK     { PIO_GROUP_D, PIO_PD23C_SDCK, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_SDCKE    { PIO_GROUP_D, PIO_PD14C_SDCKE, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_SDCS     { PIO_GROUP_C, PIO_PC15A_SDCS, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_SDRAM_SDCS_ALT { PIO_GROUP_D, PIO_PD18A_SDCS, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_SDRAM_BA0      { PIO_GROUP_A, PIO_PA20C_BA0, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_BA1      { PIO_GROUP_A, PIO_PA0C_BA1, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_RAS      { PIO_GROUP_D, PIO_PD16C_RAS, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_CAS      { PIO_GROUP_D, PIO_PD17C_CAS, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_SDWE     { PIO_GROUP_D, PIO_PD29C_SDWE, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_NBS0     { PIO_GROUP_C, PIO_PC18A_NBS0, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_SDRAM_NBS1     { PIO_GROUP_D, PIO_PD15C_NBS1, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_A0_9     { PIO_GROUP_C, 0x3FF00000, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_SDRAM_A10      { PIO_GROUP_D, PIO_PC13C_SDA10, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_A10_ALT  { PIO_GROUP_D, PIO_PD13C_SDA10, PIO_PERIPH_C, PIO_DEFAULT }
#define PIN_SDRAM_D0_7     { PIO_GROUP_C, 0x000000FF, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_SDRAM_D8_13    { PIO_GROUP_E, 0x0000003F, PIO_PERIPH_A, PIO_DEFAULT }
#define PIN_SDRAM_D14_15   { PIO_GROUP_A, 0x00018000, PIO_PERIPH_A, PIO_DEFAULT }

//=============================================================================

#endif /* _CHIP_PINS_H_ */