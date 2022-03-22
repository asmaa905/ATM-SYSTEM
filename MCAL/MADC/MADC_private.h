/*
 * MADC_private.h
 *
 *  Created on: Oct 24, 2021
 *      Author: Mina
 */

#ifndef MADC_MADC_PRIVATE_H_
#define MADC_MADC_PRIVATE_H_

/* ADC Registers */
#define MADC_ADMUX_REG	*(((volatile u8*)0x27))
#define MADC_ADCSRA_REG	*(((volatile u8*)0x26))
#define MADC_ADCH_REG	*(((volatile u8*)0x25))
#define MADC_ADCL_REG	*(((volatile u8*)0x24))
#define MADC_SFIOR_REG	*(((volatile u8*)0x50))

/* ADMUX Register b*/
#define REFS1	7
#define REFS0	6
#define ADLAR	5

/* ADCSRA Register bits */
#define ADEN	7 /* Enable ADC bit */
#define ADSC	6 /* Start conversion bit */
#define ADATE	5 /* ADC Auto Trigger Enable bit */
#define ADIF	4 /* Conversion complete flag */
#define ADIE	3 /* conversion complete interrupt */

/* PRESCALER options */
#define MADC_PRESCALER_2	1
#define MADC_PRESCALER_4	2
#define MADC_PRESCALER_8	3
#define MADC_PRESCALER_16	4
#define MADC_PRESCALER_32	5
#define MADC_PRESCALER_64	6
#define MADC_PRESCALER_128	7

/* VREF options */
#define MADC_VREF_INTERNAL  3
#define MADC_VREF_AVCC		1
#define MADC_VREF_AREF		0

#define MADC_VREF_MASK			0b00111111
#define MADC_PRESCALER_MASK		0b11111000
#define CHANNEL_MASK			0b11100000
#endif /* MADC_MADC_PRIVATE_H_ */
