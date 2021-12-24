 #include <Servo.h>
 #include <Encoder.h> 



const int BUT = A5; //вывод подключения контакта D
long oldPosition  = -999; //переменная для хранения старой позиции
bool lastButton = HIGH; //прошлое положение кнопки
const int LED = 6;
const int BUT1 = A0;
const int BUT3 = 13;//включени
int h = 0; // работа часов вообще
int f = 0; // время- час
int c = 0; // время минуты

int BOSSOFTHEGYM = 0;
int v1 = 0;         //будильник на часы 1
int d1 = 0;           //будильник на минуты 1
int s2 = 0;         //будильник на часы 2
int sas2 = 0;         //будильник на минуты 2
int sass3 = 0;      //будильник на часы 3
int minute3 = 0;      //будильник на минуты 3
int hours4 = 0;     //будильник на часы 4
int minute4 = 0;      //будильник на минуты 4




















class pwrl_main{
public:
 pwrl_main(int pina,pinb/*пины инкодера*/){
  pinA = pina;
  pinB = pinb;
 }
   bool srv(int dgr){/*работа с серво*/
    if (srv_setup == true){
   if(dgr>=0&&dgr<=180){
    if (dgr != last_dgr){
      servoDrive.write(dgr);
      last_dgr = dgr;
      return true;
    }
    else{
      return true;
    }
   }
   else{
    return false;
   }
    }
    else {
      return false;
    }
}
  void srv_setup_(int prt,int position_zero){/*инициализация серво*/
    
    servoDrive.attach(prt);
    servoDrive.write(position_zero);
    last_dgr = position_zero;
    srv_setup = true;
  }
  bool alarm_check(){/*проверка совпадения времяни с будильником*/
  
  if(alarm_setup != false){
    time_up();
    if(times[0] == alarm_times[0]{
      if(times[1] == alarm_times[1]){
        switch(times[2]){
          case alarm_times_sc[0]:
            return true;
            break;
          case alarm_times_sc[1]:
            return true;
            break;
          case alarm_times_sc[2]:
            return true;
            break;
         case alarm_times_sc[3]:
            return true;
            break;
         case alarm_times_sc[4]:
            return true;
            break;
        case alarm_times_sc[5]:
            return true;
            break;
        case alarm_times_sc[6]:
            return true;
            break;
        case alarm_times_sc[7]:
            return true;
            break;
        case alarm_times_sc[8]:
            return true;
            break;
        case alarm_times_sc[9]:
            return true;
            break;
        case alarm_times_sc[10]:
            return true;
            break;
        default :
            return false; 
        }
      }
      else {
        return false;
      }
    }
    return false;
  }
  else{
    return false;
  }
  }
  int enc_ret(){
   int l = encd.read();
   if (){
    
   }
  }
private:
  void time_up(){/*актуализация времяни*/
    times[0] = rtc.getHour();
    times[1] = rtc.getMinute();
    times[2] = rtc.getSecond();
  }
  int last_dgr;/*последнее значение угла серво*/
  byte times[3];/*актулизированное время*/
  int alarm_times[2];/*час и минута для будильника*/
  int alarm_times_sc[11];/*массив погрешности секунд*/
  bool alarm_setup = false;/*флаг инициализации будильника*/
  bool srv_setup = false;/*флаг инициализации серво*/
  int  pinA,pinB;/*пины инкодера*/
  int  last_l = 0;
  Servo servoDrive;/*обьект серво*/
  Encoder Encd(pinA, pinB);/*обьект инкодера*/
  
}
