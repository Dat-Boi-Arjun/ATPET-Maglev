#include "maglev.h"

const int BREAKBEAM_PIN = 53;
//const int[] ELECTROMAGNETS = int[]{5, 6, 7};
//const int[] BREAKBEAMS = int[]{10, 11, 12};

const int ELECTROMAGNET_PIN = 42;

void setup() {
  // Setting up breakbeam sensors
  // for (int i = 0; i < sizeof(BREAKBEAMS) / sizeof(int); i++) {
  //   // Set breakbeam pin as input
  //   pinMode(BREAKBEAMS[i], INPUT);
  //   // Turn on built-in pull-up resistor for breakbeam
  //   digitalWrite(BREAKBEAMS[i], HIGH);
  // }

  // Setting up electromagnets
  // for (int i = 0; i < sizeof(ELECTROMAGNETS) / sizeof(int), i++) {
  //   // Set electromagnet pin as output
  //   pinMode(ELECTROMAGNETS[i], OUTPUT);
  // }

  pinMode(ELECTROMAGNET_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(BREAKBEAM_PIN));
  //delay(500);

  digitalWrite(ELECTROMAGNET_PIN, HIGH);
}
