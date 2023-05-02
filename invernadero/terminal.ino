#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE

#include "terminal.h"
#include <DabbleESP32.h>

//funcion para enviar datos a la terminal de la aplicacion dabble
void enviarDatos(String data) {
  Terminal.print(data);  // Mostrar los datos en la terminal
}


//funcion para leer los datos enviados desde la terminal de dabble 
String leerTerm(){
  String cadena;
  Dabble.processInput();
  do {
    while (Terminal.available() != 0) {
      cadena = Terminal.readString();
    }
    Dabble.processInput();
  } while (Terminal.available() == 0);
  cadena = Terminal.readString();
  return cadena;

}




