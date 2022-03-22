





#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MADC_config.h"
#include "MADC_interface.h"
#include "MADC_private.h"

void MADC_voidInit(void)
{
	/* step 1: config prescaler */
	MADC_ADCSRA_REG &=  MADC_PRESCALER_MASK;
	MADC_ADCSRA_REG |= MADC_PRESCALER;

	/* step 2: vref select */
	MADC_ADMUX_REG &= MADC_VREF_MASK;
	MADC_ADMUX_REG |= MADC_VREF<< 6;

	/* step 3: disable INT*/
	CLR_BIT(MADC_ADCSRA_REG,ADIE);

	/* step 4: config adjustment */
	CLR_BIT(MADC_ADMUX_REG,ADLAR);

	/* step : Enable ADC */
	SET_BIT(MADC_ADCSRA_REG,ADEN);
}
u16 MADC_voidADCread(u8 copy_ADCchannel)
{
	u16 adc_digital_value;

	/* step 1: choose channel */
	MADC_ADMUX_REG &= CHANNEL_MASK;
	MADC_ADMUX_REG |= copy_ADCchannel;

	/* step 2: start conversion */
	SET_BIT(MADC_ADCSRA_REG,ADSC);

	/* step 3: wait until conversion is complete */
	while(GET_BIT(MADC_ADCSRA_REG,ADIF)==0);

	/* step 4: read value */
	adc_digital_value = MADC_ADCL_REG + (MADC_ADCH_REG<<8);

	/* step 5: return value */
	return adc_digital_value;
}
