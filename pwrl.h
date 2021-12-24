 #include <Encoder.h> 
 #include <Wire.h>
 #include <Rtc_Pcf8563.h>
 #include <LiquidCrystal.h> 
 #include <Servo.h>
 #include <Stepper.h>
namespace encoder{
const int pinA = A1; //вывод подключения контакта А
const int pinB = A2; //вывод подключения контакта В
long oldPosition  = -999; //переменная для хранения старой позици
}
/*m*/
namespace alarm{
int v1 = 0;         //будильник на часы 1
int d1 = 0;           //будильник на минуты 1
int s2 = 0;         //будильник на часы 2
int saalarm = 0;         //будильник на минуты 2
int sass3 = 0;      //будильник на часы 3
int minute3 = 0;      //будильник на минуты 3
int hours4 = 0;     //будильник на часы 4
int minute4 = 0;      //будильник на минуты 4
}
const int BUT1 = A0;
const int BUT3 = 13;//включени

bool lastButton = HIGH; //прошлое положение кнопки
int degree = 0;
int h = 0; // работа часов вообще
int f = 0; // время- час
int c = 0; // время минуты
int BOSSOFTHEGYM = 0;

LiquidCrystal lcd(8, 7, 2, 3, 4, 5); // rs, e,d4, d5, d6, d7
Rtc_Pcf8563 rtc;
Stepper stepper(32,8,10,9,11);
Servo servoDrive;
Encoder myEnc(encoder::pinA, encoder::pinB); //объявление объекта для работы с энкодером


class index{
  public:
void br(){
    if (digitalRead(BUT1) == HIGH)
    {
        BOSSOFTHEGYM = BOSSOFTHEGYM+1;
        delay(500);
        Serial.println(BOSSOFTHEGYM);
    }
    if(BOSSOFTHEGYM == 7){
      BOSSOFTHEGYM = 0;
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
void index.ncoderrr (){
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
        if (BOSSOFTHEGYM < 1) { 
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
     if (c >= 60)
     {
            c = 0;
     }     
    }    
    }
            }
    encoder::oldPosition = newPosition; //запомнить новую позицию
        }

}



  private:

}
}
}
