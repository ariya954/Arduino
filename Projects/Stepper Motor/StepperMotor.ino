const int FULL_STEP = 1;
const int HALF_STEP = 2;

const int A = 7, B = 6, C = 5, D = 4;

const int TOTAL_STEPS_IN_FULL_STEP_MODE = 2038; //total steps in one round for full step drive
//28BYJ-48 Stepper Motor: for full step use 2038

void fullStepPulse (int thisStep) {
  switch (thisStep) {
      case 0:  // 1100
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
      break;
      case 1:  // 0110
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
      break;
      case 2:  //0011
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      break;
      case 3:  //1001
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
      break;
    }
}

void halfStepPulse (int thisStep) {
  switch (thisStep) {
      case 0:  // 1000
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
      break;
      case 1:  // 1100
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
      break;
      case 2:  // 0100
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
      break;
      case 3:  // 0110
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
      break;
      case 4:  // 0010
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
      break;
      case 5:  //0011
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
      break;
      case 6:  // 0001
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
      break;
      case 7:  //1001
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
      break;  
    }
}

void step (int steps, int drive, double rpm) {
  int totalSteps =  TOTAL_STEPS_IN_FULL_STEP_MODE;
  if (drive == HALF_STEP) totalSteps = TOTAL_STEPS_IN_FULL_STEP_MODE*2;
  
  double stepDelay = (60L*1000L*1000L / (totalSteps * rpm)); 

  int stepsLeft = abs(steps);
  int direction = 0;
  if (steps > 0) direction = 1;
  else if (steps < 0) direction = -1;
  int stepNum = 0;
  unsigned long lastStepTime = micros();
  
  while (stepsLeft > 0) {
    unsigned long now = micros();    
    if (now - lastStepTime >= stepDelay)
    {
      lastStepTime = now;

      if (direction == 1) {
        if (stepNum == totalSteps)
          stepNum = 0;
      }
      else
        if (stepNum == 0)
          stepNum = totalSteps;
  
      stepNum += direction;
      stepsLeft--;

      if (drive == FULL_STEP)
        fullStepPulse(stepNum % 4);
      else if (drive == HALF_STEP)
        halfStepPulse(stepNum % 8);
    }
  }
}

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

}

void loop() {
  
  step(-TOTAL_STEPS_IN_FULL_STEP_MODE/2, HALF_STEP, 13);
  delay(1000);
}
