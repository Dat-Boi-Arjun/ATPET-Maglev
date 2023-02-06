#include "maglev.h"

const int BREAKBEAM_PIN = 53;
const int[] ELECTROMAGNETS = {5, 6, 7};
const int[] BREAKBEAMS = {10, 11, 12};

void setup() {
  // Setting up breakbeam sensors
  for (int i = 0; i < sizeof(BREAKBEAMS) / sizeof(int), i++) {
    // Set breakbeam pin as input
    pinMode(BREAKBEAMS[i], INPUT);
    // Turn on built-in pull-up resistor for breakbeam
    digitalWrite(BREAKBEAMS[i], HIGH);
  }

  // Setting up electromagnets
  for (int i = 0; i < sizeof(ELECTROMAGNETS) / sizeof(int), i++) {
    // Set electromagnet pin as output
    pinMode(ELECTROMAGNETS[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(BREAKBEAM_PIN));
  delay(500);

  accelerate(BREAKBEAMS, ELECTROMAGNETS);
}
