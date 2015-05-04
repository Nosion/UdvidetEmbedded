int LDR = 0;     //analog pin to which LDR is connected, here we set it to 0 so it means A0
int LDRValue = 0;      //that’s a variable to store LDR values
int light_sensitivity = 300;    //This is the approx value of light surrounding your LDR
 
void setup()
  {
    Serial.begin(9600);          //start the serial monitor with 9600 buad
    pinMode(12, OUTPUT);     //we mostly use 13 because there is already a built in yellow LED in arduino which shows output when 13 pin is enabled
  }
 
void loop()
  {
    LDRValue = analogRead(LDR);      //reads the ldr’s value through LDR 
    Serial.println(LDRValue);       //prints the LDR values to serial monitor
    delay(50);        //This is the speed by which LDR sends value to arduino
 
    if (LDRValue < light_sensitivity) 
      {
        digitalWrite(12, HIGH);
      }
    else
      {
        digitalWrite(12, LOW);
      }
  }
