#ifndef _actuadores_h_
#include <ESP32Servo.h>
Servo servo_ventana;

#define _sensores_h_

#define ventilador 15  //rele
#define bomba_riego 22  //rele
#define lampara 2       //rele
#define ventana 13  

#define led_rojo 18
#define led_verde 19
#define led_azul 21

int Umbral_temp_alta = 30;
int Umbral_temp_baja = 18;
int Umbral_luz = 50;
int Umbral_hum_suelo = 40;

int cant_agua=0;

void actuador();
void activarBomba();


#endif