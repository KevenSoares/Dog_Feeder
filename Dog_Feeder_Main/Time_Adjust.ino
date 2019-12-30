void time_adjust()
{
  if(digitalRead(bot) == LOW)
  {
    while(digitalRead(bot) == LOW);
    if(h>=24)
    {
      h=0;
    }
    else
    {
      h++;
    }
  }
  if(digitalRead(bot2) == LOW)
  {
    while(digitalRead(bot2) == LOW);
    if(m>=59)
    {
      m=0;
    }
    else
    {
      m++;
    }
  }
}
