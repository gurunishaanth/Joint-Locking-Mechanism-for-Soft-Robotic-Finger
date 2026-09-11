const int stepPin = 311;
const int dirPin = 4;

bool moveForward = false;
bool moveBackward = false;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Send:");
  Serial.println("'1' → Forward");
  Serial.println("'2' → Backward");
  Serial.println("'0' → Stop");
}

void loop() {

  // Read serial command
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    if (cmd == '1') {
      Serial.println("Forward");
      moveForward = true;
      moveBackward = false;
      digitalWrite(dirPin, HIGH);
    } 
    else if (cmd == '2') {
      Serial.println("Backward");
      moveForward = false;
      moveBackward = true;
      digitalWrite(dirPin, LOW);
    } 
    else if (cmd == '0') {
      Serial.println("Stop");
      moveForward = false;
      moveBackward = false;
    }
  }

  // Continuous stepping
  if (moveForward || moveBackward) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}
