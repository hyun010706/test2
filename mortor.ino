#define DIR1 6
#define PUL1 7
#define DIR2 8
#define PUL2 9

void setup() {
  pinMode(DIR1, OUTPUT);
  pinMode(PUL1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PUL2, OUTPUT);
}

void loop() {
  // 두 모터를 동시에 0.3바퀴 회전 (240 스텝)
  rotateMotorsSimultaneously(DIR1, PUL1, LOW, DIR2, PUL2, HIGH, 300);

  delay(500);
  // 두 모터를 동시에 역회전으로 0.3바퀴 회전
  rotateMotorsSimultaneously(DIR1, PUL1, HIGH, DIR2, PUL2, LOW, 300);

  // 2초 대기
  delay(2000);
}

void rotateMotorsSimultaneously(int dirPin1, int pulPin1, int dir1, int dirPin2, int pulPin2, int dir2, int steps) {
  digitalWrite(dirPin1, dir1);
  digitalWrite(dirPin2, dir2);
  for (int i = 0; i < steps; i++) {
    digitalWrite(pulPin1, HIGH);
    digitalWrite(pulPin2, HIGH);
    delayMicroseconds(200);
    digitalWrite(pulPin1, LOW);
    digitalWrite(pulPin2, LOW);
    delayMicroseconds(200);
  }
}


