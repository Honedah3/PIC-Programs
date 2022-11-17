/*
 * File:   LM35.c
 * Author: Erick
 *
 * Created on 20 de mayo de 2021, 12:31 PM
 */


#include<18f24j11.h> //Biblioteca para usar el PIC18F24J11
#device ADC = 10
#fuses INTRC_IO, NOWDT, NOPROTECT //Configuración de fusibles.
#use delay(internal=8MHz)
#use fast_io(C)
#define LCD_ENABLE_PIN PIN_B0
#define LCD_RW_PIN PIN_B2
#define LCD_RS_PIN PIN_B1
#define LCD_DATA4 PIN_C4
#define LCD_DATA5 PIN_C5
#define LCD_DATA6 PIN_C6
#define LCD_DATA7 PIN_C7
// ES INDISPENSABLE DEFINIR LOS PINES ANTES DE INVOCAR LA BIBLIOTECA LCD  
#include <lcd.c>

void main(void) //Función principal main
{
float t;
int16 valorAD;
setup_oscillator(OSC_8MHZ); //Oscilador interno 8 MHz
disable_interrupts(GLOBAL); //Todas las interrupciones desactivadas.
lcd_init(); // Inicializa el LCD.
lcd_putc('\a');
lcd_putc('\f');
printf(lcd_putc, "  Temperatura:");
lcd_gotoxy(1,2);
setup_adc(ADC_CLOCK_DIV_8 | ADC_TAD_MUL_2 );
setup_adc_ports(sAN0);
set_adc_channel(0);
while(TRUE) //Bucle infinito.
{ //Inicio del bucle.
valorAD = read_adc();
t = valorAD*330/1024.0;//valorAD*3300/1024.0;
lcd_gotoxy(1,2);
printf(lcd_putc," T = %f ", t);
printf(lcd_putc, "[");
lcd_putc(223);
printf(lcd_putc, "C]  ");
delay_ms(100);
} //Fin del bucle infinito.
}