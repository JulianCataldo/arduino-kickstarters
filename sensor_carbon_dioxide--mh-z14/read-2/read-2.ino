// source : https://forum.mysensors.org/topic/3821/mh-z14a-co2-sensor/2
// *   Pad 1, Pad 5: Vin (Voltage input 4.5V-6V) 
// *   Pad 2, Pad 3, Pad 12: GND 
// *   Pad 6: PWM output ==> pin 6

// set pin number:
const int sensorPin = 2;     // the number of the sensor pin
long ppm=0;
unsigned long duration;

void setup() {
  Serial.begin(9600);
  // initialize the sensor pin as an input
  pinMode(sensorPin, INPUT);
}

void loop(){
  duration = pulseIn(sensorPin,HIGH,2000000);
  ppm = 5000 * (((duration)/1000)-2)/1000; 
    Serial.println("CO2 = " + String(ppm) + " ppm");
    delay(10000);
}
