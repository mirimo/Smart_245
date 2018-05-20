void setup() {
  // ---- Serial monitor
  Serial.begin(9600);
  Serial.println("Setup - START");

  // ---- Wylaczenie karty SD
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  Serial.println("Setup - D4 OFF");

  // ---- Inicjalizacja Ledow
  pinMode(LED_BUTTON, OUTPUT);
  digitalWrite(LED_BUTTON, led_button_state);
  Serial.println("Setup - LEDs Inicjalized");

  // ---- Inicjalizacja buttonow
  pinMode(BUTTON_1, INPUT_PULLUP); // Relay Switch 1
  button_1.attach(BUTTON_1);
  button_1.interval(BOUNCE_INTERVAL);
  Serial.println("Setup - BUTTONs Inicjalized");

  // --- Inicjalizacja ethernetu
  Ethernet.begin(mac);
  Serial.print("Setup - Ethernet - ");
  delay(1500);
  Serial.print("ON, ip:");
  Serial.println(Ethernet.localIP());
  

  // --- Inicjalizacja MQTT
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  Serial.print("Setup - MQTT server - ");
  delay(1500);
  Serial.println("ON");
  Serial.print("  ");
  reconnect();

  // --- Pixels
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
   clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif
  strip.begin();
  // Update LED contents, to start they are all 'off'
  strip.show();


  // ----
  Serial.println("Setup - END");
  Serial.println();
}
