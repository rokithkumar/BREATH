#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;
uint32_t aun_ir_buffer[500];  //infrared LED sensor data
uint32_t aun_red_buffer[500]; //red LED sensor data
int pulseRate;
int oxygen;
const int ledPin = 2; // connect LED to digital pin 13
const int lm35Pin = A3; // connect LM35 to analog pin A0

void setup() {
  Serial.begin(9600); // set up serial communication at 9600 baud
  pinMode(ledPin, OUTPUT); // set LED pin as output
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) { //use fast I2C
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
}

void loop() {
  // Initialize variables
  byte rate[4];
  byte pulseWidth[4];

  // Read values from sensor
  int32_t irValue = particleSensor.getIR();
  int32_t redValue = particleSensor.getRed();

  // Read temperature from LM35 sensor
  float voltage = analogRead(lm35Pin) * 5.0 / 1023.0;
  float temperature = voltage * 100.0;

  // Calculate pulse rate and oxygen level
  if (checkForBeat(irValue) == true) {
    // We sensed a beat!
    float ratio = (float)redValue / irValue;
    int bpm = getHeartRateBeatPerMinute();
    pulseRate = bpm;
    oxygen = getSpO2();
  }

  // Send the temperature, oxygen level, and pulse rate readings over the serial port
  Serial.print("T:");
  Serial.print(temperature);
  Serial.print(",O:");
  Serial.print(oxygen);
  Serial.print(",P:");
  Serial.println(pulseRate);
  
  // Wait for command from Python to turn on/off LED
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == '1') {
      digitalWrite(ledPin, HIGH); // turn on LED
    } else if (cmd == '0') {
      digitalWrite(ledPin, LOW); // turn off LED
    }
  }
  
  delay(100); // Delay for 100ms
}
