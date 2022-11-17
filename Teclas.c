/*
 * File:   Teclas.c
 * Author: Erick
 *
 * Created on 26 de mayo de 2021, 10:31 PM
 */
#include <18f24j11.h>
#include <stdio.h>
#include <stdlib.h>
#fuses INTRC_IO, NOWDT, NOPROTECT
#use I2C(MASTER, SCL=PIN_C7, SDA=PIN_C6, FAST=4000000, STREAM=SSD1306_STREAM)
#use delay(clock = 32000000)                                        // Libreria para manejo de pantalla OLED por I2C
#define SSD1306_I2C_ADDRESS 0x78                                  // Direccion 0x78 o 0x7A
#include <SSD1306OLED.c> 
#define LOWTOHIGH TRUE
#INT_RB

char cadena[12];

int current,last,dbutton4,dbutton5,dbutton6,dbutton7;
signed int16 cuenta = 0;

void detect_rb_change(void)
{
current=input_b();
#if LOWTOHIGH
if ((bit_test(current,4))&&(!bit_test(last,4)))
    cuenta++;
/*if ((!bit_test(last,5))&&(bit_test(current,5)))
dbutton5=1;
if ((!bit_test(last,6))&&(bit_test(current,6)))
dbutton6=1;
if ((!bit_test(last,7))&&(bit_test(current,7)))
dbutton7=1;
#elif HIGHTOLOW
if ((!bit_test(current,4))&&(bit_test(last,4)))
dbutton4=1;
if ((!bit_test(current,5))&&(bit_test(last,5)))
dbutton5=1;
if ((!bit_test(current,6))&&(bit_test(last,6)))
dbutton6=1;
if ((!bit_test(current,7))&&(bit_test(last,7)))
dbutton7=1;*/
#endif
last=current;
delay_ms(1);
}

void main(void){
   enable_interrupts (INT_RB);
   enable_interrupts(GLOBAL);
   setup_oscillator( OSC_32MHZ | OSC_INTRC );  //Oscilador interno 8 MHz //Todas las interrupciones activadas.
   set_tris_b(0xF0);
   set_tris_c(0x00);  // Puerto C como salidas
   SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
   cadena="kiubas";
   SSD1306_ClearDisplay();
   SSD1306_Display();
   signed int16 cuenta = 0;
   char txt[9]; //Variable auxiliar para desplegar
   while(TRUE){
       detect_rb_change();
       SSD1306_DrawText(10, 1, cadena, 2); //Col, Ren, Texto, Size
       //sprintf(txt, "%.2f", temp); //Flotante dos decimales
       if(dbutton4==1){
       cuenta++;
       sprintf(txt, "%ld",cuenta); //Entero
       SSD1306_DrawText(43, 30, txt, 3); //Col, Ren, Texto, Size
       SSD1306_Display();
      
       }
       else {
           
       }
      delay_ms(500); //Retardo de 500 ms.
   }
}