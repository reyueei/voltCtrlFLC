#include <SoftwareSerial.h>

char rxbyte;
int  i;
char * range;
char * watts;
char * va;
char * var;
char * pf;
char * volts;
char * amps;
char padata[53];
bool StartDataReceived = false;
bool DataAvailable = false;


SoftwareSerial mySerial(10, 255); 

void setup()  
{
	Serial.begin(9600);
	mySerial.begin(9600);
}

void loop()
{
	if (mySerial.available() > 0)
	{
		rxbyte = mySerial.read();
		if ( rxbyte == 'I')
		{
			StartDataReceived = true;
			padata[0] = rxbyte;
		}
	}
	if (( StartDataReceived == true) && ( mySerial.available() > 0))
	{
		for ( i = 1; i < 53; i++ )
		{
			while (mySerial.available() == 0){}
			padata[i] = mySerial.read();
		}
		StartDataReceived = false;
		DataAvailable = true;
	}
	if ( DataAvailable == true)
	{
		range	= strtok(padata, ",");
		watts	= strtok(NULL, ",");
		va		= strtok(NULL, ",");
		var		= strtok(NULL, ",");
		pf		= strtok(NULL, ",");
		volts	= strtok(NULL, ",");
		amps	= strtok(NULL, ",");
			
		Serial.print("WATTS: "); Serial.println(watts);
		Serial.print("VA: "); Serial.println(va);
		Serial.print("VAR: "); Serial.println(var);
		Serial.print("PF: "); Serial.println(pf);
		Serial.print("VOLTS: "); Serial.println(volts);
		Serial.print("AMPS: "); Serial.println(amps);
		memset(padata, NULL, 53);
		DataAvailable = false;
	}
}
