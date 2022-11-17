/*
 * File:   LED-pwm.c
 * Author: Erick
 *
 * Created on 1 de junio de 2021, 02:13 PM
 */


#include <18f24j11.h> //Biblioteca para usar el PIC18F24J11.
#fuses INTRC_IO, NOWDT, NOPROTECT //Configuración de fusibles.
#use delay(internal = 8MHz)
#use pwm(PWM1,OUTPUT = PIN_C0,FREQUENCY = 10000,BITS=10, DUTY = 0)
#use fast_io(C)
#INT_TIMER1

void cuenta_ascendente(void){
    int16 cuenta_1;
    for(cuenta_1 = 0; cuenta_1 < 1024; cuenta_1++){
    pwm_set_duty_percent(cuenta_1);
    }
}

void cuenta_descendente(void){
    int16 cuenta_2;
    for(cuenta_2 = 0; cuenta_2 < 1024; cuenta_2++){
    pwm_set_duty_percent(1023-cuenta_2);
    }
}

void TIMER1_isr(void)
{
toggle_output (PIN_C0);
set_timer1(65286); 
}
void main(void) //Función principal main.
{
setup_oscillator( OSC_8MHZ );
set_tris_c(0x00); //Puerto C como salidas
setup_timer_1(T1_INTERNAL | T1_DIV_BY_8 );
set_timer1(65286); //10 ms overflow
enable_interrupts(INT_TIMER1);
enable_interrupts(GLOBAL);

while(TRUE) //Bucle infinito.
{  //Fin del bucle infinito.
}
}