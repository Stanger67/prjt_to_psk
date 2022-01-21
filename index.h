 #include <Encoder.h> 
 #include <Wire.h>
 #include <Rtc_Pcf8563.h>
 #include <LiquidCrystal.h> 
 #include <Servo.h>
 #include <Stepper.h>
 #include "namespace.h"

 class index{
    public:
      main_work(){
        ptw_obj::rtc.initClock();
        ptw_obj::lcd.home();
        ptw_obj::lcd.print (ptw_obj::rtc.formatTime());
        ptw_obj::lcd.setCursor(0, 1);
        ptw_obj::lcd.setCursor(12, 0);
        ptw_obj::lcd.print(':');
        ptw_obj::lcd.setCursor(2, 2);
        ptw_obj::lcd.print (':');
        ptw_obj::lcd.setCursor(7, 2);
        ptw_obj::lcd.print (':');
        ptw_obj::lcd.setCursor(13, 2);
        ptw_obj::lcd.print (':');
        int tups = buttn_control();
        switch(tups){
          case 2:
            alarm_setup_ncoder();
            break;
          case 1:
            clock_setup();
        }
        alm.alarm_work();
      }      
    private:
     void clock_setup(){
      int ch_time[2] = {0,0};
      long oldPosition = ptw_obj::myEnc.read(); 
      bool x = false;
      long newPosition;
      while(x == false){
        newPosition = ptw_obj::myEnc.read();
        ch_time[0] = newPosition - oldPosition + ch_time;
        ptw_obj::lcd.setCursor (11, 2);
        ptw_obj::lcd.print (ch_time[0]);
        if (but_easy == true){
          x = true;
       }
      }
      x = false;
      while (x == false){
         newPosition = ptw_obj::myEnc.read();
         ch_time[1] = newPosition - oldPosition + ch_time;
         ptw_obj::lcd.setCursor (13, 0);
         ptw_obj::lcd.print (ch_time [1]);
         if (but_easy==true){
          x = true;
         }
      }
      x = false;
      ptw_obj::rtc.setTime(ch_time[0],ch_time[1]0);
    }
     void alarm_setup_ncoder(){
      int ch_time[2] = {0,0};
      long oldPosition = ptw_obj::myEnc.read(); 
      bool x = false;
      long newPosition;
      while(x == false){
        newPosition = ptw_obj::myEnc.read();
        ch_time[0] = newPosition - oldPosition + ch_time;
        ptw_obj::lcd.setCursor (11, 2);
        ptw_obj::lcd.print (ch_time[0]);
        if (but_easy == true){
          x = true;
       }
      }
      x = false;
      while (x == false){
         newPosition = ptw_obj::myEnc.read();
         ch_time[1] = newPosition - oldPosition + ch_time;
         ptw_obj::lcd.setCursor (13, 0);
         ptw_obj::lcd.print (ch_time [1]);
         if (but_easy==true){
          x = true;
         }
      }
      x = false;
      alm.set_alarm(ch_time[0],ch_time[1]);
     }
     alrm alm;
     bool but_easy(){
        if (ptw::but1 == HIGH){
          return true;
        }
        else{
          return false;
        }
     }
     int buttn_control(){
      if(ptw::but1 == HIGH){
        int x = buttn();
        return x;
      }
      else{
      return 0;  
      }
      
     }
     int buttn(){
        boolean reading = digitalRead(ptw::but1);
        if (reading && !lastReading){
          onTime = millis();
        }
  
        if (!reading && lastReading){
        if (((millis() - onTime) > bounceTime)){
        if ((millis() - lastSwitchTime) >= doubleTime){
          lastSwitchTime = millis();
          buttonSingle = true;
          i=1;
        } else {
          i++;
          lastSwitchTime = millis();
          buttonSingle = false;
          buttonMulti = true;
        }
      }
    }
  
    lastReading = reading;
  
    if (buttonSingle && (millis() - lastSwitchTime) > doubleTime){
      buttonSingle = false;
      buttonMulti = false;
      return 1;
    }
    if (buttonMulti && (millis() - lastSwitchTime) > doubleTime){
      buttonSingle = false;
      buttonMulti = false;
      return i; 
    }
    }
      boolean lastReading = false;  
      boolean buttonSingle = false; 
      boolean buttonMulti = false;
      long onTime = 0;
      long lastSwitchTime = 0;
      const int bounceTime = 10;
      const int doubleTime = 500;
      int i = 0;
 };
 class alrm{
    public:
    void alarm_work(){
      if(alarm_check ==true){
      ptw_obj::st_m.setSpeed(500);
        ptw_obj::st_m.step(2048);
        delay(1500);

        ptw_obj::st_m.setSpeed(1000);
        ptw_obj::st_m.step(-2048);
        delay(1500);
      }  
    }
    bool set_alarm(int hour,int mnt){
      if (alarm_index >predel_alarm){
         return false;
      }
      if (arr_srch(hour,mnt,sec) == true){
        return false;
      }
      alarm[0][alarm_index-1] = hour;
      alarm[1][alarm_index-1] = mnt;
      alarm[2][alarm_index-1] = sec;
      alarm_index++;
    }
    private:
    bool alarm_check(){
      get_rt();
      if(arr_srch(rtime[0],rtime[1],rtime[2]) == true){
        return true;
      }
      else{
        return false;
      }
    }
    bool arr_srch(int hour,int mnt){
      int x = 0;
      while (x<alarm_index){
        if (alarm[0][x] == hour&&alarm[1][x] == mnt){
          return true;
        }
        x++;
      }
      return false;
    }
    void bettn(){
  if (digitalRead(ptw::BUT1) == HIGH)
    {
        ptw::br_int = ptw::br_int +1;
        delay(500);
    }
    if(ptw::br_int == 8){
      ptw::br_int = 0;
      Serial.println(ptw::br_int);
    }
}
    void get_rt(){
    ptw_obj::rtc.getTime();
    rtime[0] = ptw_obj::rtc.getHour();
    rtime[1] = ptw_obj::rtc.getMinute();
    rtime[2] = ptw_obj::rtc.getSecond ();
    }
    byte rtime[3];//0-hour;1-minute;2-sec
    int alarm[2][30];//0-hour;1-minute;2-sec
    int alarm_index = 1;
    const int predel_alarm = 30;
 };
 
