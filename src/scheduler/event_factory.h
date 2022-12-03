#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include <string>
#include "event.h"

class EventFactory {
public:
	//default constructor 
	EventFactory();
	//creates and returns a new custom event 
	Event create_custom_event(string name, string description, int duration, int startTime, int endTime, int priority, int specificDay);
	Event create_param_event(int option, int duration, int startTime);
private:
};
#endif