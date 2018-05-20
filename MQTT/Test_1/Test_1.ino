#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10, 20, 30, 106);
IPAddress server(10, 20, 30, 4);

const int switchPin1 = 2;
const int switchPin2 = 3;
//EJ: These are the MQTT Topic that will be used to manage the state of Relays 1 ~ 4
//EJ: Refer to my YAML component entry

char const* switchTopic1 = "/house/switch1/";
char const* switchTopic2 = "/house/switch2/";


EthernetClient ethClient;
PubSubClient client(ethClient);


void setup()
{
  
  Serial.begin(9600);
  Serial.println("Setup - 1");
  
  client.setServer(server, 1883);
  client.setCallback(callback_org);

  Serial.println("Setup - 2");

  Ethernet.begin(mac, ip);
  Serial.println("Setup - 3");
  
  // Allow the hardware to sort itself out
  delay(1500);

  Serial.println("Setup - 4");
  pinMode(switchPin1, OUTPUT); // Relay Switch 1
  digitalWrite(switchPin1, LOW);

  pinMode(switchPin2, OUTPUT); // Relay Switch 2
  digitalWrite(switchPin2, LOW);
  
  Serial.println("Setup - END");
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
