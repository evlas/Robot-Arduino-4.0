// Funzione per ricevere i dati dal MEGA

void Receive_All_From_MEGA() {
  String NodeMCU_RX_Value = "";  // Variabile per ricevere i dati dal MEGA

  while (NodeMCU.available() > 0) {
    char recieved = NodeMCU.read();
    if (recieved != '\g' && recieved != '\c' && recieved != '\d' && recieved != '\z' && recieved != '\y' && recieved != '\o' && recieved != '\m') {
      NodeMCU_RX_Value += (char)recieved;
    } else if (recieved == '\g') {
      val_VoltNow = NodeMCU_RX_Value.toFloat();
      BatteryVoltage = val_VoltNow;
      Serial.print("Battery Voltage: ");
      Serial.println(BatteryVoltage);
      NodeMCU_RX_Value = "";
    } else if (recieved == '\c') {
      Loop_Cycle_Mowing = NodeMCU_RX_Value.toInt();
      NodeMCU_RX_Value = "";
    } else if (recieved == '\d') {
      Mower_Docked = NodeMCU_RX_Value.toInt();
      NodeMCU_RX_Value = "";
    } else if (recieved == '\z') {
      Mower_Running = NodeMCU_RX_Value.toInt();
      NodeMCU_RX_Value = "";
    } else if (recieved == '\y') {
      Mower_Parked = NodeMCU_RX_Value.toInt();
      NodeMCU_RX_Value = "";
    } else if (recieved == '\o') {
      Charge_Detected = NodeMCU_RX_Value.toInt();
      NodeMCU_RX_Value = "";
    } else if (recieved == '\m') {
      Tracking_Wire = NodeMCU_RX_Value.toInt();
      NodeMCU_RX_Value = "";
    }
  }
}

void Update_Home_Assistant_With_Status() {
  JsonDocument discovery;
  String data;

  discovery["device"]["name"] = "Mower";
  discovery["device"]["manufacturer"] = "Marco Bedendo";
  discovery["device"]["model"] = "Mower Sensor";
  discovery["device"]["identifiers"] = "BedendoMower";

  //control
  discovery["name"] = "control";
  discovery["object_id"] = "mower_control";
  discovery["unique_id"] = "mower_control";
  discovery["max"] = "255";
  discovery["min"] = "0";
  discovery["mode"] = "text";
  discovery["command_topic"] = (String(mqtt_topic_in)).c_str();
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/text").c_str(), String(data).c_str());

  // BatteryVoltage
  discovery["name"] = "battery";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/battery").c_str();
  discovery["device_class"] = "battery";
  discovery["unit_of_measurement"] = "V";
  discovery["unique_id"] = "mowerbattery";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/battery").c_str(), String(data).c_str());

  // Loop_Cycle_Mowing
  discovery["name"] = "loop";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/loop").c_str();
  discovery["device_class"] = "";
  discovery["unit_of_measurement"] = "";
  discovery["unique_id"] = "mowerloop";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/loop").c_str(), String(data).c_str());

  // Mower_Parked
  discovery["name"] = "parked";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/parked").c_str();
  discovery["device_class"] = "";
  discovery["unit_of_measurement"] = "";
  discovery["unique_id"] = "mowerparked";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/parked").c_str(), String(data).c_str());

  // Mower_Docked
  discovery["name"] = "docked";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/docked").c_str();
  discovery["device_class"] = "";
  discovery["unit_of_measurement"] = "";
  discovery["unique_id"] = "mowerdocked";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/docked").c_str(), String(data).c_str());

  // Mower_Running
  discovery["name"] = "running";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/running").c_str();
  discovery["device_class"] = "";
  discovery["unit_of_measurement"] = "";
  discovery["unique_id"] = "mowerrunning";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/running").c_str(), String(data).c_str());

  // Charge_Detected
  discovery["name"] = "charge";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/charge").c_str();
  discovery["device_class"] = "";
  discovery["unit_of_measurement"] = "";
  discovery["unique_id"] = "mowercharge";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/charge").c_str(), String(data).c_str());

  // Tracking_Wire
  discovery["name"] = "tracking";
  discovery["state_topic"] = (String(mqtt_topic_out) + "/tracking").c_str();
  discovery["device_class"] = "";
  discovery["unit_of_measurement"] = "";
  discovery["unique_id"] = "mowertracking";
  serializeJson(discovery, data);
  client.publish((String(mqtt_topic_discovery) + "/tracking").c_str(), String(data).c_str());

  client.publish((String(mqtt_topic_out) + "/battery").c_str(), String(BatteryVoltage).c_str());
  client.publish((String(mqtt_topic_out) + "/loop").c_str(), String(Loop_Cycle_Mowing).c_str());
  client.publish((String(mqtt_topic_out) + "/parked").c_str(), String(Mower_Parked).c_str());
  client.publish((String(mqtt_topic_out) + "/docked").c_str(), String(Mower_Docked).c_str());
  client.publish((String(mqtt_topic_out) + "/running").c_str(), String(Mower_Running).c_str());
  client.publish((String(mqtt_topic_out) + "/charge").c_str(), String(Charge_Detected).c_str());
  client.publish((String(mqtt_topic_out) + "/tracking").c_str(), String(Tracking_Wire).c_str());
}
