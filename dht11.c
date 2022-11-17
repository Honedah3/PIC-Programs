/*
 * File:   dht11.c
 * Author: Erick
 *
 * Created on 9 de junio de 2021, 09:34 PM
 */

#include <18f24j11.h> //Biblioteca para usar el PIC18F24J11.
#device ADC = 10
#fuses INTRC_IO, NOWDT, NOPROTECT //Configuración de fusibles.
#use delay (internal=8000000)
#use I2C(MASTER, SCL=PIN_C6, SDA=PIN_C7, FAST=4000000, stream=SSD1306_STREAM)
// No soporta el puerto I2C nativo, lo maneja por SW
#include <stdio.h>
#include <stdlib.h>
#define SSD1306_I2C_ADDRESS 0x78 //OK
#include <SSD1306OLED.c> //Debe estar en PICC
#use fast_io(C)
#INT_TIMER1
// variables para el oled
char cadena[12];
char cadena1[12];
char cadena2[12];
char cadena3[12];
char txt[9]; //Variable auxiliar para desplegar
///////////////////////////////////////
void main(void) //Función principal main.
{
 int16 valorAD;
 setup_oscillator(OSC_8MHZ); //Oscilador interno 8 MHz
 disable_interrupts(GLOBAL); //Todas las interrupciones desactivadas.
 setup_adc(ADC_CLOCK_DIV_8 | ADC_TAD_MUL_2 );
 setup_adc_ports(sAN0);
 set_adc_channel(0);
// Initialize the SSD1306 OLED with an I2C addr = 0x7A (default address)
SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
delay_ms(100);
cadena="Calidad";
cadena1= "Veredicto";
cadena2= "Mala";
cadena3= "Buena";
SSD1306_ClearDisplay();
SSD1306_Display();

while(TRUE) 
{ //Inicio del bucle.
valorAD = read_adc();
//Accion en pantalla    
SSD1306_ClearDisplay();
SSD1306_DrawText(29, 0, cadena,1 ); //Col, Ren, Texto, Size
SSD1306_DrawText(38, 37, cadena1,1 ); //Col, Ren, Texto, Size
sprintf(txt, "%ld", valorAD); //Entero
SSD1306_DrawText(20, 13, txt, 2); //Col, Ren, Texto, Size

if (valorAD >= 900){
SSD1306_DrawText(20, 50, cadena2, 2); //Col, Ren, Texto, Size
}
else {
    SSD1306_DrawText(20, 50, cadena3, 2); //Col, Ren, Texto, Size
}

SSD1306_Display();
delay_ms(500); //Retardo de 500 ms.
} //Fin del bucle infinito. 
}
