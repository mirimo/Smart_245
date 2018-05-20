// -------- Setup
void setup() {
  pinMode(PIN_R0_SWIATLO_KUCHNIA_BAR, OUTPUT);
  buttons_init();
  
  Serial.begin(9600);
  Serial.println("START");
  
  digitalWrite(PIN_R0_SWIATLO_KUCHNIA_BAR, ON);
  for (int i; i < LED_COUNTER; i++) {
    leds[i].setTime(4000);
    leds[i].set(0);
  }

}
