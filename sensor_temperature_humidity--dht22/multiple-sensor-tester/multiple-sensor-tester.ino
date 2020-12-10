// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPINA 2     // what digital pin we're connected to

#define DHTPINB 3     // what digital pin we're connected to

#define DHTPINC 4     // what digital pin we're connected to

#define DHTPIND 5     // what digital pin we're connected to

#define DHTPINE 6     // what digital pin we're connected to

#define DHTPINF 7     // what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht1(DHTPINA, DHTTYPE);
DHT dht2(DHTPINB, DHTTYPE);
DHT dht3(DHTPINC, DHTTYPE);
DHT dht4(DHTPIND, DHTTYPE);
DHT dht5(DHTPINC, DHTTYPE);
DHT dht6(DHTPIND, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  dht6.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
<
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h1 = dht1.readHumidity();
  // Read temperature as Celsius (the default)
  float t1 = dht1.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f1 = dht1.readTemperature(true);

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float f2 = dht2.readTemperature(true);

  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();
  float f3 = dht3.readTemperature(true);

  float h4 = dht4.readHumidity();
  float t4 = dht4.readTemperature();
  float f4 = dht4.readTemperature(true);

  float h5 = dht5.readHumidity();
  float t5 = dht5.readTemperature();
  float f5 = dht5.readTemperature(true);

  float h6 = dht6.readHumidity();
  float t6 = dht6.readTemperature();
  float f6 = dht6.readTemperature(true);


  // Check if any reads failed and exit early (to try again).
  if (isnan(h1) || isnan(t1) || isnan(f1)) {
    Serial.println(">>> Failed to read from DHT sensor 1 !");
    //return;
  }

  if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println(">>> Failed to read from DHT sensor 2 !");
    //return;
  }
  if (isnan(h3) || isnan(t3) || isnan(f3)) {
    Serial.println(">>> Failed to read from DHT sensor 3 !");
    //return;
  }
  if (isnan(h4) || isnan(t4) || isnan(f4)) {
    Serial.println(">>> Failed to read from DHT sensor 4 !");
    //return;
  }
  if (isnan(h5) || isnan(t5) || isnan(f5)) {
    Serial.println(">>> Failed to read from DHT sensor 5 !");
    //return;
  }
  if (isnan(h6) || isnan(t6) || isnan(f6)) {
    Serial.println(">>> Failed to read from DHT sensor 6 !");
    //return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif1 = dht1.computeHeatIndex(f1, h1);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic1 = dht1.computeHeatIndex(t1, h1, false);

  float hif2 = dht2.computeHeatIndex(f2, h2);
  float hic2 = dht2.computeHeatIndex(t2, h2, false);

  float hif3 = dht3.computeHeatIndex(f3, h3);
  float hic3 = dht3.computeHeatIndex(t3, h3, false);

  float hif4 = dht4.computeHeatIndex(f4, h4);
  float hic4 = dht4.computeHeatIndex(t4, h4, false);

  float hif5 = dht5.computeHeatIndex(f5, h5);
  float hic5 = dht5.computeHeatIndex(t5, h5, false);

  float hif6 = dht6.computeHeatIndex(f6, h6);
  float hic6 = dht6.computeHeatIndex(t6, h6, false);

  Serial.print("SENSOR 1 ==== Humidity: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t1);
  Serial.print(" *C ");
  Serial.print(f1);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic1);
  Serial.print(" *C ");
  Serial.print(hif1);
  Serial.println(" *F");
  Serial.println("---------------------------");


  Serial.print("SENSOR 2 ==== Humidity: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t2);
  Serial.print(" *C ");
  Serial.print(f2);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic2);
  Serial.print(" *C ");
  Serial.print(hif2);
  Serial.println(" *F");
  Serial.println("---------------------------");


  Serial.print("SENSOR 3 ==== Humidity: ");
  Serial.print(h3);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t3);
  Serial.print(" *C ");
  Serial.print(f3);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic3);
  Serial.print(" *C ");
  Serial.print(hif3);
  Serial.println(" *F");
  Serial.println("---------------------------");


  Serial.print("SENSOR 4 ==== Humidity: ");
  Serial.print(h4);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t4);
  Serial.print(" *C ");
  Serial.print(f4);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic4);
  Serial.print(" *C ");
  Serial.print(hif4);
  Serial.println(" *F");
  Serial.println("---------------------------");

  Serial.print("SENSOR 5 ==== Humidity: ");
  Serial.print(h5);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t5);
  Serial.print(" *C ");
  Serial.print(f5);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic5);
  Serial.print(" *C ");
  Serial.print(hif5);
  Serial.println(" *F");
  Serial.println("---------------------------");

  Serial.print("SENSOR 6 ==== Humidity: ");
  Serial.print(h6);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t6);
  Serial.print(" *C ");
  Serial.print(f6);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic6);
  Serial.print(" *C ");
  Serial.print(hif6);
  Serial.println(" *F");
  Serial.println("---------------------------");

  
  Serial.println("=           END            =");
  Serial.println("============================");
  Serial.println("=                          =");


}
