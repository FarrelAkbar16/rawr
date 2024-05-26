
void Nextion() {
  if (Serial.available()> 0) {
  String data = Serial.readString(); // membaca data dari port serial dan menyimpannya sebagai string
  
  if (data == "A") { // jika data "A", nyalakan screw
    Nexscrew = HIGH;
  } else if (data == "B") { // jika data "B", matikan screw
    Nexscrew = LOW;
  } else if (data == "C") { // jika data "C", nyalakan heater
    Nexheater = HIGH;
  } else if (data == "D") { // jika data "D", matikan heater
    Nexheater = LOW;
  } else if (data == "E") { // jika data "E", nyalakan fan 1
    Nexfan1 = HIGH;
  } else if (data == "F") { // jika data "F", matikan fan 1
    Nexfan1 = LOW;
  } else if (data == "G") { // jika data "G", nyalakan puller
    Nexpuller = HIGH;
  } else if (data == "H") { // jika data "H", matikan puller
    Nexpuller = LOW;
  } else if (data == "I") { // jika data "I", nyalakan water
    Nexwater = HIGH;
  } else if (data == "J") { // jika data "J", matikan water
    Nexwater = LOW;
  } else if (data == "K") { // jika data "K", nyalakan fan 2
    Nexfan2 = HIGH;
  } else if (data == "L") { // jika data "L", matikan fan 2
    Nexfan2 = LOW;
  } else if (data == "M") { // jika data "M", nyalakan roller
    Nexslider = HIGH;
  } else if (data == "N") { // jika data "N", matikan roller
    Nexslider = LOW;
  } else if (data == "O") { // jika data "O", nyalakan roller
    Nexroller = HIGH;
  } else if (data == "P") { // jika data "P", matikan roller
    Nexroller =LOW;
  } else if (data == "Q") {
    Nexinterface = HIGH;
  } else if (data == "R") {
    Nexinterface = LOW;
  }
Serial.println(Nexfan1);
Serial.println(Nexscrew);
  
 
  //Serial.println(data);
  }

}
