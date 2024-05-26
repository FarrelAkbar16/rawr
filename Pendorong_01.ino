void Pendorong() {

  if (Nexscrew == HIGH) { 
    digitalWrite(22, HIGH);
    
    


    analogWrite(rEnPin, 250);
    digitalWrite(rPwmPin, HIGH);
    digitalWrite(lPwmPin, LOW); 
   
    // if (setPoint == 0.00) {
    // digitalWrite(rPwmPin, LOW);
    // } else {
    // analogWrite(rPwmPin, kecepatanmot);
    // }
  } else {
    digitalWrite(22, LOW);
    // stop the motor moving
    analogWrite(rEnPin, 0);
    digitalWrite(rPwmPin, LOW);
    digitalWrite(lPwmPin, LOW);
    

  }
}