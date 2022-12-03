#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Event {
public:
	//default constructor to initialize a new event
	Event();
	//paramaterized constructor 

	Event(string name, string description, int duration, 
		int startTime, int endTime, int priority, int specificDay);

	//prints a single events details
	void print_event();    

	//overloaded operator to compare event priority
	friend bool operator<(const Event& lhs, const Event& rhs);

	//converts military time to standard time for printing
	string mil_to_std(int time);

	//converts duration in minutes to hours and minutes
	string dur_to_std(int duration);

	//Accessor functions 
	int get_duration() { return duration;}
	int get_startTime() { return startTime; }
	int get_endTime() { return endTime; }
	int get_specificDay() { return specificDay; }
	
	//Mutator functions
	void set_startTime(int startTime) { this->startTime = startTime; }
	void set_endTime(int endTime) { this->endTime = endTime; }
	void set_specificDay(int specificDay) { this->specificDay = specificDay; }
private: 
	string name;           //name of the event 
	string description;    //description of the event
	int duration;          //duration of event in minutes 
	int startTime;         //start time in military time 
	int endTime;           //end time in military time
	int priority;          //priority of the requested event 
	int specificDay;       //Specific requested day of week, 0 == Monday, 1 == Tuesday etc...
};
#endif
