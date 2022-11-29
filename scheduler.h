#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <queue>
#include "event.h"
class scheduler {
public:
	void create_event();
	void push_event(event e);    //pushes event into priority queue based on priority
	void pop_event();    //pops event at top of priority queue
	event top();    //returns event at top of priority queue
private:
	//schedule s;
	priority_queue<event> eq;    //priority event queue(eq) for storing events
};

class schedule {
public:
	schedule();
private:
	vector<vector<int>> times;
	vector<list<event>> events;
};
#endif
