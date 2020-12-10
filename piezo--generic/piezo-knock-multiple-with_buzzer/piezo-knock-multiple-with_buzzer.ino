
const int ledPin = 13;    
const int knockSensor1 = A0; 
const int knockSensor2 = A1; 
const int threshold = 50; 



int sensorReading1 = 0;    
int sensorReading2 = 0;     
int ledState = LOW;        

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);      
}

void loop() {
  
  sensorReading1 = analogRead(knockSensor1);
  sensorReading2 = analogRead(knockSensor2);

  
  if (sensorReading1 >= threshold) {
  
    ledState = !ledState;
  
    digitalWrite(ledPin, ledState);
  
    Serial.println("  Knock1!");
    Serial.println(sensorReading1);
  }
  
  if (sensorReading2 >= threshold) {
  
    
    Serial.println("Knock2!");
    Serial.println(sensorReading2);
  }
  delay(100);  
}

