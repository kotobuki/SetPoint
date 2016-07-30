#include <SetPoint.h>

// The threshold
int threshold = 511;

// The hysteresis
int hysteresis = 102;

// The analog input pin connected to the LDR
int sensorPin = 0;

// The digital pin connected to the LED
int ledPin = 13;

// SetPoint
SetPoint setPoint;

void setup() {
  // Declare the ledPin as an OUTPUT
  pinMode(ledPin, OUTPUT);

  // Initialize the library instance
  setPoint.begin(threshold, hysteresis);

  // Set event handlers to two events
  setPoint.attach(RISING_EDGE, onBrightenUp);
  setPoint.attach(FALLING_EDGE, onDarkenUp);
}

void loop() {
  // Read the value from the sensor
  int value = analogRead(sensorPin);

  // Update the library instance with the value to detect edges
  setPoint.update(value);

  // Stop the program for 100 ms
  delay(100);
}

// On brighten up
void onBrightenUp() {
  // Turn the LED on
  digitalWrite(ledPin, LOW);
}

// On darken up
void onDarkenUp() {
  // Turn the LED off
  digitalWrite(ledPin, HIGH);
}

