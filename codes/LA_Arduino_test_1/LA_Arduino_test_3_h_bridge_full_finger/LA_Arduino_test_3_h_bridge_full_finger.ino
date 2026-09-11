int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int IN11 = 3;
int IN22 = 4;
int IN33 = 5;
int IN44 = 6;
int INA = 0;
int INB = 0;
int INC = 0;
int IND = 0;
int motor = 1;
int stepIndex = 1;
int direction = 1; // 1 = forward, -1 = backward

int stepsPerRev = 100; // adjust to your motor

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN11, OUTPUT);
  pinMode(IN22, OUTPUT);
  pinMode(IN33, OUTPUT);
  pinMode(IN44, OUTPUT);

  Serial.begin(9600);
}

void stepMotor(int step, int motor) {
  if (motor == 1){
      INA = IN1;
      INB = IN2;
      INC = IN3;
      IND = IN4;
      }
  if (motor == 2){
      INA = IN11;
      INB = IN22;
      INC = IN33;
      IND = IN44;
      }
      
  switch(step) {
    case 0: // A+, B+
      digitalWrite(INA, HIGH);
      digitalWrite(INB, LOW);
      digitalWrite(INC, HIGH);
      digitalWrite(IND, LOW);
      break;

    case 1: // A-, B+
      digitalWrite(INA, LOW);
      digitalWrite(INB, HIGH);
      digitalWrite(INC, HIGH);
      digitalWrite(IND, LOW);
      break;

    case 2: // A-, B-
      digitalWrite(INA, LOW);
      digitalWrite(INB, HIGH);
      digitalWrite(INC, LOW);
      digitalWrite(IND, HIGH);
      break;

    case 3: // A+, B-
      digitalWrite(INA, HIGH);
      digitalWrite(INB, LOW);
      digitalWrite(INC, LOW);
      digitalWrite(IND, HIGH);
      break;
  }
}

void moveSteps(int steps, int motor ) {
  for (int i = 0; i < steps; i++) {
    stepMotor(stepIndex , motor);

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
      Serial.println("Moving forward - lock - Joint 1");
      direction = 1;
      moveSteps(stepsPerRev * 10 , 1);
    } 
    else if (incoming == '2') {
      Serial.println("Moving backward - unlock - Joint 1");
      direction = -1;
      moveSteps(stepsPerRev * 10 , 1);
    }
    if (incoming == '3') {
      Serial.println("Moving forward - lock - Joint 2");
      direction = 1;
      moveSteps(stepsPerRev * 10 , 2);
    } 
    else if (incoming == '4') {
      Serial.println("Moving backward - unlock - Joint 2");
      direction = -1;
      moveSteps(stepsPerRev * 10 , 2);
    }
  }

}
