int d_red = 2;
int d_green = 3;
int r_red = 4;
int r_green = 5;
int l_red = 6;
int l_green = 7;
int u_red = 8;
int u_green = 9;

// IR sensor pins
int irSensor1 = A0;  // Adjust the pin according to your setup
int irSensor2 = A1;  // Adjust the pin according to your setup
int irSensor3 = A2;  // Adjust the pin according to your setup
int irSensor4 = A3;  // Adjust the pin according to your setup

// Define constants for timing
const int LIGHT_DURATION = 30000;  // 15 seconds
const int INTER_SENSOR_DELAY = 500; // Delay between turning off green and resuming regular sequence

void setup() {
  pinMode(d_red, OUTPUT);
  pinMode(d_green, OUTPUT);
  pinMode(r_red, OUTPUT);
  pinMode(r_green, OUTPUT);
  pinMode(l_red, OUTPUT);
  pinMode(l_green, OUTPUT);
  pinMode(u_red, OUTPUT);
  pinMode(u_green, OUTPUT);

  // IR sensor pins set as INPUT
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
}

void loop() {
  changeLights();
}

void changeLights() {
  // Check if any IR sensor detects an object
  if (digitalRead(irSensor1) == LOW) {
    // Activate green light for 15 seconds if an object is detected
    digitalWrite(u_green, HIGH);
    digitalWrite(u_red, LOW);
    digitalWrite(r_red, HIGH);
    digitalWrite(d_red, HIGH);
    digitalWrite(l_red, HIGH);

    digitalWrite(r_green, LOW);
    digitalWrite(d_green, LOW);
    digitalWrite(l_green, LOW);
    delay(LIGHT_DURATION);
    
    // Turn off green light
    digitalWrite(u_green, LOW);
    // digitalWrite(u_red, HIGH);
    // digitalWrite(r_red, LOW);
    // digitalWrite(d_red, LOW);
    // digitalWrite(l_red, LOW);

    delay(500);
    // Resume regular sequence
    regularTrafficLightSequence();
  } 
  
   else if (digitalRead(irSensor2) == LOW){
    // Activate green light for 15 seconds if an object is detected
    digitalWrite(r_green, HIGH);
    digitalWrite(u_red, HIGH);
    digitalWrite(r_red, LOW);
    digitalWrite(d_red, HIGH);
    digitalWrite(l_red, HIGH);

    digitalWrite(u_green, LOW);
    digitalWrite(d_green, LOW);
    digitalWrite(l_green, LOW);
    delay(LIGHT_DURATION);

    // Turn off green light
    digitalWrite(r_green, LOW);
    // digitalWrite(u_red, LOW);
    // digitalWrite(r_red, HIGH);
    // digitalWrite(d_red, LOW);
    // digitalWrite(l_red, LOW);

    delay(500);

    // Resume regular sequence
    regularTrafficLightSequence();
  }

  else if (digitalRead(irSensor3) == LOW){
    // Activate green light for 15 seconds if an object is detected
    digitalWrite(d_green, HIGH);
    digitalWrite(u_red, HIGH);
    digitalWrite(r_red, HIGH);
    digitalWrite(d_red, LOW);
    digitalWrite(l_red, HIGH);

    digitalWrite(u_green, LOW);
    digitalWrite(r_green, LOW);
    digitalWrite(l_green, LOW);
    delay(LIGHT_DURATION);

    // Turn off green light
    digitalWrite(d_green, LOW);
    // digitalWrite(u_red, LOW);
    // digitalWrite(r_red, LOW);
    // digitalWrite(d_red, HIGH);
    // digitalWrite(l_red, LOW);

    delay(500);

    // Resume regular sequence
    regularTrafficLightSequence();
  }

  else if (digitalRead(irSensor4) == LOW){
    // Activate green light for 15 seconds if an object is detected
    digitalWrite(l_green, HIGH);
    digitalWrite(u_red, HIGH);
    digitalWrite(r_red, HIGH);
    digitalWrite(d_red, HIGH);
    digitalWrite(l_red, LOW);

    digitalWrite(d_green, LOW);
    digitalWrite(r_green, LOW);
    digitalWrite(u_green, LOW);
    delay(LIGHT_DURATION);

    // Turn off green light
    digitalWrite(l_green, LOW);
    // digitalWrite(u_red, LOW);
    // digitalWrite(r_red, LOW);
    // digitalWrite(d_red, LOW);
    // digitalWrite(l_red, HIGH);

    delay(500);
    regularTrafficLightSequence();
    // Resume regular sequence
  }
  else {
    // If no object is detected, continue with the regular traffic light sequence
    regularTrafficLightSequence();
  }
}


// Function for regular traffic light sequence
void regularTrafficLightSequence() {
  // Red lights for all directions
  digitalWrite(u_red, HIGH);
  digitalWrite(d_red, HIGH);
  digitalWrite(r_red, HIGH);
  digitalWrite(l_green, LOW);
  delay(500);

  // Upper lane go
  digitalWrite(u_green, HIGH);
  digitalWrite(u_red, LOW);
  digitalWrite(r_red, HIGH);
  digitalWrite(l_red, HIGH);
  digitalWrite(d_red, HIGH);
  delay(5000);

  // All yellow
  digitalWrite(u_green, LOW);
  digitalWrite(r_red, LOW);
  digitalWrite(l_red, LOW);
  digitalWrite(d_red, LOW);
  delay(500);

  // Right lane go
  digitalWrite(u_red, HIGH);
  digitalWrite(l_red, HIGH);
  digitalWrite(d_red, HIGH);
  digitalWrite(r_green, HIGH);
  digitalWrite(r_red, LOW);
  delay(5000);

  // All yellow on
  digitalWrite(u_red, LOW);
  digitalWrite(l_red, LOW);
  digitalWrite(d_red, LOW);
  digitalWrite(r_green, LOW);
  delay(500);

  // Down lane go
  digitalWrite(u_red, HIGH);
  digitalWrite(l_red, HIGH);
  digitalWrite(r_red, HIGH);
  digitalWrite(d_green, HIGH);
  digitalWrite(d_red, LOW);
  delay(5000);

  // All yellow
  digitalWrite(u_red, LOW);
  digitalWrite(l_red, LOW);
  digitalWrite(r_red, LOW);
  digitalWrite(d_green, LOW);
  delay(500);

  // Left lane go
  digitalWrite(u_red, HIGH);
  digitalWrite(d_red, HIGH);
  digitalWrite(r_red, HIGH);
  digitalWrite(l_green, HIGH);
  digitalWrite(l_red, LOW);
  
  delay(5000);
}
