// Only turn on one magnet at a time
void accelerate(int breakbeams[], int left_electromagnets[], int right_electromagnets[]) {
  while (true) {
    for (int i = 0; i < 6; i++) {
      // Beam broken
      if (!digitalRead(breakbeams[i])) {
        // If i = 0, then the cart is just starting to be pushed
        // so there is no previous electromagnet
        Serial.println(i);
        if (i != 0) {
          // Turn on previous electromagnet
          digitalWrite(left_electromagnets[i-1], LOW);
          digitalWrite(right_electromagnets[i-1], LOW);
          Serial.print("Electromagnet ");
          Serial.print(i-1);
          Serial.println(": HIGH");
          // Turn off subsequent electromagnet (raise gate to +5v)
          digitalWrite(left_electromagnets[i], HIGH);
          digitalWrite(right_electromagnets[i], HIGH);
          Serial.print("Electromagnet ");
          Serial.print(i);
          Serial.println(": LOW");
        }
      }
    }
  }
}

// TODO get deceleration code working
// void decelerate(int[] breakbeams, int[] electromagnets) {
//   for (int i = 0; i < sizeof(breakbeams) / sizeof(int); i++) {
//     if digitalRead(breakbeams[i]) {
//       // If this is true, then the current breakbeam is the front-most on the cart
//       if !(digitalRead(breakbeams[i + 1])) {
//         // Turn on the current electromagnet if the cart just passed the previous breakbeam
//         digitalWrite(electromagnets[i], HIGH);
//         // Turn on the next electromagnet just in case we need extra magnetic force
//         digitalWrite(electromagnets[i+1], HIGH)
//         // TODO figure out if we need to progressively decelerate and how long it takes
//       }
//     }
//   }
// }