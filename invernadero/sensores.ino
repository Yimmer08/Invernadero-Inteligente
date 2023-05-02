#include <DFRobot_DHT11.h>
#include "sensores.h"

DFRobot_DHT11 DHT;

//////////////////////////////
//funcion para leer la temperatura y la humedad del DHT11
void leer_Temp_Hum() {

  DHT.read(DHT11_PIN);
  humedad = DHT.humidity;
  temperatura = DHT.temperature;
}
//////////////////////////////
//Funcion para leer la intensidad de luz  
void leer_luminosidad() {
  //funcion map() para que entregue los valores de luminosidad entre 0 y 100
  sensorLDR = int(map(int(analogRead(LDR)), 0,4095, 0, 100));
}
//////////////////////////////
//funcion para leer la humedad del suelo del sensor higrometro FC28
void leer_humedad_suelo() {
  humedad_suelo = 100 - int(map(int(analogRead(humedad_FC_28)), 1840, 4095, 0, 100));
}
