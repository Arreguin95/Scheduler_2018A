/****************************************************************************
 * Proyecto realizado para mostrar funcionamiento de una UART
 * con maquinas de estado
 *
 *
 * Date: 02 May 2018
 * Author: Luis Antonio Arreguin Sandoval
 */

#include <drivers_HAL/fsl_gpio.h>
#include "MKL25Z4.h"
#include "stdtypedef.h"

#define TX (18)
#define TX_SHIFT (1 << 18)
#define RX (19)

#define TX_BAJO			(GPIOB->PCOR = TX_SHIFT)
#define TX_ALTO			(GPIOB->PSOR = TX_SHIFT)                                                                                                                                                                                                                                             [8]	    01010100

uint8_t contador = 0;
uint8_t i=0;

void tx_alto(void);
void uart_tx(void);

void init_uart(void){
	/* Turn on clock to PortB module */
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;

	/* Set the PTB18 pin multiplexer to GPIO mode */
	PORTB->PCR[18] = PORT_PCR_MUX(1);

	/* Set the initial output state to high */
	GPIOB->PSOR |= TX_SHIFT;

	/* Set the pins direction to output */
	GPIOB->PDDR |= TX_SHIFT;
}
