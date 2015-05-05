int LDR = 0;     //analog pin to which LDR is connected, here we set it to 0 so it means A0
int LDRValue = 0;      //that’s a variable to store LDR values
int light_sensitivity = 300;    //This is the approx value of light surrounding your LDR
char menu;

// note to self
// '1' == 1
// "1" == 49


void setup()
  {
    Serial.begin(9600);          //start the serial monitor with 9600 buad
    pinMode(12, OUTPUT);     //we mostly use 13 because there is already a built in yellow LED in arduino which shows output when 13 pin is enabled
    
    
    Serial.println("#####--Menu--######");
    Serial.println("###Select mode..###");
    Serial.println("æ: Lightsensor reader and on/off diode.");
    Serial.println("ø: for snabel");
    Serial.println("9: for exiting a mode");
  }
 
void loop()
  {
//    LDRValue = analogRead(LDR);      //reads the ldr’s value through LDR 
//    Serial.println(LDRValue);       //prints the LDR values to serial monitor
   // delay(100);        //This is the speed by which LDR sends value to arduino
  
  if(Serial.available() > 0) {
    menu = Serial.read();
    Serial.println(menu);
    switch(menu) {
    case 'æ':
      Serial.println("Welcome to mode 1");
      char in;
      Serial.println("Hit a key to get value from lightsensor.");
      while(true){
        if(Serial.available() > 0) {
          in = Serial.read();
          // code goes here
          
          LDRValue = analogRead(LDR);      //reads the ldr’s value through LDR 
          Serial.println(LDRValue);       //prints the LDR values to serial monitor
          
          if (LDRValue < light_sensitivity) {
              digitalWrite(12, HIGH);
            }
          else {
              digitalWrite(12, LOW);
            }
          // code ends here
          if(in == '9') {
            Serial.println("break");
            break;  
          }
        } // if end
      } // while end
      break;
    case 'ø':
      Serial.println("Welcome to mode 2");
        char in2;
        while(true){
            // code goes here
            if(Serial.available() > 0) {
             in2 = Serial.read();
             Serial.println(in2);       
     
            // code ends here
            if(in2 == '9') {
              Serial.println("break");
              break;
            } // if end - break
          } // if end
        } // while end
        break;
      } // swithc end
      Serial.println("#####--Menu--######");
      Serial.println("###Select mode..###");
      Serial.println("1: for snabel");
      Serial.println("2: for snabel");
    } // if end
}
