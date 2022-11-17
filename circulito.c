/*
 * File:   circulo.c
 * Author: Erick
 *
 * Created on 1 de junio de 2021, 12:34 AM
 */
#include <18f24j11.h> //Biblioteca para usar el PIC18F24J11.
#include <math.h>
#fuses INTRC_IO, NOWDT, NOPROTECT //Configuración de fusibles.
#use delay (clock=32000000)
#use I2C(MASTER, SCL=PIN_C7, SDA=PIN_C6, FAST=4000000, stream=SSD1306_STREAM)
// No soporta el puerto I2C nativo, lo maneja por SW
#include <stdio.h>
#include <stdlib.h>
#define SSD1306_I2C_ADDRESS 0x78 //OK
#include <SSD1306OLED.c> //Debe estar en PICC

#define SSD1306_LCDWIDTH            128
#define SSD1306_LCDHEIGHT            64
float x = 0;
void main(void) //Función principal main.
{while(TRUE) //Bucle infinito.
{ //Inicio del bucle.
 
        x = sqrt(0.33);

// Initialize the SSD1306 OLED with an I2C addr = 0x7A (default address)
SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
SSD1306_ClearDisplay();        // limpia pantalla
  for(int i=1; i < 1.4*SSD1306_LCDHEIGHT ; i++) {  // bucle desde 1 hasta alto de pantalla/2
    SSD1306_DrawCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT /2, i);   // dibuja circulo
    SSD1306_Display();       // muestra en pantalla todo lo establecido anteriormente 
    SSD1306_ClearDisplay();  // limpia pantalla
  }

} 
} //Fin del bucle infinito. 
