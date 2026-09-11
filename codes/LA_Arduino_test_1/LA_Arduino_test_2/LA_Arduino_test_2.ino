const int stepPin = 8;
const int dirPin = 9;
const int stepsPerRev = 400; // Now this makes sense! (e.g. DRV8825 with 1/20 microstepping)

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Send '1' for fwd, '2' for bwd");
}

void loop() {
  
}

void moveSteps(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500); // Adjust for speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}
