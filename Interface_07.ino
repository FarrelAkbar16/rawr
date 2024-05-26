void Interface(){
  if (Nexinterface==HIGH){
  Serial.print("t1.txt=\"");
  Serial.print(random(0,100));
  Serial.print("\"");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  Serial.print("t3.txt=\"");
  Serial.print(random(0,100));
  Serial.print("\"");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);


}
}