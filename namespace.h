namespace ptw{
boolean alarm_work [3] = {true,true,true};
int alarm_hour [5]; 
int alarm_all [5];
const int pinA = A1; 
const int pinB = A2;
const int BUT = A3; 
const int BUT1 = 6;
const int BUT3 = 13; 
long oldPosition  = -999;
bool lastButton = HIGH;
int degree = 0;
int n = 0;//число чисел в массиве
int h= 0;
int br_int = 0;
}
namespace ptw_obj{
Stepper st_m(32,9,12,10,11);
Encoder myEnc(ptw::pinA, ptw::pinB);
Servo servoDrive;
LiquidCrystal lcd(8, 7, 2, 3, 4, 5);
Rtc_Pcf8563 rtc;
}
