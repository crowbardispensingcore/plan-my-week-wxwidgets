#include "military_time.h"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

int MilitaryTime::getMinutes(){
    return minutes;
}
int MilitaryTime::getHours(){
    return hours;
}
// int MilitaryTime::calcDuration(MilitaryTime time1, MilitaryTime time2){
    
// }
void MilitaryTime::setMinute(int minute){
    this->minutes=minute;
}
void MilitaryTime::setHour(int hour){
    this->hours=hour;
}
string MilitaryTime::mil_to_std(int time) {
	int hour = time / 100;
	int minute = time - hour * 100;
	string timeframe = "";
	string returnTime;
	if (hour < 12) {
		timeframe = "AM";
	}
	else {
		if (hour > 12) {
			hour -= 12;
		}
		timeframe = "PM";
	}
	string hour_str = to_string(hour);
	string minute_str = to_string(minute);
	if (minute == 0) {
		minute_str = "00";
	}
	if (hour == 0) {
		hour_str = "12";
	}
	returnTime = hour_str + ":" + minute_str + timeframe;
	return returnTime;
}
//converts duration in minutes to hours and minutes
string MilitaryTime::dur_to_std(int duration) {
	int hour = duration / 60;
	int minute = duration - hour * 60;
	string returnTime;
	returnTime = to_string(hour) + "hours and " + to_string(minute) + " minutes";
	return returnTime;
}