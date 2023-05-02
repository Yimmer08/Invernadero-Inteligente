#include "AsyncTaskLib.h"
#include "sensores.h"
#include "terminal.h"
#include "actuadores.h"
#include <DabbleESP32.h>

  
String cadena; //cadena para enviar datos a la aplicacion dabble

///tareas asincronas///
////////////////////////////////temperatura///////////////////////
AsyncTask asyncTaskTemperatura(1000, true, leer_Temp_Hum);
//////////////////////////// Fotorreistencia /////////////////////
AsyncTask asyncTaskFotorresistencia(5000, true, leer_luminosidad);
///////////////////////////humedad suelo//////////////////////////
AsyncTask asyncTaskHumedSuelo(4000, true, leer_humedad_suelo);

void setup() {
  //inicializamos funciones ///
  leer_Temp_Hum();
  leer_luminosidad();
  leer_humedad_suelo();
  actuador();
  ///configuracion de pines///
  pinMode(ventilador, OUTPUT);
  //////////leds////////////////
  pinMode(led_azul, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  /////////////////////////////
  pinMode(lampara, OUTPUT);
  ////////////////////////////
  pinMode(bomba_riego, OUTPUT);
  ////////////////////////////
  servo_ventana.attach(ventana);

 
  Serial.begin(115200);
  Dabble.begin("Esp32_Invernadero");
  /////////tareas asincronas /////////////////
  asyncTaskTemperatura.Start();       //leer temperatura
  asyncTaskFotorresistencia.Start();  //sensor de luz
  asyncTaskHumedSuelo.Start();        //leer humedad suelo
 
}



void loop() {
  Dabble.processInput();  //actualizar el envio de datos 
  //Terminal.available() envia 1 si hay datos nuevos enviados desde la aplicacion
  if (Terminal.available() != 0) {
    menu();
    Dabble.processInput(); 
  }
  actuador();

  //actualizar tareas asincronas
  asyncTaskTemperatura.Update();
  asyncTaskFotorresistencia.Update();
  asyncTaskHumedSuelo.Update();
}
