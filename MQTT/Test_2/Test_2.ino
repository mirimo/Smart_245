#include <FadeLed.h>
#include <PubSubClient.h>
#include <Bounce2.h>
#include <Ethernet.h>
#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

// ------- PINY
#define BUTTON_1 7
#define LED_RED_LEFT 5
#define LED_RED_RIGHT 6
#define LED_GREEN_LEFT 9
#define LED_GREEN_RIGHT 8
#define LED_BLUE 9
#define LED_BUTTON 4
uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels

// ------- SIEC
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress mqtt_server(10, 20, 30, 4);


// ------- USTAWIENIA
#define BOUNCE_INTERVAL 10
char const* mqtt_client_name = "ARD_1";
char const* mqtt_subscribe = "/ARD_1/#";
char const* switchTopic1 = "/test_1/";
char const* switchTopic2 = "/test_2/";

// ------- OBIEKTY
Bounce button_1 = Bounce(); \
EthernetClient ethClient;
PubSubClient client(ethClient);
FadeLed redLed(LED_RED_LEFT);
FadeLed leds[] = {LED_RED_RIGHT, LED_GREEN_LEFT, LED_GREEN_RIGHT, LED_BLUE};
Adafruit_WS2801 strip = Adafruit_WS2801(16, dataPin, clockPin);

// ------- ZMIENNE
int led_button_state = LOW;
int RedLedState[] = {0, 50};
int ledsState[][2] = {{0, 10}, {0, 60}, {0, 70}, {0, 10}};
int counter = 0;
int temp;
String component_name;
String component_function;



