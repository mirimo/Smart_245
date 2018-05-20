void callback(char* topic, byte* payload, unsigned int length) {

  //convert topic to string to make it easier to work with
  String topicStr = topic; 
  //EJ: Note:  the "topic" value gets overwritten everytime it receives confirmation (callback) message from MQTT

  //Print out some debugging info
  Serial.println("Callback update.");
  Serial.print("Topic: ");
  Serial.println(topicStr);

   if (topicStr == "/house/switch1/") 
    {

     //turn the switch on if the payload is '1' and publish to the MQTT server a confirmation message
     if(payload[0] == '1'){
       digitalWrite(switchPin1, HIGH);
       client.publish("/house/switchConfirm1/", "1");
       }

      //turn the switch off if the payload is '0' and publish to the MQTT server a confirmation message
     else if (payload[0] == '0'){
       digitalWrite(switchPin1, LOW);
       client.publish("/house/switchConfirm1/", "0");
       }
     }

     // EJ: copy and paste this whole else-if block, should you need to control more switches
     else if (topicStr == "/house/switch2/") 
     {
     //turn the switch on if the payload is '1' and publish to the MQTT server a confirmation message
     if(payload[0] == '1'){
       digitalWrite(switchPin2, HIGH);
       client.publish("/house/switchConfirm2/", "1");
       }

      //turn the switch off if the payload is '0' and publish to the MQTT server a confirmation message
     else if (payload[0] == '0'){
       digitalWrite(switchPin2, LOW);
       client.publish("/house/switchConfirm2/", "0");
       }
     }
}

