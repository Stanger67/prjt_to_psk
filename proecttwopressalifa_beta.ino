#include "index.h"
void setup() 
    {
    Serial.begin(9600);
    ptw_obj::lcd.begin (16, 2);
    pinMode (ptw::LED, OUTPUT);
    pinMode (ptw::BUT1 , INPUT);
    }
    

void loop() 
    {
    br() ;
    digitalWrite(ptw::LED, digitalRead(ptw::BUT1));
    if (ptw::h>=2)
        {
            //часы
/*            ptw_obj::ptw_obj::rtc.setDate (9, 2, 10, 0, 21); // месяц3, неделя1, день2, год4*/
            
        }
    //часы
    
   
    if (digitalRead(ptw::BUT3)== HIGH)
    {//включение
       ptw::h =ptw::h+ 1;
//      Serial.println(h);
        delay(500);
    } //включение кнопок в код
    
    ncoderrr ();
    if (ptw::h > 2)
    {
       ptw::h= 0;
        delay (10);
  }
}
