void Penggulung(){
  // SLIDER
  if (digitalRead(52) == LOW || Nexslider == HIGH) {
  digitalWrite(28, HIGH);
  // Serial.println("Slider aktif");
    digitalWrite(Slider, LOW);
  } else {
    digitalWrite(28, LOW);
    // Mematikan fungsi slider
    digitalWrite(Slider, HIGH);
  }

  // ROLLER
  if (digitalRead(53) == LOW || Nexroller == LOW) {
  digitalWrite(29, HIGH);
    // Serial.println("Roller aktif");
    digitalWrite(Roller, LOW);
  } else {
    digitalWrite(29, LOW);
    digitalWrite(Roller, LOW);
  }
}