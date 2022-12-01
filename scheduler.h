#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <queue>
#include "event.h"
class scheduler {
public:
	scheduler();
	void create_event();
	//pushes event into priority queue based on priority
	void push_event(event e);    
	//pops event at top of priority queue
	void pop_event();   
	//returns event at top of priority queue
	event top();
	void append_event();
	bool empty();
private:
	vector<vector<int>> times;
	vector<list<event>> events;
	//priority event queue(eq) for storing events
	priority_queue<event> eq; 

	int search_time();
};
#endif
