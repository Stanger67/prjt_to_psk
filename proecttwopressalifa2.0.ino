

 #include <Wire.h>
 #include <Rtc_Pcf8563.h>
 #include <LiquidCrystal.h> 
 #include "pwrl.h"
 //объявление объекта для работы с энкодером

LiquidCrystal lcd(8, 7, 2, 3, 4, 5); // rs, e,d4, d5, d6, d7
Rtc_Pcf8563 rtc;


void br(){
    if (digitalRead(BUT1) == HIGH)
    {
        BOSSOFTHEGYM = BOSSOFTHEGYM;
        delay(500);
        Serial.println(BOSSOFTHEGYM);
    }

    rtc.getTime(); //получение времени с часов
    byte hour = rtc.getHour(); //запись в переменную количество часов
    byte minute = rtc.getMinute();
    byte second = rtc.getSecond ();

    if (hour == v1 && minute == d1 && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
    }
    if (hour == s2 && minute == sas2 && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
    }
    if (hour == sass3 && minute == minute3 && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
   }  
}

void setup() 
    {
    Serial.begin(9600);
    lcd.begin (16, 2);
    pinMode (LED, OUTPUT);
    pinMode (BUT1 , INPUT);
    
    degree = servoDrive.read();
    }

void loop() 
    {
    //br() ;
    digitalWrite(LED, digitalRead(BUT1));
    if (h>=2)
        {
            rtc.initClock();//часы
/*            rtc.setDate (9, 2, 10, 0, 21); // месяц3, неделя1, день2, год4*/
            rtc.setTime(f, c, 0);
        }
    lcd.home();
    lcd.print (rtc.formatTime());//часы
    lcd.setCursor(0, 1);
   
    if (digitalRead(BUT3)== HIGH)
    {//включение
        h  = h + 1;
//      Serial.println(h);
        delay(500);
    } //включение кнопок в код
    lcd.setCursor(12, 0);
    lcd.print(':');
    lcd.setCursor(3, 2);
    lcd.print (':');
    lcd.setCursor(7, 2);
    lcd.print (':');
    lcd.setCursor(12, 2);
    lcd.print (':');
    ncoderrr ();
    if (h > 2)
    {
        h = 0;
        delay (500);
//      Serial.println(h);
  }
}
void ncoderrr ()
    {
    lastButton = digitalRead(BUT); //чтение текущего положения кнопки
    long newPosition = myEnc.read(); //чтение новой позиции
    if (newPosition != oldPosition) 
    { //если она отлична от старой
        if (oldPosition != -999)
        { //начальная позиция не интересует
            if (BOSSOFTHEGYM >= 1)
            {
                if (BOSSOFTHEGYM == 1 )
                {
                    v1 = newPosition - oldPosition + v1;
                    v1 = abs(v1);
                    lcd.setCursor (0, 2);
                    lcd.print (v1);
                    if (v1 >= 23)
                    {
                        v1 = 0;
                    }
               }
               if (BOSSOFTHEGYM == 2 )
                   {
                       d1 = newPosition - oldPosition + d1;
                       d1 = abs(d1);
                       lcd.setCursor (3, 2);
                       lcd.print (d1);
                       if (d1 >= 59)
                       {
                           d1 = 0;
                       }
                  }
               if (BOSSOFTHEGYM == 3 )
               {
                   s2 = newPosition - oldPosition + s2;
                   s2 = abs(s2);
                   lcd.setCursor (5, 2);
                   lcd.print (s2);
                   if (s2 >= 23)
                   {
                       s2 = 0;
                   }
              }
              if (BOSSOFTHEGYM == 4 )
              {
                  sas2 = newPosition - oldPosition + sas2;
                  sas2 = abs(sas2);
                  lcd.setCursor (8, 2);
                  lcd.print (sas2);
                  if (v1 >= 59)
                  {
                      v1 = 0;
                  }
             }
             if (BOSSOFTHEGYM == 5 )
             {
                 sass3 = newPosition - oldPosition + sass3;
                 sass3 = abs(sass3);
                 lcd.setCursor (11, 2);
                 lcd.print (sass3);
                 if (sass3 >= 23)
            {
            v1 = 0;
        }
      }
      if (BOSSOFTHEGYM == 6 )
      {
        minute3 = newPosition - oldPosition + minute3;
        minute3 = abs(minute3);
        lcd.setCursor (14, 2);
        lcd.print (minute3);
        if (minute3 >= 59)
        {
            minute3 = 0;
        }
      }      
    }
            }
    if (BOSSOFTHEGYM <= 1) { 
    if (h == 0){
    f = newPosition - oldPosition + f;
    f = abs(f);
    lcd.setCursor (10, 0);
    lcd.print (f);
    if (f >= 23)
     {
            f = 0;
     }
    }
     if (h == 1){
     c = newPosition - oldPosition + c;
     c = abs(c);
     lcd.setCursor (13, 0);
     lcd.print (c);
     if (c >= 59)
     {
            c = 0;
     }     
    }    
    }
        }
    oldPosition = newPosition; //запомнить новую позицию
 }
}
