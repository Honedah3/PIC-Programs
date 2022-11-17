/*
 * File:   OLED.c
 * Author: Erick
 *
 * Created on 26 de mayo de 2021, 10:07 PM
 */

#include <18f24j11.h> //Biblioteca para usar el PIC18F24J11.
#fuses INTRC_IO, NOWDT, NOPROTECT //Configuración de fusibles.
#use delay (clock=32000000)
#use I2C(MASTER, SCL=PIN_C6, SDA=PIN_C, FAST=4000000, stream=SSD1306_STREAM)
// No soporta el puerto I2C nativo, lo maneja por SW
#include <stdio.h>
#include <stdlib.h>
#define SSD1306_I2C_ADDRESS 0x78 //OK
#include <SSD1306OLED.c> //Debe estar en PICC


//Drivers
//https://simple-circuit.com/
char cadena[12];
char cadeni[12];
char txt[9]; //Variable auxiliar para desplegar
signed int16 cuenta=0; //Contador
float temp=27.8; //Ejemplo
void main(void) //Función principal main.
{
// Initialize the SSD1306 OLED with an I2C addr = 0x7A (default address)
SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
delay_ms(100);
cadena="Contador";
SSD1306_ClearDisplay();
SSD1306_Display();
while(TRUE) //Bucle infinito.
{ //Inicio del bucle.
output_low(PIN_C0); //LED off.
delay_ms(500); //Retardo de 500 ms.
output_high(PIN_C0); //LED on.
SSD1306_ClearDisplay();
SSD1306_DrawText(2, 7, cadena, 2); //Col, Ren, Texto, Size
//sprintf
(txt, "%.2f", temp); //Flotante dos decimales
sprintf
(txt, "%ld", cuenta); //Entero
SSD1306_DrawText(2, 32, txt, 3); //Col, Ren, Texto, Size
SSD1306_Display();
delay_ms(500); //Retardo de 500 ms.
cuenta++;
} //Fin del bucle infinito. 
}