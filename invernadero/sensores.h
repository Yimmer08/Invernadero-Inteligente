
#ifndef _sensores_h_
#define _sensores_h_

extern int temperatura = 0;
extern int humedad = 0;
extern int sensorLDR = 0;
extern int humedad_suelo = 0;
//asignacion de pines para los sensores
#define DHT11_PIN 4
#define LDR 35
#define humedad_FC_28 34

void leer_Temp_Hum();
void leer_luminosidad();
void leer_humedad_suelo();

#endif