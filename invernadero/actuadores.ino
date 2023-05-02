//funcion para el control de los actuadores
void actuador() {

  ///////control de temperatura y alarmas////
  if (temperatura >= Umbral_temp_alta) {
    //encender ventilador con low
    digitalWrite(ventilador, LOW); 

 //encender led rojo
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_azul, HIGH);
  } else if (temperatura <= Umbral_temp_baja) {
   //apagar ventilador 
    digitalWrite(ventilador, HIGH);
 //enceder led azul
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_azul, LOW);
  } else {
  
    digitalWrite(ventilador, HIGH);
  //encender led verde
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_azul, HIGH);
  }

  //////////control de luz ///////////
  if (sensorLDR <= Umbral_luz){
    digitalWrite(lampara, LOW);  //prender con low
    servo_ventana.write(180);    //cerrar ventana
  } else {
    digitalWrite(lampara, HIGH);
    servo_ventana.write(90);
  }
  /////////control de Riego//////////
  if (humedad_suelo <= Umbral_hum_suelo) {
    //combinar led rojo+verde=amarillo
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, LOW);
    //alarma luminica////
    digitalWrite(led_azul, HIGH);
    //////////////////////

    digitalWrite(bomba_riego, LOW);
    delay(3000);
    digitalWrite(bomba_riego, HIGH);
    delay(2000);
   

  } else {
    digitalWrite(bomba_riego, HIGH);
  }
}
/*Funcion para controlar el riego de las plantas
La bomba de agua funciona a razon de 1 gota por segundo
*/
void activarBomba(){
  // Calculamos la cantidad de gotas necesarias
  int gotas = cant_agua / 0.05;

  // Calculamos el tiempo que tardará la bomba en funcionar
  int tiempoBomba = gotas * 1000;

  // Encendemos la bomba durante el tiempo necesario
  unsigned long tiempoInicio = millis();
  while ((millis() - tiempoInicio) < tiempoBomba) {
    digitalWrite(bomba_riego, LOW);
    delay(3000);  // Esperamos 1 segundo para que caiga una gota
    digitalWrite(bomba_riego, HIGH);
    delay(1000);  // Esperamos 1 segundo antes de encender la bomba de nuevo
  }
}
