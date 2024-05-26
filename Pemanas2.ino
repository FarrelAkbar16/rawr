void Pemanas2(){
  float suhu = 105;
  float suhuval2 = thermocouple2.readCelsius();
  delay(200);
  if (Nexheater == HIGH) { 
    digitalWrite(23, HIGH);
    digitalWrite(Heater2, LOW);
    digitalWrite(Fansupport, HIGH);
    if (suhuval2 < suhu) {
    // heater nyala
    digitalWrite(Heater2, LOW);
  } else {
    digitalWrite(Heater2, HIGH);
  }
  }else {
    digitalWrite(Heater2, HIGH);
    digitalWrite(Fansupport, LOW);
  }
  
}
