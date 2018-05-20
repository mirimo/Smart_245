void save_pwm_from_serial(){

  if (Serial.available())
  {
    char ch = Serial.read();
    Serial.println(ch);
    if (ch >= '0' && ch <= '9')
    {
      int id = (ch - '0');
      set_led_pwm(id);
    }
    
  }
}

