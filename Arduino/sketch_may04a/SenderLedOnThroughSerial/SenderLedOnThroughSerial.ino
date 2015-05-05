/*
Sending signal
When hw button is pushed, sends serial comm to the other board.
*/
int analogChannel = 0;
int analogInput;
void setup() {
    Serial.begin(9600);          //start the serial monitor with 9600 buad
}

// the loop function runs over and over again forever
void loop() {


   analogInput = analogRead(analogChannel);
   if(analogInput > 348){
         Serial.println(1);
     }
   if(analogInput < 348) {
     Serial.println(2);  
   }
}
