#include "pwrl.h"
index idx;

void setup() 
    {
    Serial.begin(9600);
    lcd.begin (16, 2);
//    pinMode (LED, OUTPUT);
    pinMode (BUT1 , INPUT);
    servoDrive.attach (12);
    degree = servoDrive.read();
    }
void loop() 
    {
    idx.br() ;
   // digitalWrite(LED, digitalRead(BUT1));
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
    lcd.setCursor(2, 2);
    lcd.print (':');
    lcd.setCursor(7, 2);
    lcd.print (':');
    lcd.setCursor(13, 2);
    lcd.print (':');
    idx.ncoderrr ();
    if (h > 2)
    {
        h = 0;
        delay (10);
//      Serial.println(h);
  }
}
