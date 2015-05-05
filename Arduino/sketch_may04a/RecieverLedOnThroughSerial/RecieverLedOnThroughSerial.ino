/*
Reciever that turns on a LED
Serial tx/rx 
*/

char input;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);          //start the serial monitor with 9600 buad
    pinMode(13, OUTPUT);     //we mostly use 13 because there is already a built in yellow LED in arduino which shows output when 13 pin is enabled
    
}

void loop() {
  if(Serial.available() > 0) {
    input = Serial.read();
    Serial.println(input);
    if(input == '1') {
      digitalWrite(13, HIGH);
    }
    if(input == '2') {
      digitalWrite(13, LOW);
    } 
  }
}
