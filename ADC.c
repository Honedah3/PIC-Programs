/*
 * File:   ADC.c
 * Author: Erick
 *
 * Created on 10 de mayo de 2021, 07:51 PM
 */


#include <18f24j11.h> //Biblioteca para usar el PIC18F24J11.

#device ADC= 10
int16 valorAD;

void main(){
setup_adc( ADC_CLOCK_DIV_32); //Configura reloj, y adquisición
setup_adc_ports( sAN2 ); //Configura Puerto como A/D
set_adc_channel( 2 ); //Selecciona canal
valorAD = read_adc (); //Lee convertidor A/D
}
