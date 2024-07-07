#include <AccelStepper.h>

const int limitswitch1 = 11;
const int limitswitch2 = 12;
int nilai = 0;
int kecepatanrol;
int potPin = A0;                  // pin input dari potensiometer

AccelStepper stepper1(AccelStepper::DRIVER, 6, 5);
AccelStepper stepper2(AccelStepper::DRIVER, 10, 9);

void setup() {
  Serial.begin(9600);
  pinMode(limitswitch1, INPUT_PULLUP);
  pinMode(limitswitch2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);  // Button slider
  pinMode(4, INPUT_PULLUP);  // Button roller
  pinMode(28, OUTPUT);  // Led slider
  pinMode(29, OUTPUT);  // Led roller
  stepper1.setMaxSpeed(200);
  stepper2.setMaxSpeed(200);
}

void loop() {
  // SLIDER
  if (digitalRead(4) == LOW) {
  if (digitalRead(limitswitch1) == LOW) {
    nilai = 0;
    // Serial.println("Nilai: 0 (Switch 1 ditekan)");
    // delay(1000);
  } else if (digitalRead(limitswitch2) == LOW) {
    nilai = 1;
    // Serial.println("Nilai: 1 (Switch 2 ditekan)");
    // delay(1000);
  } else {
    // Serial.println("Tidak ada perubahan");
    // delay(1000);
  }
  // Serial.println(nilai);

    if (nilai == 0) {
    stepper1.setSpeed(100);  // Set kecepatan motor stepper1 (dalam langkah per detik)
    stepper1.runSpeed();    // Jalankan motor stepper1
    } else {
    stepper1.setSpeed(-100);  // Set kecepatan motor stepper1 (dalam langkah per detik)
    stepper1.runSpeed();    // Jalankan motor stepper1
    }
  } else {
    // Mematikan fungsi slider
    stepper1.setSpeed(0);  // Set kecepatan motor stepper1 (dalam langkah per detik)
    stepper1.runSpeed();    // Jalankan motor stepper1
    // stepper1.stop();  // Menghentikan motor stepper1
  }
  
  // ROLLER
  if (digitalRead(3) == LOW) {
    int potVal = analogRead(potPin);
    kecepatanrol = map(potVal, 511, 1024, 80, 30);
    // stepper2.setSpeed(100);  // Set kecepatan motor stepper2 (dalam langkah per detik)
    stepper2.setSpeed(kecepatanrol);  // Set kecepatan motor stepper2 (dalam langkah per detik)
    stepper2.runSpeed();    // Jalankan motor stepper2
  } else {
    stepper2.setSpeed(0);  // Set kecepatan motor stepper2 (dalam langkah per detik)
    stepper2.runSpeed();    // Jalankan motor stepper2
    stepper2.stop();  // Menghentikan motor stepper2
  }
    Serial.println(kecepatanrol);
}
