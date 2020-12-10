#include <Wire.h>
#include "RTClib.h"
#include "Time.h"
#include "TimeAlarms.h"

//RTC_Millis rtc;
RTC_DS3231 rtc;

const int output = 3;

uint32_t syncProvider()//function which sets up the RTC as the source of external time
{
  return rtc.now().unixtime();
}


void setup(){
  //rtc.begin(DateTime(F(__DATE__), F(__TIME__)));  
 rtc.begin();
// following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));//comment this out when the RTC has been set

 setSyncProvider(syncProvider);   // the function to get the time from the RTC
 

  Alarm.alarmRepeat(9,13,50,buzzer);  // 10:30am every day
  Alarm.alarmRepeat(9,14,10,buzzer);  // 4:30pm every day 
  Alarm.alarmRepeat(9,15,30,buzzer);  // 10:30pm every day 
  
  pinMode( output , OUTPUT);//new line
  Serial.begin(9600);
}

void loop(){

  //printing the current time
  DateTime now = rtc.now();
    
  Serial.print(now.year());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.day());
  Serial.print(' ');
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.println();
   Alarm.delay(1000); // wait one second between clock display
}

void buzzer(){
  Alarm.alarmRepeat(9,15,40,buzzer);  // 10:30pm every day 
  Serial.print('buzzerrere');
}
