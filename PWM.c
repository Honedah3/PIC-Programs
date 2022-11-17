/*
 * File:   PWM.c
 * Author: Erick
 *
 * Created on 20 de mayo de 2021, 12:12 PM
 */


#include <18f24j11.h> //Biblioteca para usar el PIC18F24J11.
#device ADC = 10
#fuses INTRC_IO, NOWDT, NOPROTECT //Configuración de fusibles.
#use delay(internal = 8MHz)
#use pwm(PWM1,OUTPUT = PIN_C0,FREQUENCY = 10000,DUTY = 0)
#use fast_io(C)
#INT_TIMER1

void TIMER1_isr(void)
{
int16 valorAD;
valorAD = read_adc();
pwm_set_duty_percent(valorAD);
output_toggle(PIN_C1);
set_timer1(65286);
}
void main(void) //Función principal main.
{
setup_oscillator( OSC_8MHZ );
set_tris_c(0x00); //Puerto C como salidas
setup_adc(ADC_CLOCK_DIV_8 | ADC_TAD_MUL_2 );
setup_adc_ports(sAN0);
set_adc_channel(0);
setup_timer_1(T1_INTERNAL | T1_DIV_BY_8 );
set_timer1(65286); //10 ms overflow
enable_interrupts(INT_TIMER1);
enable_interrupts(GLOBAL);

while(TRUE) //Bucle infinito.
{ //Inicio del bucle.
} //Fin del bucle infinito.
}                                                                                                                                                                                                                                                                                                                                                                                                                      