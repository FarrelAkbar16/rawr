void Kipas(){
  // FAN 1
  
  if (digitalRead(48) == LOW || Nexfan1 == HIGH) {
    digitalWrite(24, HIGH);
    digitalWrite(Fan1, LOW);
  } else {
    digitalWrite(24, LOW);
    digitalWrite(Fan1, HIGH);
  
  }

  // FAN 2
  if (digitalRead(51) == LOW || Nexfan2 == HIGH) {
    digitalWrite(26, HIGH);
    digitalWrite(Fan2, LOW);
  } else {
    digitalWrite(26, LOW);
    digitalWrite(Fan2, HIGH);
  }
}