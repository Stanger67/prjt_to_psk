 #include <Encoder.h> 
 #include <Wire.h>
 #include <Rtc_Pcf8563.h>
 #include <LiquidCrystal.h> 
 #include <Servo.h>
 #include <Stepper.h>

 Stepper stepper(32,9,12,10,11);                                          // ..., IN1, IN3, IN2, IN4
 
    const int pinA = A1; //вывод подключения контакта А
    const int pinB = A2; //вывод подключения контакта В
    const int BUT = A3; //вывод подключения контакта D++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    const int LED = 6;
    const int BUT1 = A0;
    const int BUT3 = 13;//включени
    
Encoder myEnc(pinA, pinB); //объявление объекта для работы с энкодером
long oldPosition  = -999; //переменная для хранения старой позиции
bool lastButton = HIGH; //прошлое положение кнопки

Servo servoDrive;
int degree = 0;

LiquidCrystal lcd(8, 7, 2, 3, 4, 5); // rs, e,d4, d5, d6, d7
Rtc_Pcf8563 rtc;

int h = 0; // работа часов вообще
int f = 0; // время- час
int c = 0; // время минуты
int BOSSOFTHEGYM = 0;

int alarm_all [8]; //1-2: сами часы и минуты, 3,5,7: будильник по часам, 4,6,8: будильник по минутам
boolean alarm_work [3] = {true,true,true};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void kordan(){
  stepper.setSpeed(500);
  stepper.step(2048);
  delay(1500);

  stepper.setSpeed(1000);
  stepper.step(-2048);
  delay(1500);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void alarm_for_work(){
  if (alarm_all[3] >= 1){
     
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void br(){
    if (digitalRead(BUT1) == HIGH)
    {
        BOSSOFTHEGYM = BOSSOFTHEGYM+1;
        delay(500);
        Serial.println(BOSSOFTHEGYM);
    }
    if(BOSSOFTHEGYM == 8){
      BOSSOFTHEGYM = 0;
      Serial.println(BOSSOFTHEGYM);
    }

    rtc.getTime(); //получение времени с часов
    byte hour = rtc.getHour(); //запись в переменную количество часов
    byte minute = rtc.getMinute();
    byte second = rtc.getSecond ();

    if (hour == alarm_all [3] && minute == alarm_all [4] && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
    }
    if (hour == alarm_all [5] && minute == alarm_all [6] && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
    }
    if (hour == alarm_all [7] && minute == alarm_all [8] && second == 1)
    {
        digitalWrite(LED, HIGH);
        kordan();
        delay(100);   
   }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
    {
    Serial.begin(9600);
    lcd.begin (16, 2);
    pinMode (LED, OUTPUT);
    pinMode (BUT1 , INPUT);
    servoDrive.attach (12);
    degree = servoDrive.read();
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() 
    {
    br() ;
    digitalWrite(LED, digitalRead(BUT1));
    if (h>=2)
        {
            rtc.initClock();//часы
/*            rtc.setDate (9, 2, 10, 0, 21); // месяц3, неделя1, день2, год4*/
            rtc.setTime(alarm_all [1], alarm_all [2], 0);
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
    ncoderrr ();
    if (h > 2)
    {
        h = 0;
        delay (10);
//      Serial.println(h);
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
                    alarm_all [3] = newPosition - oldPosition + alarm_all [3];
                    alarm_all [3] = abs(alarm_all [3]);
                    lcd.setCursor (0, 2);
                    lcd.print (alarm_all [3]);
                    if (alarm_all [3] >= 23)
                    {
                        alarm_all [3] = 0;
                    }
               }
               if (BOSSOFTHEGYM == 2 )
                   {
                       alarm_all [4] = newPosition - oldPosition + alarm_all [4];
                       alarm_all [4] = abs(alarm_all [4]);
                       lcd.setCursor (3, 2);
                       lcd.print (alarm_all [4]);
                       if (alarm_all [4] >= 59)
                       {
                           alarm_all [4] = 0;
                       }
                  }
               if (BOSSOFTHEGYM == 3 )
               {
                   alarm_all [5] = newPosition - oldPosition + alarm_all [5];
                   alarm_all [5] = abs(alarm_all [5]);
                   lcd.setCursor (5, 2);
                   lcd.print (alarm_all [5]);
                   if (alarm_all [5] >= 23)
                   {
                       alarm_all [5] = 0;
                   }
              }
              if (BOSSOFTHEGYM == 4 )
              {
                  alarm_all [6] = newPosition - oldPosition + alarm_all [6];
                  alarm_all [6] = abs(alarm_all [6]);
                  lcd.setCursor (8, 2);
                  lcd.print (alarm_all [6]);
                  if (alarm_all [6] >= 59)
                  {
                      alarm_all [6] = 0;
                  }
             }
             if (BOSSOFTHEGYM == 5 )
             {
                 alarm_all [7] = newPosition - oldPosition + alarm_all [7];
                 alarm_all [7] = abs(alarm_all [7]);
                 lcd.setCursor (11, 2);
                 lcd.print (alarm_all [7]);
                 if (alarm_all [7] >= 23)
                    {
                     alarm_all [7] = 0;
                    }
      }
      if (BOSSOFTHEGYM == 6 )
      {
        alarm_all [8] = newPosition - oldPosition + alarm_all [8];
        alarm_all [8] = abs(alarm_all [8]);
        lcd.setCursor (14, 2);
        lcd.print (alarm_all [8]);
        if (alarm_all [8] >= 59)
        {
            alarm_all [8] = 0;
        }
      }      
    }
        if (BOSSOFTHEGYM < 1) { 
    if (h == 0){
    alarm_all [1] = newPosition - oldPosition + alarm_all [1];
    alarm_all [1] = abs(alarm_all [1]);
    lcd.setCursor (10, 0);
    lcd.print (alarm_all [1]);
    if (alarm_all [1] >= 23)
     {
           alarm_all [1] = 0;
     }
    }
     if (h == 1){
     alarm_all [2] = newPosition - oldPosition + alarm_all [2];
     alarm_all [2] = abs(alarm_all [2]);
     lcd.setCursor (13, 0);
     lcd.print (alarm_all [2]);
     if (alarm_all [2] >= 60)
     {
            alarm_all [2] = 0;
     }     
    }    
    }
            }
    oldPosition = newPosition; //запомнить новую позицию
        }

 }
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
