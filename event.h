#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

using namespace std;

class event {
public:
	event();
	event(string name, string description, int duration, 
		int startTime, int endTime, int priority, int specificDay);
	void print_event();    //used for testing purposes, prints event information to console 
	bool operator<(const event&x, const event& y);
private: 
	string name;    //name of the event 
	string description;    //description of the event
	int duration;    //duration in minutes 
	int startTime;    //start in military time 
	int endTime;    //end in military time
	int specificDay;    //Specific requested day of week, 0 == Monday, 1 == Tuesday etc...
	int priority;    //priority of the requested event 
};
#endif
