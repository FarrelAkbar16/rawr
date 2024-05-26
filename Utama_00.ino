#include <max6675.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define Fan1  15
#define Heater1 17
#define Heater2 16
#define Water 18
#define Fansupport 19
#define motorPin 9
#define Fan2 14 
#define Slider 31
#define Roller 30 




float diameterval = 0.0;
float setpointval = 0.0;

int Nexscrew = LOW; // Variable untuk menyimpan status dari Node-RED
int Nexheater = LOW; // Variable untuk menyimpan status dari Node-RED
int Nexfan1 = LOW; // Variable untuk menyimpan status dari Node-RED
int Nexpuller = LOW; // Variable untuk menyimpan status dari Node-RED
int Nexwater = LOW; // Variable untuk menyimpan status dari Node-RED
int Nexfan2 = LOW; // Variable untuk menyimpan status dari Node-RED
int Nexslider = LOW; 
int Nexroller= LOW;
int Nexinterface = LOW;
//float Num_read;

// deklarasi node-red
//bool Nodescrew = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Nodeheater = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Nodefan1 = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Nodepuller = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Nodewater = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Nodefan2 = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Nodeslider = LOW; // Variable untuk menyimpan status dari Node-RED
//bool Noderoller= LOW; // Variable untuk menyimpan status dari Node-RED
// deklarasi node-red

//---Motor Screw--//
int rEnPin = 12;    // Pin R_EN BTS 6790
int rPwmPin = 11;   // Pin RPWM BTS 6790
//int lEnPin = 12;    // Pin L_EN BTS 6790
int lPwmPin = 10;   // Pin LPWM BTS 6790
//---Motor Screw--//

//---Suhu Temp---//
//Sensor MAX6675 1
int thermoDO = 40; //so
int thermoCS = 41; 
int thermoCLK = 42; //sck

//Sensor MAX6675 2
int thermoDO2 = 43;
int thermoCS2= 44;
int thermoCLK2 = 45;


double suhutotal;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
MAX6675 thermocouple2(thermoCLK2, thermoCS2, thermoDO2);

double suhuval1;
double suhuval2;

//---Suhu Temp---//

//---Puller---//
int potPin = A0;                  // pin input dari 
byte speedMotor = 2;              // variabel untuk menyimpan nilai pembacaan potensiometer
float setPoint ;                   // variabel untuk menyimpan nilai pembacaan potensiometer
const int encoderPin = 2;         // pin untuk input encoder hall
unsigned long previousEncoder = 0;
unsigned long currentEncoder;
float kecepatanmot;
bool usePotentiometer = true; // Flag untuk menentukan penggunaan nilai potensiometer atau Node-RED

const int ppr = 21;               //define number of pulses in one round of encoder
const float GR = 1 / 28.0;        //gear ratio
const float wheelDiameter = 11.6;  // diameter roda dalam meter
const float pi = 3.14159;         // nilai pi
float new_rot_speed = 0.0;
float old_rot_speed = 0.0;
float rot_speed = 0.0;
float speed_mps = 0.0;             //speed in meter per second
float rotspeedval = 0.0;             //rotating speed in rad/s
float error;                       // variabel untuk menyimpan nilai error antara setpoint dan rotasi speed
unsigned long previousMillis = 0;  // variabel untuk menyimpan waktu sebelumnya
const int interval = 1000;  // interval waktu dalam milidetik

//PID
// float kp = 0.3718;
float kp = 0.5;
float ki = kp * 0.8; 
float kd = kp * 0; // not necessary
float dt = 1;
float prevError;
float integral;
float derivative;
float PID;
float pwm1;

void countPulse() {
  currentEncoder++;
  // Serial.println(currentEncoder);
}
//---Puller---//

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup() {
  //start serial connection
  Serial.begin(9600);
  // initialize the lcd
  lcd.init(); 
  lcd.backlight();
  pinMode(Nexscrew, INPUT); 
  pinMode(Nexheater, INPUT); 
  pinMode(Nexfan1, INPUT); 
  pinMode(Nexpuller, INPUT);
  pinMode(Nexwater, INPUT); 
  pinMode(Nexfan2, INPUT); 
  pinMode(Nexslider, INPUT);
  pinMode(Nexroller, INPUT);
  pinMode(Nexinterface, INPUT);
  attachInterrupt()

  pinMode(46, INPUT_PULLUP);  // Button screw
  pinMode(47, INPUT_PULLUP);  // Button heater
  pinMode(48, INPUT_PULLUP);  // Button fan 1
  pinMode(49, INPUT_PULLUP);  // Button puller
  pinMode(50, INPUT_PULLUP);  // Button fan 2
  pinMode(51, INPUT_PULLUP);  // Button water pump
  pinMode(52, INPUT_PULLUP);  // Button slider
  pinMode(53, INPUT_PULLUP);  // Button roller
  pinMode(22, OUTPUT);  // Led screw
  pinMode(23, OUTPUT);  // Led heater
  pinMode(24, OUTPUT);  // Led fan 1
  pinMode(25, OUTPUT);  // Led puller
  pinMode(27, OUTPUT);  // Led fan 2
  pinMode(26, OUTPUT);  // Led water pump
  pinMode(28, OUTPUT);  // Led slider
  pinMode(29, OUTPUT);  // Led roller
  pinMode(Fan2, OUTPUT); 
  pinMode(Fan1, OUTPUT);
  pinMode(Heater1, OUTPUT);
  pinMode(Heater2, OUTPUT);
  pinMode(Water, OUTPUT);
  pinMode(Fansupport, OUTPUT);
  pinMode(motorPin, OUTPUT); 
  pinMode(Slider, OUTPUT);
  pinMode(Roller, OUTPUT); 
  // motor screw 
  //pinMode(rEnPin, OUTPUT);
  pinMode(rPwmPin, OUTPUT);
  pinMode(lPwmPin, OUTPUT);
  pinMode(rEnPin, OUTPUT);
  //pinMode(lEnPin, OUTPUT);
  //digitalWrite(rEnPin, LOW);
  //digitalWrite(lEnPin, LOW);
  // LCD
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("FILAMENT");
  lcd.setCursor(4, 1);
  lcd.print("EXTRUDER");
  // wait for MAX chip to stabilize
  delay(1000);
  pinMode(encoderPin, INPUT_PULLUP);                                       // set pin sebagai input dengan pullup resistor
  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);  // mengaktifkan interrupt pada naiknya
  previousEncoder = 0; // Inisialisasi previousEncoder
}

void loop(){
  
  Pendorong();
  Pemanas1();
  Pemanas2();
  Kipas();
  Penarik();
  Airpump();
  Penggulung();
  Nextion();
  Interface();
  
}
