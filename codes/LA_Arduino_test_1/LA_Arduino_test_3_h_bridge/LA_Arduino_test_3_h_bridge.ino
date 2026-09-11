int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int stepIndex = 0;
int direction = -1; // 1 = forward, -1 = backward

int stepsPerRev = 100; // adjust to your motor

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void stepMotor(int step) {
  switch(step) {
    case 0: // A+, B+
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

    case 1: // A-, B+
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;

    case 2: // A-, B-
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;

    case 3: // A+, B-
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
  }
}

void moveSteps(int steps) {
  for (int i = 0; i < steps; i++) {
    stepMotor(stepIndex);

    stepIndex += direction;

    if (stepIndex > 3) stepIndex = 0;
    if (stepIndex < 0) stepIndex = 3;

    delay(5); // speed control
  }
}

void loop() {

  if (Serial.available() > 0) {
    int incoming = Serial.read();

    if (incoming == '1') {
      Serial.println("Moving forward");
      direction = 1;
      moveSteps(stepsPerRev * 10);
    } 
    else if (incoming == '2') {
      Serial.println("Moving backward");
      direction = -1;
      moveSteps(stepsPerRev * 10);
    }
  }

}
