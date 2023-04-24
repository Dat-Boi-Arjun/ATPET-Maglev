#include "maglev.h"

// First electromagnet is the start electromagnet
const int LEFT_ELECTROMAGNETS[] = {23, 25, 27, 29, 31, 33};
const int RIGHT_ELECTROMAGNETS[] = {38, 36, 34, 32, 30, 28};
// Each breakbeam is before its corresponding electromagnet on the track
// First breakbeam is the start breakbeam
const int BREAKBEAMS[] = {39, 41, 43, 45, 47, 49};

void setup() {
  Serial.begin(9600);
  // Setting up breakbeam sensors
  for (int i = 0; i < 6; i++) {
    // Set breakbeam pin as input
    pinMode(BREAKBEAMS[i], INPUT);
    // Turn on built-in pull-up resistor for breakbeam
    digitalWrite(BREAKBEAMS[i], HIGH);
  }

  // Setting up electromagnets
  for (int i = 0; i < 6; i++) {
    // Set electromagnet pin as output
    pinMode(LEFT_ELECTROMAGNETS[i], OUTPUT);
    pinMode(RIGHT_ELECTROMAGNETS[i], OUTPUT);
    // To stop current flow, raise mosfet to 5v
    digitalWrite(LEFT_ELECTROMAGNETS[i], HIGH);
    digitalWrite(RIGHT_ELECTROMAGNETS[i], HIGH);
  }

  Serial.println("Setup completed");
}

void loop() {
  accelerate(BREAKBEAMS, LEFT_ELECTROMAGNETS, RIGHT_ELECTROMAGNETS);
}
