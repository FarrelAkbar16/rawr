void Pemanas1(){
  float suhu = 105;
  float suhuval1 = thermocouple.readCelsius();
  delay(200);
  if (Nexheater == HIGH) { 
    digitalWrite(23, HIGH);
    digitalWrite(Heater1, LOW);
    digitalWrite(Fansupport, HIGH);
    if (suhuval1 < suhu ) {
    // heater nyala
    digitalWrite(Heater1, LOW);
  } else {
    digitalWrite(Heater1, HIGH);
  }
  }else {
    digitalWrite(Heater1, HIGH);
    digitalWrite(Fansupport, LOW);
  }


//Serial.println(suhuval1);
}