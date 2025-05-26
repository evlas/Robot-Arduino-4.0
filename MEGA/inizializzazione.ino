void mower_setup() {
  Init_Serial();
  Init_Serial_1();
  Init_Serial_2();
  Init_I2C();
  Init_Ina226();
  Load_EEPROM();
  Init_RTC();
  Init_Mower();
}

void Init_Serial() {
  Serial.begin(115200);

  Serial.println(" ");
  Serial.println(" ");
  Serial.print(F("Robot Tagliaerba Arduino :"));
  Serial.println(Version);
  Serial.println(F("==================="));
  Serial.println("");
  Serial.println(F("Avvio della configurazione del tosaerba"));
  Serial.println(F("==================="));
}

void Init_Serial_1() {
  if (NANO_Serial == true) Serial1.begin(1200);  // Aprire la porta seriale 1 per la comunicazione nano
}

void Init_Serial_2() {
  if (WIFI_Enabled == true) Serial2.begin(9600);  // Se il Wi-Fi è attivo prepara la porta seriale 2 aperta per la comunicazione NodeMCU
}

void Init_I2C() {
  Wire.begin();  // avviare l'interfaccia I2C
}

void Init_Ina226() {
  ina226.init();

  /* Set Number of measurements for shunt and bus voltage which shall be averaged
    Mode *     * Number of samples
    AVERAGE_1            1 (default)
    AVERAGE_4            4
    AVERAGE_16          16
    AVERAGE_64          64
    AVERAGE_128        128
    AVERAGE_256        256
    AVERAGE_512        512
    AVERAGE_1024      1024*/

  //ina226.setAverage(AVERAGE_16); // choose mode and uncomment for change of default

  /* Set conversion time in microseconds
     One set of shunt and bus voltage conversion will take:
     number of samples to be averaged x conversion time x 2
 
       Mode *         * conversion time
     CONV_TIME_140          140 µs
     CONV_TIME_204          204 µs
     CONV_TIME_332          332 µs
     CONV_TIME_588          588 µs
     CONV_TIME_1100         1.1 ms (default)
     CONV_TIME_2116       2.116 ms
     CONV_TIME_4156       4.156 ms
     CONV_TIME_8244       8.244 ms  */

  //ina226.setConversionTime(CONV_TIME_1100); //choose conversion time and uncomment for change of default

  /* Set measure mode
    POWER_DOWN - INA226 switched off
    TRIGGERED  - measurement on demand
    CONTINUOUS  - continuous measurements (default)*/

  //ina226.setMeasureMode(CONTINUOUS); // choose mode and uncomment for change of default

  /* Set Resistor and Current Range
     if resistor is 5.0 mOhm, current range is up to 10.0 A
     default is 100 mOhm and about 1.3 A*/

  //ina226.setResistorRange(0.1, 1.3); // choose resistor 0.1 Ohm and gain range up to 1.3A

  /* If the current values delivered by the INA226 differ by a constant factor
     from values obtained with calibrated equipment you can define a correction factor.
     Correction factor = current delivered from calibrated equipment / current delivered by INA226*/

  //ina226.setCorrectionFactor(0.93);

  Serial.println("INA226 Current Sensor - Continuous");

  ina226.waitUntilConversionCompleted();  //if you comment this line the first data might be zero
}

void Load_EEPROM() {
  Load_EEPROM_Saved_Data();
}

void Init_RTC() {
  if (Set_Time == 1) {
    Serial.print(F("Setting Time"));
    Set_Time_On_RTC();
  }  // avviare l'interfaccia I2C
  DisplayTime();
  Serial.println("");
}

void Init_Mower() {
  Prepare_Mower_from_Settings();
  Setup_Run_LCD_Intro();
  Setup_Compass();
  delay(100);
  Setup_Relays();
  Setup_Motor_DX_Pins();
  Setup_Motor_SX_Pins();
  Setup_Motor_Pins();
  Setup_Tip_Safety();
  Setup_Membrane_Buttons();
  Setup_ADCMan();
  Setup_Check_Pattern_Mow();
  if (Bumper_Activate_Frnt == true) Setup_Bumper_Bar();
}


void Setup_Motor_DX_Pins() {                                  //Modifica per driver motori nuovi
  Serial.println(F("Setup Motor DX Pins"));
//  pinMode(IN1Pin, OUTPUT);
//  pinMode(IN2Pin, OUTPUT);
//  pinMode(ENAPin, OUTPUT);
}

void Setup_Motor_SX_Pins() {                                 //Modifica per driver motori nuovi
  Serial.println(F("Setup Motor SX Pins"));
//  pinMode(IN3Pin, OUTPUT);
//  pinMode(IN4Pin, OUTPUT);
//  pinMode(ENBPin, OUTPUT);
}

void Setup_Motor_Pins() {
  Serial.println(F("Setup Motor Pins"));
//  pinMode(L_EN, OUTPUT);
//  pinMode(R_EN, OUTPUT);
//  pinMode(RPWM, OUTPUT);
}



