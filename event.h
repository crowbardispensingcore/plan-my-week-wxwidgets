#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class event {
public:
	event();
	event(string name, string description, int duration, 
		int startTime, int endTime, int priority, int specificDay);
	void print_event();    //used for testing purposes, prints event information to console
	friend bool operator<(const event& lhs, const event& rhs);
	
	int get_duration() { return duration;}
	int get_startTime() { return startTime; }
	int get_endTime() { return endTime; }
	int get_specificDay() { return specificDay; }

private: 
	string name;    //name of the event 
	string description;    //description of the event
	int duration;    //duration in minutes 
	int startTime;    //start in military time 
	int endTime;    //end in military time
	int priority;    //priority of the requested event 
	int specificDay;    //Specific requested day of week, 0 == Monday, 1 == Tuesday etc...
	vector<int>repeating;
};
#endif
