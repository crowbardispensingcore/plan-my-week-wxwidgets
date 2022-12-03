#include <iostream>
#include <string>
#include "event_factory.h"
#include "event.h"
//default constructor
EventFactory::EventFactory() {

}
//creates and returns a new event 
Event EventFactory::create_custom_event(string name, string description, int duration, int startTime, int endTime, int priority, int specificDay) {
	return Event(name, description, duration, startTime, endTime, priority, specificDay);
}
Event EventFactory::create_param_event(int option, int duration, int startTime) {
	switch (option) {
	case 1:
		return Event("Sleep", "Sleep Time", duration, startTime, -1, 0, -1);
	case 2:
		return Event("Lunch", "Lunch Time", duration, startTime, -1, 0, -1);
	case 3:
		return Event("Dinner", "Dinner Time", duration, startTime, -1, 0, -1);
	default:
		return Event();
	}