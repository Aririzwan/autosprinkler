const int sensor_value = A0;	//pin for soil moisture sensor
const int led_pin = 7;			//pin for LED indicator
const int relay = 6;			//pin for relay

int output_value = 0;			//variable to store analog value from soil moisture sensor
int in_percent = 0;				//variable to store moisture value in percent

void setup() {
	// put your setup code here, to run once:
	pinMode(led_pin, OUTPUT);
	pinMode(relay, OUTPUT);
	digitalWrite(relay, LOW);
	Serial.begin(9600);
}

void loop() {
	// put your main code here, to run repeatedly:
	output_value = analogRead(sensor_value);					//retrive analog value from the sensor
	in_percent = map(output_value, 1023, 0, 0, 100);	//we use map function to convert analog value to percent
  
	if(in_percent >= 50) {
		digitalWrite(led_pin, LOW);
		digitalWrite(relay, HIGH);
	} if(in_percent <= 50) {
		digitalWrite(led_pin, HIGH);
		digitalWrite(relay, LOW);
	}
	printOnSerial();
}

//function to print output value to the serial
void printOnSerial() {
	Serial.print(output_value);
	Serial.println("");
	Serial.print(in_percent);
	Serial.println(" %");
	delay(1);
}

/*
Have a nice 'coding' day :)

Your friend, Ahmad Mujahid A
*/
