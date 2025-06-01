// Auto discovery per sensore di movimento
void sendMotionDiscovery() {
  const char* discovery_topic = "homeassistant/binary_sensor/motion_sensor/config";
  const char* payload = R"rawliteral({
    "name": "Motion Sensor",
    "state_topic": "home/motion/state",
    "device_class": "motion",
    "payload_on": "ON",
    "payload_off": "OFF",
    "unique_id": "motion_sensor_01",
    "device": {
      "identifiers": ["motion_sensor_01"],
      "name": "Motion Sensor Node",
      "model": "PIR-Sensor",
      "manufacturer": "Custom"
    }
  })rawliteral";
  client.publish(discovery_topic, payload, true);
}

// Auto discovery per i comandi del robot

void sendRobotCommandDiscovery() {
  struct CommandInfo {
    const char* id;
    const char* name;
    const char* payload;
  } commands[] = {
    { "motion_start", "Start Robot", "start" },
    { "motion_pause", "Pause Robot", "pause" },
    { "motion_dock", "Dock Robot", "dock" },
    { "motion_exitdock", "Exit Dock", "Exit Dock" }
  };

  for (CommandInfo cmd : commands) {
    String topic = "homeassistant/button/" + String(cmd.id) + "/config";
    String payload = R"rawliteral({
      "name": "NAME",
      "command_topic": "home/robot/mower/control",
      "payload_press": "PAYLOAD",
      "unique_id": "ID",
      "device": {
        "identifiers": ["motion_sensor_01"],
        "name": "Motion Robot",
        "model": "Mower-X",
        "manufacturer": "Custom"
      }
    })rawliteral";
    payload.replace("NAME", cmd.name);
    payload.replace("PAYLOAD", cmd.payload);
    payload.replace("ID", cmd.id);
    client.publish(topic.c_str(), payload.c_str(), true);
  }
}

// Auto discovery per i comandi manuali e modalità
void sendManualControlDiscovery() {
  struct CommandInfo {
    const char* id;
    const char* name;
    const char* payload;
  } manualCmds[] = {
    { "manual_mode", "Manual Mode", "manuale" },
    { "auto_mode", "Automatic Mode", "automatico" },
    { "move_forward", "Move Forward", "avanti" },
    { "move_backward", "Move Backward", "indietro" },
    { "turn_left", "Turn Left", "sinistra" },
    { "turn_right", "Turn Right", "destra" },
    { "stop", "Stop", "pause" }
  };

  for (CommandInfo cmd : manualCmds) {
    String topic = "homeassistant/button/" + String(cmd.id) + "/config";
    String payload = R"rawliteral({
      "name": "NAME",
      "command_topic": "home/robot/mower/control",
      "payload_press": "PAYLOAD",
      "unique_id": "ID",
      "device": {
        "identifiers": ["motion_sensor_01"],
        "name": "Motion Robot",
        "model": "Mower-X",
        "manufacturer": "Custom"
      }
    })rawliteral";
    payload.replace("NAME", cmd.name);
    payload.replace("PAYLOAD", cmd.payload);
    payload.replace("ID", cmd.id);
    client.publish(topic.c_str(), payload.c_str(), true);
  }
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

#ifdef SOFT_SERIAL
  Serial.print("Received message: ");
  Serial.println(message);
  Serial.print("From topic: ");
  Serial.println(topic);
#endif
  if (String(topic) == mqtt_topic_in) {
    if (message == "start") {
#ifdef SOFT_SERIAL
      Serial.println("Starting Mower");
#endif
      transmit_MQTT_code = 13;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "pause" || message == "fermo") {
#ifdef SOFT_SERIAL
      Serial.println("Pausing Mower");
#endif
      transmit_MQTT_code = 11;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "dock") {
#ifdef SOFT_SERIAL
      Serial.println("Going Home");
#endif
      transmit_MQTT_code = 12;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "Exit Dock") {
#ifdef SOFT_SERIAL
      Serial.println("Exit Dock");
#endif
      transmit_MQTT_code = 14;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "manuale") {
#ifdef SOFT_SERIAL
      Serial.println("Switching to manual mode");
#endif
      transmit_MQTT_code = 15;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "automatico") {
#ifdef SOFT_SERIAL
      Serial.println("Switching to automatic mode");
#endif
      transmit_MQTT_code = 16;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "avanti") {
#ifdef SOFT_SERIAL
      Serial.println("Moving forward");
#endif
      transmit_MQTT_code = 17;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "indietro") {
#ifdef SOFT_SERIAL
      Serial.println("Moving backward");
#endif
      transmit_MQTT_code = 18;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "destra") {
#ifdef SOFT_SERIAL
      Serial.println("Turning right");
#endif
      transmit_MQTT_code = 20;
      Transmit_MQTT_Data_to_Mega();
    } else if (message == "sinistra") {
#ifdef SOFT_SERIAL
      Serial.println("Turning left");
#endif
      transmit_MQTT_code = 19;
      Transmit_MQTT_Data_to_Mega();
    }
  }
}
