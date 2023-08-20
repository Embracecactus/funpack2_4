
#include <SoftwareSerial.h>

SoftwareSerial mySerial(PIN_PD5, PIN_PD4); // RX, TX
int sensorValue = 0;  // value read from the pot
void setup() {
  pinMode(PIN_PD3,OUTPUT);
   // Open serial communications and wait for port to open:
  Serial.begin(57600);
  // while (!Serial) {
  //   ; // wait for serial port to connect. Needed for native USB port only
  // }
    // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
}

void loop() {
 
 //读取adc值
 sensorValue=analogRead (PIN_PD7);
 float voltage= sensorValue * (3.3 / 1023.0);
 float tem=(voltage-0.5)*100;
  delay(1000);
  if(tem>40)
  {
    digitalWrite(PIN_PD3,HIGH);

  }
  else
  { 
      digitalWrite(PIN_PD3,LOW);

  }
 mySerial.println(tem);  
}
