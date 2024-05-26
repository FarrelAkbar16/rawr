void Penarik(){
    if (Nexpuller == HIGH) {
    digitalWrite(25, HIGH);
    // baca nilai potensiometer
    if (usePotentiometer) {
      int potVal = analogRead(potPin);
      kecepatanmot = map(potVal, 0, 1024, 10, 250);
      setPoint = map(potVal, 0, 1024, 0, 104); // Menggunakan nilai dari potensiometer
      pwm1 = setPoint;
      // Menangani kasus khusus saat slider berada di titik nol
      if (potVal == 0) {
      setPoint = 0.0; // Set nilai setPoint menjadi 0.0
    }
    }
  
    if (setPoint == 0.00) {
    digitalWrite(motorPin, LOW);
    } else {
    analogWrite(motorPin, pwm1);
    }

    // perhitungan rpm
    //unsigned long currentMillis = millis();
    //if (currentMillis - previousMillis >= interval) {
    //previousMillis = currentMillis;
    //float time_elapsed = (float)interval / 1000.0;                                          // convert interval to seconds
    //rot_speed = (((float)currentEncoder - (float)previousEncoder) * 60 / (float)ppr) * GR;  // Gear ratio applied to motor speed
    //speed_mps = (wheelDiameter * pi) * rot_speed  / 60;    
    //previousEncoder = currentEncoder;
    //new_rot_speed = rot_speed;
    //error = setPoint - new_rot_speed;
    //}

    //integral += error * dt;
  //  derivative = (error - prevError) / dt;
    //PID = (kp * error) + (ki * integral) + (kd * derivative);
    //prevError = error;
    //PID = min(max(PID, 0.0), 255.0);
    //pwm1 = (int)((1.8048 * PID) + 6.1615);
    //old_rot_speed = new_rot_speed;
    
     Serial.print("Potensio/setpoint:");
     Serial.print(setPoint);
    // Serial.print(",");
    // Serial.print("RPM:");
    // Serial.print(rot_speed);
     //Serial.print(" ");
    // Serial.print(error);
    // Serial.print("%");
  
  } else {
    digitalWrite(25, LOW);
    digitalWrite(motorPin, LOW);
  }
  setpointval = setPoint;
  rotspeedval = rot_speed;
  }
