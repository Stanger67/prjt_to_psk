

 #include <Wire.h>
 #include <Rtc_Pcf856.h>
  
 #include "pwrl.h"
#include <L>
 
 //объявление объекта для работы с энкодером

LiquidCrystal lcd(8, 7, 2, 3, 4,5); // rs, e,d4, d5, d6, d7



void index.br(){
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

    if (hour == alarm::v1 && minute == alarm::d1 && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
    }
    if (hour == alarm::s2 && minute == alarm::saalarm && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
    }
    if (hour == alarm::sass3 && minute == alarm::minute3 && second == 1)
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
    //index.br() ;
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
    index.ncoderrr ();
    if (h > 2)
    {
        h = 0;
        delay (500);
//      Serial.println(h);
  }
}
void index.ncoderrr ()
    {
    lastButton = digitalRead(BUT); //чтение текущего положения кнопки
    long newPosition = myEnc.read(); //чтение новой позиции
    if (newPosition != encoder::oldPosition) 
    { //если она отлична от старой
        if (encoder::oldPosition != -999)
        { //начальная позиция не интересует
            if (BOSSOFTHEGYM >= 1)
            {
                if (BOSSOFTHEGYM == 1 )
                {
                    alarm::v1 = newPosition - encoder::oldPosition + alarm::v1;
                    alarm::v1 = abs(alarm::v1);
                    lcd.setCursor (0, 2);
                    lcd.print (alarm::v1);
                    if (alarm::v1 >= 23)
                    {
                        alarm::v1 = 0;
                    }
               }
               if (BOSSOFTHEGYM == 2 )
                   {
                       alarm::d1 = newPosition - encoder::oldPosition + alarm::d1;
                       alarm::d1 = abs(alarm::d1);
                       lcd.setCursor (3, 2);
                       lcd.print (alarm::d1);
                       if (alarm::d1 >= 59)
                       {
                           alarm::d1 = 0;
                       }
                  }
               if (BOSSOFTHEGYM == 3 )
               {
                   alarm::s2 = newPosition - encoder::oldPosition + alarm::s2;
                   alarm::s2 = abs(alarm::s2);
                   lcd.setCursor (5, 2);
                   lcd.print (alarm::s2);
                   if (alarm::s2 >= 23)
                   {
                       alarm::s2 = 0;
                   }
              }
              if (BOSSOFTHEGYM == 4 )
              {
                  alarm::saalarm = newPosition - encoder::oldPosition + alarm::saalarm;
                  alarm::saalarm = abs(alarm::saalarm);
                  lcd.setCursor (8, 2);
                  lcd.print (alarm::saalarm);
                  if (alarm::v1 >= 59)
                  {
                      alarm::v1 = 0;
                  }
             }
             if (BOSSOFTHEGYM == 5 )
             {
                 alarm::sass3 = newPosition - encoder::oldPosition + alarm::sass3;
                 alarm::sass3 = abs(alarm::sass3);
                 lcd.setCursor (11, 2);
                 lcd.print (alarm::sass3);
                 if (alarm::sass3 >= 23)
            {
            alarm::v1 = 0;
        }
      }
      if (BOSSOFTHEGYM == 6 )
      {
        alarm::minute3 = newPosition - encoder::oldPosition + alarm::minute3;
        alarm::minute3 = abs(alarm::minute3);
        lcd.setCursor (14, 2);
        lcd.print (alarm::minute3);
        if (alarm::minute3 >= 59)
        {
            alarm::minute3 = 0;
        }
      }      
    }
            }
    if (BOSSOFTHEGYM <= 1) { 
    if (h == 0){
    f = newPosition - encoder::oldPosition + f;
    f = abs(f);
    lcd.setCursor (10, 0);
    lcd.print (f);
    if (f >= 23)
     {
            f = 0;
     }
    }
     if (h == 1){
     c = newPosition - encoder::oldPosition + c;
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
    encoder::oldPosition = newPosition; //запомнить новую позицию
 }
}
