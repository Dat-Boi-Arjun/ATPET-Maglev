int BREAKBEAM_PIN = 53;

void setup() {
  // put your setup code here, to run once:
  pinMode(BREAKBEAM_PIN, INPUT);
  digitalWrite(BREAKBEAM_PIN, HIGH);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(BREAKBEAM_PIN));
  delay(500);
}
