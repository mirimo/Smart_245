Bounce Button_Main_Right = Bounce();
Bounce Button_Main_Left = Bounce();
Bounce Button_Living_Right = Bounce();
Bounce Button_Living_Left = Bounce();
Bounce Button_Sleap_Right = Bounce();
Bounce Button_Sleap_Left = Bounce();

void buttons_init() {
  pinMode(PIN_A0, INPUT);
  pinMode(PIN_A1, INPUT);
  pinMode(PIN_A2, INPUT);
  pinMode(PIN_A3, INPUT);
  pinMode(PIN_A4, INPUT);
  pinMode(PIN_A5, INPUT);

  Button_Main_Right.attach(PIN_A2);
  Button_Main_Right.interval(5);
  Button_Main_Left.attach(PIN_A3);
  Button_Main_Left.interval(5);
  Button_Living_Right.attach(PIN_A4);
  Button_Living_Right.interval(5);
  Button_Living_Left.attach(PIN_A5);
  Button_Living_Left.interval(5);
  Button_Sleap_Right.attach(PIN_A1);
  Button_Sleap_Right.interval(5);
  Button_Sleap_Left.attach(PIN_A0);
  Button_Sleap_Left.interval(5);
}

void buttons_update() {
  Button_Main_Right.update();
  Button_Main_Left.update();
  Button_Living_Right.update();
  Button_Living_Left.update();
  Button_Sleap_Right.update();
  Button_Sleap_Left.update();

  if (Button_Main_Right.fell()) {
    int temp = (leds[LED_SALON_KUCHNIA].get() == 0) ? pwm_value : 0;
    leds[LED_SALON_KUCHNIA].set(temp);
    leds[LED_SALON_LODOWKA].set(temp);
  };
  if (Button_Main_Left.fell()) {
    leds[LED_LAZIENKA_SUFIT_A].set((leds[LED_LAZIENKA_SUFIT_A].get() == 0) ? pwm_value : 0);
  };
  if (Button_Living_Right.fell()) {
    leds[LED_SALON_SRODEK].set((leds[LED_SALON_SRODEK].get() == 0) ? pwm_value : 0);
  };
  if (Button_Living_Left.fell()) {
    leds[LED_SALON_KANAPA].set((leds[LED_SALON_KANAPA].get() == 0) ? pwm_value : 0);
  };
  if (Button_Sleap_Left.fell()) {
    leds[LED_SYPIALNIA].set((leds[LED_SYPIALNIA].get() == 0) ? pwm_value : 0);
  };
  if (Button_Sleap_Right.fell()) {
    leds[LED_SALON_KANAPA].set((leds[LED_SALON_KANAPA].get() == 0) ? pwm_value : 0);
  };
}

