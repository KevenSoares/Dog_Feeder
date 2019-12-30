#include <LiquidCrystal.h>
#include <Servo.h> 
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(27, 29, 31);
Servo myservo;
int h = 0;
int m = 0;
int i = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int bot = 22;
int bot2 = 24;
int bot3 = 26;
int led = 10;
int buzzer = 9;
const int trigPin = 17;
const int echoPin = 18;
const int trigPin2 = 19;
const int echoPin2 = 20;
char rele = 21;
int ledg = 14;
int ledy = 15;
int ledr = 16;

void setup()  
{
    
 lcd.begin(16, 2);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(rele,OUTPUT);
 pinMode(bot , INPUT_PULLUP);
 pinMode(bot2 , INPUT_PULLUP);
 pinMode(bot3 ,INPUT_PULLUP); 
 pinMode(led,OUTPUT);
 pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  myRTC.setDS1302Time(00, 00, 00, 6, 10, 1, 2014);
  myservo.attach(13);
}

void loop()  {                                                                                           
  myservo.write(0);
  lcd.setCursor(0,0);
  lcd.print("INTERVALO:");
  lcd.setCursor(0,1);
  lcd.print("1-H:");
  lcd.print(h);
  lcd.print(" ");
  lcd.print("2-M:");
  lcd.print(m);
  lcd.print(" 3-ok");
  lcd.print("        ");
  time_adjust();
  if(digitalRead(bot3)==LOW)
  {
    int sensorValue = analogRead(A0);
    lcd.setCursor(0,0);
    lcd.print("TEMPO DECORRIDO:   ");
    i =1;
    myservo.write(90);
    delay(2000);
    myservo.write(0);
    while(digitalRead(bot3)==LOW);
    while(i = 1)
    {
      light();
      distance();
      myRTC.updateTime();  
      lcd.setCursor(0,1);
      lcd.print(ArrumaZero(myRTC.hours));
      lcd.print(":");
      lcd.print(ArrumaZero(myRTC.minutes));
      lcd.print(":");
      lcd.print(ArrumaZero(myRTC.seconds));
      lcd.print("        ");
      if(myRTC.hours >= h && myRTC.minutes >= m && myRTC.seconds >= 0)
      {
        myRTC.setDS1302Time(00, 00, 00, 6, 10, 1, 2014);
        myservo.write(90);
        digitalWrite(buzzer,HIGH);
        delay(2000);
        myservo.write(0);
        digitalWrite(buzzer,LOW);
      }
    }
  }
}

      
    
      
  
