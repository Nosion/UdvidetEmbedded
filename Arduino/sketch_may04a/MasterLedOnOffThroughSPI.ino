/*Example taken form http://electronics.stackexchange.com/questions/42197/making-two-arduinos-talk-over-spi 
and edited by Jakob.*/

/*
############ MASTER ###########
*/

#include <SPI.h>

int analogInput0;
int analogInput1;
int analogChannel0 = 0;
int analogChannel1 = 1;
void setup (void)
{
	Serial.begin(115200);
	digitalWrite(SS, HIGH);
	SPI.begin ();
	SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop (void)
{
	char c;

	// enable Slave Select
	digitalWrite(SS, LOW);    // SS is pin 10

	analogInput0 = analogRead(analogChannel0);
	analogInput1 = analogRead(analogChannel1);
	
	if(analogInput0 > 300) {
		for (const char * p = "y\n" ; c = *p; p++) {
			SPI.transfer (c);
			Serial.print(c);
			delay (500);
		}
	}
	
	if(analogInput1 > 300) {
		for (const char * p = "n\n" ; c = *p; p++) {
			SPI.transfer (c);
			Serial.print(c);
			delay (500);
		}
	}

	// disable Slave Select
	digitalWrite(SS, HIGH);

}
