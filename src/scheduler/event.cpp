#include "event.h"
//default constructor to initialize a new event
event::event() {    
	name = "";
	description = "";
	duration = 0;
	startTime = 0;
	endTime = 0; 
	specificDay = -1;    //-1 refers to no specific day of the week 
	priority = 0;        //0 refers to highest priority 
}
//paramaterized constructor 
event::event(string name, string description, int duration,
	int startTime, int endTime, int priority, int specificDay) 
{
	this->name = name;
	this->description = description;
	this->duration = duration;
	this->startTime = startTime;
	this->priority = priority;
	this->specificDay = specificDay;
}
//prints a single events details
void event::print_event() {
	cout << "Event Name: " << this->name << endl;
	cout << "Event Description " << this->description << endl;
	cout << "Start Time: " << mil_to_std(this->startTime) << " End Time: "<< mil_to_std(this->endTime) <<" Duration: "<<dur_to_std(this->duration) << endl;
}
//overloaded operator to compare event priority
bool operator<(const event& lhs, const event& rhs) {
	return lhs.priority > rhs.priority;
}
//converts military time to standard time for printing
string event::mil_to_std(int time) {
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
string event::dur_to_std(int duration) {
	int hour = duration / 60;
	int minute = duration - hour * 60;
	string returnTime;
	returnTime = to_string(hour) + "hours and " + to_string(minute) + " minutes";
	return returnTime;
}
