// Include the Teensyduino library
#include <Arduino.h>

// Define the motor PWM pin numbers
const int motorPins[] = {2, 3, 4, 5};
const int greenLEDPins[] = {9, 10, 11, 12};
const int numOutputs = sizeof(greenLEDPins) / sizeof(greenLEDPins[0]);

// Define the PWM frequency
#define PWM_FREQ 5000

// Define the duty cycles for each motor, 0-255, could be a %
const int dutyCycles[] = {75, 255, 100, 255};

// Define the LED pin number
const int ledPin = 13;

// Define a global variable to control the LED state
bool ledOn = false;

void setup() {
  // Start serial communication at 9600 baud
  Serial.begin(9600);

  // Print the number of motors to the serial monitor
  Serial.print("Number of outputs: ");
  Serial.println(numOutputs);

  // Initialize the PWM pins as outputs
  for (int i = 0; i < numOutputs; i++) {
    pinMode(greenLEDPins[i], OUTPUT);
    pinMode(motorPins[i], OUTPUT);
    analogWriteFrequency(greenLEDPins[i], PWM_FREQ);
    analogWriteFrequency(motorPins[i], PWM_FREQ);
  }

  // ledPin
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Set the duty cycle for each motor
  for (int i = 0; i < numOutputs; i++) {
    analogWrite(greenLEDPins[i], dutyCycles[i]);
    analogWrite(motorPins[i], dutyCycles[i]);
  }

  ledOn = !ledOn;
  digitalWrite(ledPin, ledOn);
  
  // Delay for one second
  delay(1000);
}
