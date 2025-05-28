// Funzione per trasmettere i dati al MEGA con aggiunta del codice


void Transmit_MQTT_Data_to_Mega() {
    i = transmit_MQTT_code;   // trasmissione il codice
      Serial.print(i);
      Serial.println("\p");  // Aggiunge il carattere di fine
      delay(30);
      delay(20);
      }
