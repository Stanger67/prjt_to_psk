#include "index.h"
void setup() 
    {
    Serial.begin(9600);
    ptw_obj::lcd.begin (16, 2);
    pinMode (ptw::BUT1 , INPUT);
    ptw_obj::servoDrive.attach (12);
    ptw::degree = ptw_obj::servoDrive.read();
    }
    

void loop() 
    {
    br() ;
       if (ptw::h >= 2)
        {
            ptw_obj::rtc.initClock();//часы
/*            ptw_obj::ptw_obj::rtc.setDate (9, 2, 10, 0, 21); // месяц3, неделя1, день2, год4*/
            ptw_obj::rtc.setTime(ptw::alarm_hour [1], ptw::alarm_all [1], 0);
        }
    ptw_obj::lcd.home();
    ptw_obj::lcd.print (ptw_obj::rtc.formatTime());//часы
    ptw_obj::lcd.setCursor(0, 1);
   
    if (digitalRead(ptw::BUT3)== HIGH)
    {
       ptw::h =ptw::h+ 1;
        delay(500);
        Serial.println (ptw::h); 
    } 
    ptw_obj::lcd.setCursor(12, 0);
    ptw_obj::lcd.print(':');
    ptw_obj::lcd.setCursor(2, 2);
    ptw_obj::lcd.print (':');
    ptw_obj::lcd.setCursor(7, 2);
    ptw_obj::lcd.print (':');
    ptw_obj::lcd.setCursor(13, 2);
    ptw_obj::lcd.print (':');
    ncoderrr ();
    if (ptw::h > 2)
    {
       ptw::h= 0;
        delay (10);
  }
}
