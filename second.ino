void setup() {
  Serial.begin(9600);
}

void loop() {
  int nm = random(100);
  Serial.println(nm);
  delay(500);
}

