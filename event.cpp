#include "event.h"

event::event() {    //default constructor 
	name = "";
	description = "";
	duration = 0;
	startTime = 0;
	endTime = 0;
	specificDay = -1;    //-1 refers to no specific day of the week 
	priority = 0;
}

event::event(string name, string description, int duration,
	int startTime, int endTime, int priority, int specificDay) 
{
	this->name = name;
	this->description = description;
	this->duration = duration;
	this->startTime = startTime;
	this->specificDay = specificDay;
	this->priority = priority;
}
void event::print_event() {
	cout << "Event Name: " << this->name << endl;
	cout << "Event Description " << this->description << endl;
	cout << "Event Duration: " << this->duration << " minutes" << endl;
}

bool event::operator<(event const& e)
{
	if (this->priority > e.priority) {
		return true;
	}
	return false;
}
