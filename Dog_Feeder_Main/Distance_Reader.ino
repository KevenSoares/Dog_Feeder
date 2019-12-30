int distance()
{
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      unsigned long duracao = pulseIn(echoPin, HIGH);
      int distancia = duracao / 58;
      Serial.print(distancia);
      if(distancia <=9)
      {
        digitalWrite(ledg,HIGH);
        digitalWrite(ledy,LOW);
        digitalWrite(ledr,LOW);
      } 
       if(distancia >9 && distancia <=18 )
      {
        digitalWrite(ledg,LOW);
        digitalWrite(ledy,HIGH);
        digitalWrite(ledr,LOW);
      }
      if(distancia > 18)
      {
        digitalWrite(ledg,LOW);
        digitalWrite(ledy,LOW);
        digitalWrite(ledr,HIGH);
      }  
       
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      unsigned long duracao2 = pulseIn(echoPin2, HIGH);
      int distancia2 = duracao2 / 58;
      Serial.print("|");
      Serial.println(distancia2);
      if(distancia2>=25)
      {
        digitalWrite(rele,HIGH);
        delay(2000);
      }
      else
      {
        digitalWrite(rele,LOW);
      }
}
