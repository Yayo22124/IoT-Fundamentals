/* Code for step motor (28BYJ-48) with Arduino without Stepper.h library*/
// Pins of step motor to Arduino
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Secuency of steps
int step [4][4] = {
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,0,0,1}
};

void setup() {
  // Setting pins in mode OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // loop for print steps in the motor
  for (int i = 0; i<4; i++) {
    // print steps
    digitalWrite(IN1, step[i][0]);
    digitalWrite(IN2, step[i][1]);
    digitalWrite(IN3, step[i][2]);
    digitalWrite(IN4, step[i][3]);
    delay(500);
  }
}
