#include "terminal.h"


String opc;
//menu con las opciones generales de configuracion del invernadero 
void menu() {

  opc = leerTerm();

  if (opc.compareTo("menu") == 0) {
    enviarDatos("menu\n1-Leer temperatura\n2-Leer humedad\n3-leer luz\n4-leer hum suelo\n5-Cambiar Umbrales\n6-control riego");
    int input = leerTerm().toInt();
    switch (input) {
      case 1:
        Terminal.print("Temperatura:");
        enviarDatos(String(temperatura));
        break;
      case 2:
        Terminal.print("humedad:");
        enviarDatos(String(humedad));
        break;
      case 3:
        Terminal.print("luz:");
        enviarDatos(String(sensorLDR));
        break;
      case 4:
        Terminal.print("hum suelo:");
        enviarDatos(String(humedad_suelo));
        break;
      case 5:
        menu_Umbrales();
        break;
      case 6:
        menu_control_riego();
      break;  
      default:
        Terminal.println("Comando no reconocido.");
        break;
    }
  }
}

//menu con las opciones para configurar los umbrales 
void menu_Umbrales() {
  enviarDatos("menu cambiar umbrales\n1-Umbral hum suelo \n2-Umbral temp low\n3-Umbral temp High\n4-Umbral luz");

  int input = leerTerm().toInt();
  switch (input) {
    case 1:
      Umbral_hum_suelo = cambiar_Umbral(Umbral_hum_suelo);
      break;

    case 2:
      Umbral_temp_baja = cambiar_Umbral(Umbral_temp_baja);
      break;
    case 3:
      Umbral_temp_alta = cambiar_Umbral(Umbral_temp_alta);
      break;
    case 4:
      Umbral_luz = cambiar_Umbral(Umbral_luz);
      break;
    default:
      Terminal.println("Comando no reconocido.");
      break;
  }
}
//funcion para cambiar los umbrales 
int cambiar_Umbral(int Umbral_actual) {
  Terminal.print("valor actual");
  Terminal.println(Umbral_actual);
  Terminal.print("Ingrese el nuevo valor:");

  int Umbral_Nuevo = leerTerm().toInt();

  return Umbral_Nuevo;
}

//menu para el control del riego
void menu_control_riego() {
  Terminal.print("Control de riego\nIndique la cantidad en mL");
  cant_agua = leerTerm().toInt();
}