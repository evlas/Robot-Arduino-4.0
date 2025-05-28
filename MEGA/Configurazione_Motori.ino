void Motor_Action_Go_Mowing_Speed() {

  // No Mag speed adjustment active just go full speed
  if (MAG_Speed_Adjustment == 0) Motor_Action_Go_Full_Speed();

  // Adjust wheel speed according to the MAG level
  if (MAG_Speed_Adjustment == 1) {
    if (MAG_Now >= Slow_Speed_MAG) {
      Motor_Action_Go_Full_Speed();
    }

    if (MAG_Now < Slow_Speed_MAG) {
      Motor_Action_Go_Slow_Speed();
    }
  }
}

void Motor_Action_Go_Full_Speed() {
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(PWM_MaxSpeed_RH);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(PWM_MaxSpeed_LH);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, PWM_MaxSpeed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(ENBPin, PWM_MaxSpeed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, PWM_MaxSpeed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, PWM_MaxSpeed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("Wheel:FULL|"));
}

void Motor_Action_Go_Slow_Speed() {
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(PWM_Slow_Speed_RH);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(PWM_Slow_Speed_LH);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, PWM_Slow_Speed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(ENBPin, PWM_Slow_Speed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, PWM_Slow_Speed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, PWM_Slow_Speed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("Wheel:SLOW|"));
}

void Motor_Action_Max_Slow_Speed() {
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(PWM_Max_Slow_Speed_RH);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(PWM_Max_Slow_Speed_LH);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, PWM_Max_Slow_Speed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(ENBPin, PWM_Max_Slow_Speed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, PWM_Max_Slow_Speed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, PWM_Max_Slow_Speed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("Wheel:SLOW|"));
}

void Motor_Action_Go_Accel() {
  for (int i = 0; i < 255; i++) {
#ifdef I2C_MOTORS
    Wire.beginTransmission(ADDR_DX_MOTOR);
    Wire.write(i);
    Wire.endTransmission();
    Wire.beginTransmission(ADDR_SX_MOTOR);
    Wire.write(i);
    Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
    analogWrite(ENAPin, i);
    analogWrite(ENBPin, i);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, i);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, i);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
    delay(2);  // Prima impostato a 3
  }
}

void Motor_Action_Go_Track_Speed() {
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(PWM_TrackSpeed_RH);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(PWM_TrackSpeed_LH);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, PWM_TrackSpeed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(ENBPin, PWM_TrackSpeed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, PWM_TrackSpeed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, PWM_TrackSpeed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("Wheel:TRACK|"));
}

void Motor_Action_GoFullSpeed_Out_Garage() {
  //Speeds can be changed to give the mower a slight curve when exiting the Garage.
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(PWM_Max_Slow_Speed_RH);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(PWM_Max_Slow_Speed_LH);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, PWM_Max_Slow_Speed_RH);  // Velocità lenta
  analogWrite(ENBPin, PWM_Max_Slow_Speed_LH);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, PWM_Max_Slow_Speed_RH);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, PWM_Max_Slow_Speed_LH);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("Wheel:SLOW|"));
}

// USed to turn the mower at a set speed.
void Motor_Action_Turn_Speed() {
  if ((Accel_Speed_Adjustment == 0)) {
#ifdef I2C_MOTORS
    Wire.beginTransmission(ADDR_DX_MOTOR);
    Wire.write((PWM_MaxSpeed_RH - Turn_Adjust));
    Wire.endTransmission();
    Wire.beginTransmission(ADDR_SX_MOTOR);
    Wire.write((PWM_MaxSpeed_LH - Turn_Adjust));
    Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
    analogWrite(ENAPin, (PWM_MaxSpeed_RH - Turn_Adjust));  // Cambia il valore 0 in 10 o 20 per ridurre la velocità
    analogWrite(ENBPin, (PWM_MaxSpeed_LH - Turn_Adjust));  // Cambia il valore 0 in 10 o 20 per ridurre la velocità
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, (PWM_MaxSpeed_RH - Turn_Adjust));  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, (PWM_MaxSpeed_LH - Turn_Adjust));  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  }

  if ((Accel_Speed_Adjustment == 1)) {
    Motor_Action_Go_Accel();
  }
}

void SetPins_ToGoForwards() {
#ifdef I2C_MOTORS
  char msg[2];
  msg[0] = 0;  //speed
  msg[1] = 1;  //direction
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(msg, sizeof(msg));
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(msg, sizeof(msg));
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  digitalWrite(IN1Pin, LOW);  // I pin del driver motore sono impostati su alto o basso per impostare la direzione del movimento
  digitalWrite(IN2Pin, HIGH);
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, HIGH);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  digitalWrite(DirDXPin, LOW);
  digitalWrite(DirSXPin, HIGH);
#endif
  Serial.print(F("Wheel:For|"));
}

void SetPins_ToGoBackwards() {  // I pin del driver motore sono impostati per consentire a entrambi i motori di spostarsi indietro.
#ifdef I2C_MOTORS
  char msg[2];
  msg[0] = 0;  //speed
  msg[1] = 0;  //direction
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(msg, sizeof(msg));
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(msg, sizeof(msg));
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  digitalWrite(IN1Pin, HIGH);  // Motor 1
  digitalWrite(IN2Pin, LOW);
  digitalWrite(IN3Pin, HIGH);  // Motor 2
  digitalWrite(IN4Pin, LOW);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  digitalWrite(DirDXPin, HIGH);
  digitalWrite(DirSXPin, LOW);
#endif
  Serial.print(F("Wheel:Rev|"));
  delay(20);
}

void Motor_Action_Stop_Motors() {  // I pin del driver motore sono impostati per consentire a entrambi i motori di stopparsi.
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(0);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  digitalWrite(ENAPin, 0);
  digitalWrite(IN1Pin, LOW);  //Motor 1
  digitalWrite(IN2Pin, LOW);

  digitalWrite(ENBPin, 0);  //Motor 2
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, LOW);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, 0);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, 0);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("Wheel:0FF|"));
}

void SetPins_ToTurnLeft() {  // I pin sono impostati in modo che i motori girino in direzioni opposte
#ifdef I2C_MOTORS
  char msg1[2], msg2[2];
  msg1[0] = 0;  //speed
  msg1[1] = 1;  //direction
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(msg1, sizeof(msg1));
  Wire.endTransmission();
  msg2[0] = 0;  //speed
  msg2[1] = 0;  //direction
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(msg2, sizeof(msg2));
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  digitalWrite(IN1Pin, LOW);  // Motor 1
  digitalWrite(IN2Pin, HIGH);
  digitalWrite(IN3Pin, HIGH);  // Motor 2
  digitalWrite(IN4Pin, LOW);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  digitalWrite(DirDXPin, LOW);
  digitalWrite(DirSXPin, LOW);
#endif
  Serial.print(F("Wheel:TL_|"));
}

void SetPins_ToTurnRight() {  // I pin sono impostati in modo che i motori girino in direzioni opposte
#ifdef I2C_MOTORS
  char msg1[2], msg2[2];
  msg1[0] = 0;  //speed
  msg1[1] = 0;  //direction
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(msg1, sizeof(msg1));
  Wire.endTransmission();
  msg2[0] = 0;  //speed
  msg2[1] = 1;  //direction
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(msg2, sizeof(msg2));
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  digitalWrite(IN1Pin, HIGH);  // Motor 1
  digitalWrite(IN2Pin, LOW);
  digitalWrite(IN3Pin, LOW);  //Motor 2
  digitalWrite(IN4Pin, HIGH);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  digitalWrite(DirDXPin, HIGH);
  digitalWrite(DirSXPin, HIGH);
#endif
  Serial.print(F("Wheel:R|"));
}

// Turns the mowing blades on
void Motor_Action_Spin_Blades() {
  if (Cutting_Blades_Activate == 1) {  // Le lame sono accese nelle impostazioni e girano!
    delay(20);
#ifdef I2C_BLADES
    for (int i = 0; i++; i < NUM_BLADE) {
      Wire.beginTransmission(ADDR_BLADE_MOTOR + i);
      Wire.write(PWM_Blade_Speed);
      Wire.endTransmission();
    }
#endif
#ifdef BTS7960_BLADES
    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
    delay(20);
    analogWrite(RPWM, PWM_Blade_Speed);
#endif
#ifdef BRUSHLESS_TIPO1_BLADES
  digitalWrite(PwmBLPin, HIGH);
  analogWrite(PwmBLPin, PWM_Blade_Speed);
#endif
    delay(20);
    Serial.print(F("Blades:ON_|"));
  }

  if (Cutting_Blades_Activate == 0) {  // Le lame sono spente nelle impostazioni
    void StopSpinBlades();
  }
}

void Motor_Action_Stop_Spin_Blades() {
  delay(20);
#ifdef I2C_BLADES
  for (int i = 0; i++; i < NUM_BLADE) {
    Wire.beginTransmission(ADDR_BLADE_MOTOR + i);
    Wire.write(0);
    Wire.endTransmission();
  }
#endif
#ifdef BTS7960_BLADES
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
#endif
#ifdef BRUSHLESS_TIPO1_BLADES
  analogWrite(PwmBLPin, 0);
#endif
  delay(20);
  Serial.print(F("Blades:0FF|"));
}

//Sterza il tosaerba in base all'ingresso PID dell'algoritmo
void Motor_Action_Dynamic_PWM_Steering() {
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(PWM_Right);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(PWM_Left);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, PWM_Right);  // ENA low = Sterzata a destra   ENB low = Sterzata a sinistra
  analogWrite(ENBPin, PWM_Left);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, PWM_Right);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, PWM_Left);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("PWM_R:"));
  Serial.print(PWM_Right);
  Serial.print(F("|"));
  Serial.print(F("PWM_L:"));
  Serial.print(PWM_Left);
  Serial.print(F("|"));
}

float targetHeading = 90.0;  // Direzione desiderata in gradi (può essere aggiornata dopo ogni manovra)

// === PID BASSATO SULLA BUSSOLA ===
void Controllo_PID_Bussola(float headingAttuale) {
  static float pid_error = 0, pid_lastError = 0, pid_integral = 0, pid_derivative = 0;
  int baseSpeed = 150;

  pid_error = headingAttuale - targetHeading;
  if (pid_error > 180) pid_error -= 360;
  if (pid_error < -180) pid_error += 360;

  pid_integral += pid_error;
  pid_derivative = pid_error - pid_lastError;
  pid_lastError = pid_error;

  float correzione = Kp * pid_error + Ki * pid_integral + Kd * pid_derivative;

  int pwmLeft = constrain(baseSpeed - correzione, 0, 255);
  int pwmRight = constrain(baseSpeed + correzione, 0, 255);
#ifdef I2C_MOTORS
  Wire.beginTransmission(ADDR_DX_MOTOR);
  Wire.write(pwmRight);
  Wire.endTransmission();
  Wire.beginTransmission(ADDR_SX_MOTOR);
  Wire.write(pwmLeft);
  Wire.endTransmission();
#endif
#ifdef BTS7960_MOTORS
  analogWrite(ENAPin, pwmRight);
  analogWrite(ENBPin, pwmLeft);
#endif
#ifdef BRUSHLESS_TIPO1_MOTORS
  analogWrite(PwmDXPin, pwmRight);  // Velocità = 0-255  (255 è la velocità massima). La velocità è impostata nelle impostazioni
  analogWrite(PwmSXPin, pwmLeft);  // AnaolgWrite invia segnali PWM Velocità = 0-255  (255 è la velocità massima)
#endif
  Serial.print(F("PID|H:"));
  Serial.print(headingAttuale);
  Serial.print(F("|Err:"));
  Serial.println(pid_error);
}
