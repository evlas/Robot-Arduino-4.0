// Controllo per motore Brushless CM36-3650 e 42GP-4260 con Arduino Pro Mini

// Rosso   M+
// Nero    M-
// Bianco  DIR              pin 10
// Blu     PWM              pin  9
// Giallo  6pcs PPR         pin  2    6pcs PPR CM36-3650 - 12pcs PPR 42GP-4260

// A4(SDA), A5(SCL)

#define _DEBUG_
#define _MOTORE_SINISTRO_

//42GP-4260
#define PPR     12
#define REDUCTION_RATIO  185       //per 27 RPM

#define PERIOD 100 //100 msec

#include <Wire.h>

int pwmout = 9; 
int dirout = 10;
int encpin = 2; //interrupt

volatile unsigned int count; //Variabile di conteggio
char rpm = 0;
float lasttime = 0;
float currenttime = 0;

char speed = 0;
#ifdef _MOTORE_SINISTRO_
char direction = 1;   //differenziare tra destro e sinistro
#define i2c_addr 9
#else
char direction = 0;   //differenziare tra destro e sinistro
#define i2c_addr 8
#endif

void setup() 
{
  Wire.begin(i2c_addr);        // join i2c bus with address #8
  Wire.onReceive(receiveEvent);
  Wire.onRequest(sendEvent); // register event
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

#ifdef _DEBUG_
  Serial.begin(9600);   // start serial for output
#endif  
  // put your setup code here, to run once:
  analogWriteSAH_Init();
  pinMode(pwmout, OUTPUT);  // sets the pin as output
  pinMode(dirout, OUTPUT);

  pinMode(encpin, INPUT_PULLUP);
  attachInterrupt (0, count_pulse, RISING); //Configura interrupt 0 pin 2
  count = 0;
}

void loop() 
{
  // Periodically print and reset the count.
  static uint32_t last_time = 0;
  if (millis() - last_time >= PERIOD) {
    noInterrupts();
    unsigned int count_copy = count;
    count = 0;
    interrupts();
#ifdef _DEBUG_
    Serial.println("count: ");
    Serial.println(count_copy);
    int rpm_motore = count_copy/PPR;
    Serial.println("rpm motore: ");
    Serial.println(rpm_motore);
    int rpm_ruota = rpm_motore/REDUCTION_RATIO;
    Serial.println("rpm ruota: ");
    Serial.println(rpm_ruota);
#endif
    last_time += PERIOD;
    rpm = count_copy/PPR/REDUCTION_RATIO;
  }

  digitalWrite(dirout,direction);
  // put your main code here, to run repeatedly:
//  analogWrite(pwmout, map(speed, 0, 1023, 0, 255)); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWriteSAH(speed); //PIN 9 
#ifdef _DEBUG_
  Serial.print("8-bit PWM value : ");
  Serial.print(speed);
#endif
//  analogWrite(pwmout, map(speed, 0, 1023, 0, 4095));
//  Serial.print(" , 12-bit PWM value : ");
//  Serial.print(map(speed, 0, 1023, 0, 4095));

}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void receiveEvent(int c) 
{
  char msg[30] = "";

  if (c == 1) {
    speed = Wire.read();
#ifdef _DEBUG_
    Serial.println(speed);         // print the integer
#endif
  }

  if (c == 2) {
    for (int i = 0; i < c; i++)
    {
      msg[i] = Wire.read();
    }
#ifdef _DEBUG_
    Serial.println(msg);         // print the integer
#endif

    speed = msg[0];
#ifdef _DEBUG_
   Serial.println(speed);         // print the integer
#endif

#ifdef _MOTORE_SINISTRO_
    char dir_temp = msg[1];
    if (dir_temp == 1) direction = 0;
    else direction = 1;
#else
    direction = msg[1];
#endif
#ifdef _DEBUG_
    Serial.println(direction);         // print the integer
#endif
  }
}

void sendEvent()
{
  Wire.write(rpm);
}

void analogWriteSAH_Init( void )
{
  // Stop the timer while we muck with it

  TCCR1B = (0 << ICNC1) | (0 << ICES1) | (0 << WGM13) | (0 << WGM12) | (0 << CS12) | (0 << CS11) | (0 << CS10);
  
  // Set the timer to mode 14...
  //
  // Mode  WGM13  WGM12  WGM11  WGM10  Timer/Counter Mode of Operation  TOP   Update of OCR1x at TOV1  Flag Set on
  //              CTC1   PWM11  PWM10
  // ----  -----  -----  -----  -----  -------------------------------  ----  -----------------------  -----------
  // 14    1      1      1      0      Fast PWM                         ICR1  BOTTOM                   TOP
  
  // Set output on Channel A to...
  //
  // COM1A1  COM1A0  Description
  // ------  ------  -----------------------------------------------------------
  // 1       0       Clear OC1A/OC1B on Compare Match (Set output to low level).
  
  TCCR1A = 
      (1 << COM1A1) | (0 << COM1A0) |   // COM1A1, COM1A0 = 1, 0
      (0 << COM1B1) | (0 << COM1B0) | 
      (1 << WGM11) | (0 << WGM10);      // WGM11, WGM10 = 1, 0
  
  // Set TOP to...
  //
  // fclk_I/O = 16000000
  // N        = 1
  // TOP      = 799
  //
  // fOCnxPWM = fclk_I/O / (N * (1 + TOP))
  // fOCnxPWM = 16000000 / (1 * (1 + 799))
  // fOCnxPWM = 16000000 / 800
  // fOCnxPWM = 20000

  ICR1 = 799;
  
  // Ensure the first slope is complete

  TCNT1 = 0;
  
  // Ensure Channel B is irrelevant
  
  OCR1B = 0;
  
  // Ensure Channel A starts at zero / off
  
  OCR1A = 0;
  
  // We don't need no stinkin interrupts
  
  TIMSK1 = (0 << ICIE1) | (0 << OCIE1B) | (0 << OCIE1A) | (0 << TOIE1);

  // Ensure the Channel A pin is configured for output
  DDRB |= (1 << DDB1);

  // Start the timer...
  //
  // CS12  CS11  CS10  Description
  // ----  ----  ----  ------------------------
  // 0     0     1     clkI/O/1 (No prescaling)

  TCCR1B = 
      (0 << ICNC1) | (0 << ICES1) | 
      (1 << WGM13) | (1 << WGM12) |              // WGM13, WGM12 = 1, 1
      (0 << CS12) | (0 << CS11) | (1 << CS10);
}

void analogWriteSAH( uint16_t value )
{
  if ( (value >= 0) && (value < 800) )
  {
    OCR1A = value;
  }
}

void count_pulse()
{
    count++;
}