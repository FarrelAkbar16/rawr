void Airpump(){
  if (digitalRead(50) == LOW || Nexwater == HIGH)  {
    digitalWrite(27, HIGH);
    digitalWrite(Water, LOW);
  } else {
    digitalWrite(27, LOW);
    digitalWrite(Water, HIGH);
  }
}