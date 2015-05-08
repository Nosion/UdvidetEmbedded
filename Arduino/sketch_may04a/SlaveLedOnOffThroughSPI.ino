/*Example taken form http://electronics.stackexchange.com/questions/42197/making-two-arduinos-talk-over-spi 
and edited by Jakob */

/*
####### SLAVE ########
*/

#include <SPI.h>

char buf [100];

volatile byte pos;
volatile boolean process_it;

void setup (void)
{
	Serial.begin (115200);

	// have to send on master in, *slave out*
	pinMode(MISO, OUTPUT);

	// turn on SPI in slave mode
	SPCR |= _BV(SPE);

	// get ready for an interrupt
	pos = 0;   // buffer empty
	process_it = false;

	// now turn on interrupts
	SPI.attachInterrupt();
	
	pinMode(7, OUTPUT);	
}


// SPI interrupt routine
ISR (SPI_STC_vect)
{
	byte c = SPDR;  // grab byte from SPI Data Register
	if (pos < sizeof buf)
	{
		buf [pos++] = c;
		if (c == '\n')
		process_it = true;
	}
}

void loop (void)
{
	if (process_it) {
		buf [pos] = 0;
		Serial.println (buf);
		if(buf[0] == 'y') {
			digitalWrite(7, HIGH);
			pos = 0;
			process_it = false;
		}	
	}
	if (process_it) {
		buf [pos] = 0;
		Serial.println (buf);
		if(buf[0] == 'n') {
			digitalWrite(7, LOW);
	}
		pos = 0;
		process_it = false;
	}
}


