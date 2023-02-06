// Only turn on one magnet at a time
void accelerate(int[] breakbeams, int[] electromagnets) {
  for (int i = 0; i < sizeof(breakbeams) / sizeof(int); i++) {
    if digitalRead(breakbeams[i]) {
      // If this is true, then the current breakbeam is the back-most on the cart
      if !(digitalRead(breakbeams[i - 1])) {
        // Turn on the current electromagnet if the cart just passed the previous breakbeam
        digitalWrite(electromagnets[i], HIGH);
        // Turn off previous electromagnet
        digitalWrite(electromagnets[i-1], HIGH);
      }
    }
  }
}

void decelerate(int[] breakbeams, int[] electromagnets) {
  for (int i = 0; i < sizeof(breakbeams) / sizeof(int); i++) {
    if digitalRead(breakbeams[i]) {
      // If this is true, then the current breakbeam is the front-most on the cart
      if !(digitalRead(breakbeams[i + 1])) {
        // Turn on the current electromagnet if the cart just passed the previous breakbeam
        digitalWrite(electromagnets[i], HIGH);
        // Turn on the next electromagnet just in case we need extra magnetic force
        digitalWrite(electromagnets[i+1], HIGH)
        // TODO figure out if we need to progressively decelerate and how long it takes
      }
    }
  }
}

double getSpeed(int[] breakbeams) {
  //TODO
}