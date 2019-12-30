void light()
{
      int sensorValue = analogRead(A0);
      float voltage = sensorValue * (5.0 / 1023.0);
      if(voltage >= 3)
      {
        digitalWrite(led,HIGH);
      }
      else
      {
        digitalWrite(led,LOW);
      }
}
