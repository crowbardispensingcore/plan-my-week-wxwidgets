#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <queue>
#include "event.h"
class scheduler {
public:
	void create_event();
	void push_event(event e);
	void pop_event(event e);
	friend class schedule;
private:
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
