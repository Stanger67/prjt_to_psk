 #include <Encoder.h> 
 #include <Wire.h>
 #include <Rtc_Pcf8563.h>
 #include <LiquidCrystal.h> 
 #include <Servo.h>
 #include <Stepper.h>
 #include "namespace.h"


void kordan(){
  ptw_obj::st_m.setSpeed(500);
  ptw_obj::st_m.step(2048);
  delay(1500);

  ptw_obj::st_m.setSpeed(1000);
  ptw_obj::st_m.step(-2048);
  delay(1500);
}
void alarm_for_work(){
  if (ptw::alarm_all[3] >= 1){
     
  }
}
void br(){
    if (digitalRead(ptw::BUT1) == HIGH)
    {
        ptw::br_int = ptw::br_int +1;
        delay(500);
        Serial.println(ptw::br_int);
    }
    if(ptw::br_int == 8){
      ptw::br_int = 0;
      Serial.println(ptw::br_int);
    }

    ptw_obj::rtc.getTime(); //получение времени с часов
    byte hour = ptw_obj::rtc.getHour(); //запись в переменную количество часов
    byte minute = ptw_obj::rtc.getMinute();
    byte second = ptw_obj::rtc.getSecond ();

    if (hour == ptw::alarm_hour [2] && minute == ptw::alarm_all [2] && second == 1)
    {
        ptw_obj::st_m.setSpeed(500);
        ptw_obj::st_m.step(2048);
        delay(1500);

        ptw_obj::st_m.setSpeed(1000);
        ptw_obj::st_m.step(-2048);
        delay(1500);
        
        delay(100);   
    }
    if (hour == ptw::alarm_hour [3] && minute == ptw::alarm_all [3] && second == 1)
    {
        ptw_obj::st_m.setSpeed(500);
        ptw_obj::st_m.step(2048);
        delay(1500);

        ptw_obj::st_m.setSpeed(1000);
        ptw_obj::st_m.step(-2048);
        delay(1500);
        
        delay(100);   
    }
    if (hour == ptw::alarm_hour [4] && minute ==ptw::alarm_all [4] && second == 1)
    {
        ptw_obj::st_m.setSpeed(500);
        ptw_obj::st_m.step(2048);
        delay(1500);

        ptw_obj::st_m.setSpeed(1000);
        ptw_obj::st_m.step(-2048);
        delay(1500);
        
        delay(100);   
   }
}

void ncoderrr ()
    {
    ptw::lastButton = digitalRead(ptw::BUT); //чтение текущего положения кнопки
    long newPosition = ptw_obj::myEnc.read(); //чтение новой позиции
    if (newPosition != ptw::oldPosition) 
    { //если она отлична от старой
        if (ptw::oldPosition != -999)
        { //начальная позиция не интересует
            if (ptw::br_int >= 1)
            {
                if (ptw::br_int == 1 )
                {
                    ptw::alarm_hour [2] = newPosition - ptw::oldPosition + ptw::alarm_hour [2];
                    ptw::alarm_hour [2] = abs(ptw::alarm_hour [2]);
                    ptw_obj::lcd.setCursor (0, 2);
                    ptw_obj::lcd.print (ptw::alarm_hour [2]);
                    if (ptw::alarm_hour [2] >= 23)
                    {
                        ptw::alarm_hour [2] = 0;
                    }
               }
               if (ptw::br_int == 2 )
                   {
                       ptw::alarm_all [2] = newPosition - ptw::oldPosition + ptw::alarm_all [2];
                       ptw::alarm_all [2] = abs(ptw::alarm_all [2]);
                       ptw_obj::lcd.setCursor (3, 2);
                       ptw_obj::lcd.print (ptw::alarm_all [2]);
                       if (ptw::alarm_all [2] >= 59)
                       {
                           ptw::alarm_all [2] = 0;
                       }
                  }
               if (ptw::br_int == 3 )
               {
                   ptw::alarm_hour [3] = newPosition - ptw::oldPosition + ptw::alarm_hour [3];
                   ptw::alarm_hour [3] = abs(ptw::alarm_hour [3]);
                   ptw_obj::lcd.setCursor (5, 2);
                   ptw_obj::lcd.print (ptw::alarm_hour [3]);
                   if (ptw::alarm_hour [3] >= 23)
                   {
                       ptw::alarm_hour [3] = 0;
                   }
              }
              if (ptw::br_int == 4 )
              {
                  ptw::alarm_all [3] = newPosition - ptw::oldPosition + ptw::alarm_all [3];
                  ptw::alarm_all [3] = abs(ptw::alarm_all [3]);
                  ptw_obj::lcd.setCursor (8, 2);
                  ptw_obj::lcd.print (ptw::alarm_all [3]);
                  if (ptw::alarm_all [3] >= 59)
                  {
                      ptw::alarm_all [3] = 0;
                  }
             }
             if (ptw::br_int == 5 )
             {
                 ptw::alarm_hour [4] = newPosition - ptw::oldPosition + ptw::alarm_hour [4];
                 ptw::alarm_hour [4] = abs(ptw::alarm_hour [4]);
                 ptw_obj::lcd.setCursor (11, 2);
                 ptw_obj::lcd.print (ptw::alarm_hour [4]);
                 if (ptw::alarm_hour [4] >= 23)
                    {
                     ptw::alarm_hour [4] = 0;
                    }
      }
      if (ptw::br_int == 6 )
      {
        ptw::alarm_all [4] = newPosition - ptw::oldPosition + ptw::alarm_all [4];
        ptw::alarm_all [4] = abs(ptw::alarm_all [4]);
        ptw_obj::lcd.setCursor (14, 2);
        ptw_obj::lcd.print (ptw::alarm_all [4]);
        if (ptw::alarm_all [4] >= 59)
        {
            ptw::alarm_all [4] = 0;
        }
      }      
    }
        if (ptw::br_int < 1) { 
    if (ptw::h == 0){
    ptw::alarm_hour[1] = newPosition - ptw::oldPosition + ptw::alarm_hour [1];
    ptw::alarm_hour[1] = abs(ptw::alarm_hour [1]);
    ptw_obj::lcd.setCursor (10, 0);
    ptw_obj::lcd.print (ptw::alarm_hour [1]);
    if (ptw::alarm_hour [1] >= 23)
     {
           ptw::alarm_hour [1] = 0;
     }
    }
     if (ptw::h == 1){
     ptw::alarm_all [1] = newPosition - ptw::oldPosition + ptw::alarm_all [1];
     ptw::alarm_all [1] = abs(ptw::alarm_all [1]);
     ptw_obj::lcd.setCursor (13, 0);
     ptw_obj::lcd.print (ptw::alarm_all [1]);
     if (ptw::alarm_all [1] >= 60)
     {
           ptw::alarm_all [1] = 0;
     }     
    }    
    }
            }
    ptw::oldPosition = newPosition; //запомнить новую позицию
        }

 }
