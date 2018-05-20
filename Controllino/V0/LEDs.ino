
#define LED_COUNTER 8

#define LED_SALON_WEJSCIE 0
#define LED_SALON_KUCHNIA 1
#define LED_SALON_LODOWKA 2
#define LED_SALON_SRODEK 3
#define LED_SALON_KANAPA 4
#define LED_SYPIALNIA 5
#define LED_LAZIENKA_SUFIT_A 6
#define LED_LAZIENKA_SUFIT_B 7

FadeLed leds[] = {
  PIN_D2_SALON_WEJSCIE,
  PIN_D3_SALON_KUCHNIA,
  PIN_D4_SALON_LODOWKA,
  PIN_D5_SALON_SRODEK,
  PIN_D6_SALON_KANAPA,
  PIN_D7_SYPIALNIA,
  PIN_D8_LAZIENKA_SUFIT_A,
  PIN_D9_LAZIENKA_SUFIT_B
};

int pwm_value = 70;

void set_led_pwm(int led_number) {
  
  if (led_number != -1 and led_number < LED_COUNTER) {
    leds[led_number].set(pwm_value);
  } else {
    for (int i; i < LED_COUNTER; i++) {
      leds[i].set(pwm_value);
    }
  }
  
}

