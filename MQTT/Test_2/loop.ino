void loop() {
  
  // --- Uaktualnij stan przyciskow
  button_1.update();

  update_leds();

  // --- Uaktualnij stan ledow
  if (button_1.fell() == HIGH){
    led_button_state = 1 - led_button_state;
    digitalWrite(LED_BUTTON, led_button_state);
    counter += 1;
    Serial.println(counter);
    mqtt_publish(switchTopic2, byte(counter));
  }

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
   
}
