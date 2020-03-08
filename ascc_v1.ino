#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire); 

const int redPin = 11;
const int greenPin = 6;
const int bluePin = 3;
const int fanPin = 10;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("\n");
  
  delay(1000); 
  while (Serial.available() > 0) {
    int fan = Serial.parseInt();
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    
    if (Serial.read() == '\n') {
      analogWrite(fanPin, fan);
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
    }
  }
}
