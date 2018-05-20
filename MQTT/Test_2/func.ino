void callback(char* topic, byte* payload, unsigned int m_length) {
  // --- Formatowanie wiadomosci
  mqtt_message_convertion(topic, payload, m_length);
  char table[][10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

  // --- Interpetacja wiadomosci
  if (component_name == "LED_RED")
  {
    if (component_function == "") {
      Serial.println(" RED_LED - None");
      switch (payload[0]) {
        case '0':
          RedLedState[0] = 0;
          mqtt_publish("/ARD_1_STATE/LED_RED/", "0");
          break;
        case '1':
          RedLedState[0] = 1;
          mqtt_publish("/ARD_1_STATE/LED_RED/", "1");
          mqtt_publish("/ARD_1_STATE/LED_RED/dim/", table[RedLedState[1] / 12]);
          break;
        default:
          Serial.print("  Not recognized:");
          Serial.println(payload[0]);
      }
    } else if (component_function == "dim") {
      Serial.println(" RED_LED - dim");
      RedLedState[1] = (payload[0] - '0') * 12;
      mqtt_publish("/ARD_1_STATE/LED_RED/dim/", table[(payload[0] - '0')]);
    }
  }

  if (component_name == "LED_BLUE")
  {
    if (component_function == "") {
      Serial.println(" LED_BLUE - None");
      switch (payload[0]) {
        case '0':
          ledsState[3][0] = 0;
          //mqtt_publish("/ARD_1_STATE/LED_BLUE/", byte("0"));
          Serial.println("  MQTT Answear [/ARD_1_STATE/LED_BLUE/] 0");
          client.publish("/ARD_1_STATE/LED_BLUE/", "0");
          break;
        default:
          Serial.print("  Not recognized:");
          Serial.println(payload[0]);
      }
    } else if (component_function == "dim") {
      Serial.println(" LED_BLUE - dim");
      // String dimm_level = payload[0] - '0';
      char table[][10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
      ledsState[3][0] = 1;
      ledsState[3][1] = (payload[0] - '0') * 12;
      mqtt_publish("/ARD_1_STATE/LED_BLUE/dim/", table[(payload[0] - '0')]);
    }
  }
  Serial.println();
}



void mqtt_message_convertion(char* topic, byte* message, unsigned int m_length) {
  Serial.print("MQTT Message [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < m_length; i++) {
    Serial.print((char)message[i]);
  }
  Serial.println();

  // --- Konwersja zmiennych
  String topicStr = topic;
  int firstCommaIndex = topicStr.indexOf('/', 7); // Pomin nazwe ardu
  int secondCommaIndex = topicStr.indexOf('/', firstCommaIndex + 1);
  component_name = topicStr.substring(7, firstCommaIndex);
  component_function = topicStr.substring(firstCommaIndex + 1, secondCommaIndex);
}

void mqtt_publish(char* topic, char* message) {
  Serial.print("  MQTT Answear [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println(message);
  client.publish(topic, message);
}



void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(mqtt_client_name)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqtt_publish("/ARD_1_STATE/", byte("O"));
      mqtt_publish("/ARD_1_STATE/", "O");
      mqtt_publish("/ARD_1_STATE/", 0);
      // ... and resubscribe
      client.subscribe(mqtt_subscribe);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void update_leds() {

  if (RedLedState[0] == 0) {
    redLed.off();
  } else {
    redLed.set(RedLedState[1]);
  }

  for (int i = 0; i < 4; i++) {
    if (ledsState[i][0] == 0) {
      leds[i].off();
    } else {
      leds[i].set(ledsState[i][1]);
    }
  }
  // --- Uaktualnij ledy
  FadeLed::update();

}

