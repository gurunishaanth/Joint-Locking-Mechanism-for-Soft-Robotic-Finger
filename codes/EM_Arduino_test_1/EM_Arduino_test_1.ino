// Motor A connections
int in1 = 8;  // Direction pin 1
int in3 = 10;  // Direction pin 2

void setup() {
  // Set all the motor control pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in3, OUTPUT);
  Serial.begin(9600);   // START SERIAL
}

void loop() {
  
  if (Serial.available() > 0) {
    int incoming = Serial.read();

    if (incoming == '1') {
      Serial.println("lock - Joint 1");
      // --- mag 1 ---
      digitalWrite(in1, HIGH);
    } 
    else if (incoming == '2') {
      Serial.println("unlock - Joint 1");
       // --- mag 1 ---
       digitalWrite(in1, LOW);
    }
    if (incoming == '3') {
      Serial.println("lock - Joint 2");
      // --- mag 2 ---
      digitalWrite(in3, HIGH);
    } 
    else if (incoming == '4') {
      Serial.println("unlock - Joint 2");
        // --- mag 1 ---
      digitalWrite(in3, LOW);
    }
  }




}
