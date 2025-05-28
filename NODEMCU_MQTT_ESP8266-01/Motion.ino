// Funzione per ricevere comandi da Home Assistant

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }


    if (String(topic) == mqtt_topic_in) {
    if (message == "start") {
      transmit_MQTT_code = 13;  // Comando per avviare il Robot
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "pause") {
      transmit_MQTT_code = 11;  // Comando per mettere in pausa il Robot
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "dock") {
      transmit_MQTT_code = 12;   // Comando per andare il Robot alla base
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "Exit Dock") {
      transmit_MQTT_code = 14;   // Comando per far uscire il Robot dalla base
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "manuale") {
      transmit_MQTT_code = 15;  // Comando per modalità manuale
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "automatico") {
      transmit_MQTT_code = 16;  // Comando per modalità automatica
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "avanti") {
      transmit_MQTT_code = 17;  // Comando per muovere avanti
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "indietro") {
      transmit_MQTT_code = 18;  // Comando per muovere indietro
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "destra") {
      transmit_MQTT_code = 20;  // Comando per girare a destra
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "sinistra") {
      transmit_MQTT_code = 19;  // Comando per girare a sinistra
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "fermo") {
      transmit_MQTT_code = 11;  // Comando per fermare il robot (pausa)
      Transmit_MQTT_Data_to_Mega();
      
    }
  }
}
