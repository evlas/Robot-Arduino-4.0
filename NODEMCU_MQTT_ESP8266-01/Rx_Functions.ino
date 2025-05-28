// Funzione per ricevere i dati dal MEGA

void Receive_All_From_MEGA() {
  String Serial_RX_Value = "";  // Variabile per ricevere i dati dal MEGA

  while (Serial.available() > 0) {
    char recieved = Serial.read();
    if (recieved != '\g' && recieved != '\c' && recieved != '\d' && recieved != '\z' && recieved != '\y' && recieved != '\o' && recieved != '\m') {
      Serial_RX_Value += (char)recieved;
    } else if (recieved == '\g') {
      val_VoltNow = Serial_RX_Value.toFloat();
      BatteryVoltage = val_VoltNow;
      Serial_RX_Value = "";
    } else if (recieved == '\c') {
      Loop_Cycle_Mowing = Serial_RX_Value.toInt();
      Serial_RX_Value = "";
    } else if (recieved == '\d') {
      Mower_Docked = Serial_RX_Value.toInt();
      Serial_RX_Value = "";
    } else if (recieved == '\z') {
      Mower_Running = Serial_RX_Value.toInt();
      Serial_RX_Value = "";
    } else if (recieved == '\y') {
      Mower_Parked = Serial_RX_Value.toInt();
      Serial_RX_Value = "";
    } else if (recieved == '\o') {
      Charge_Detected = Serial_RX_Value.toInt();
      Serial_RX_Value = "";
    } else if (recieved == '\m') {
      Tracking_Wire = Serial_RX_Value.toInt();
      Serial_RX_Value = "";
    }
  }
}

void Update_Home_Assistant_With_Status() {
  JsonDocument discovery;
  String mqtt_data = "";

  //control
  discovery["name"] = "control";
  discovery["unique_id"] = "mower_control";
  discovery["max"] = "255";
  discovery["min"] = "0";
  discovery["mode"] = "text";
  discovery["component"] = "text";
  discovery["command_topic"] = (String(mqtt_topic_in)).c_str();
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/text/mower/control/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  // BatteryVoltage
  discovery["name"] = "Battery";
  discovery["device_class"] = "voltage";
  discovery["unit_of_measurement"] = "V";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/battery").c_str();
  discovery["unique_id"] = "robotmowerbattery";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/battery/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  // Loop_Cycle_Mowing
  discovery["name"] = "loop";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/loop").c_str();
  discovery["unique_id"] = "mowerloop";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/loop/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();
  ;

  // Mower_Parked
  discovery["name"] = "parked";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/parked").c_str();
  discovery["unique_id"] = "mowerparked";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/parked/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  // Mower_Docked
  discovery["name"] = "docked";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/docked").c_str();
  discovery["unique_id"] = "mowerdocked";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/docked/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  // Mower_Running
  discovery["name"] = "running";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/running").c_str();
  discovery["unique_id"] = "mowerrunning";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/running/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  // Charge_Detected
  discovery["name"] = "charge";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/charge").c_str();
  discovery["unique_id"] = "mowercharge";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/charge/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  // Tracking_Wire
  discovery["name"] = "tracking";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/tracking").c_str();
  discovery["unique_id"] = "mowertracking";
  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";
  serializeJson(discovery, mqtt_data);
  client.beginPublish((String(mqtt_topic_discovery) + "/sensor/mower/tracking/config").c_str(), mqtt_data.length(), false);
  client.print(mqtt_data.c_str());
  client.endPublish();
  discovery.clear();

  client.publish((String(mqtt_topic_out) + "/battery").c_str(), String(BatteryVoltage).c_str());
  client.publish((String(mqtt_topic_out) + "/loop").c_str(), String(Loop_Cycle_Mowing).c_str());
  client.publish((String(mqtt_topic_out) + "/parked").c_str(), String(Mower_Parked).c_str());
  client.publish((String(mqtt_topic_out) + "/docked").c_str(), String(Mower_Docked).c_str());
  client.publish((String(mqtt_topic_out) + "/running").c_str(), String(Mower_Running).c_str());
  client.publish((String(mqtt_topic_out) + "/charge").c_str(), String(Charge_Detected).c_str());
  client.publish((String(mqtt_topic_out) + "/tracking").c_str(), String(Tracking_Wire).c_str());
}
