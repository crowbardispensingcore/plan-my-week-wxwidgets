#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <utility>
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
	int convert_time(int time);
	void push_timeConflict(event e);
	void reorder_busy();
	void make_schedule();
private:
	vector<vector<int>> times;
	vector<pair<int, int>>busy;
	vector<list<event>> events;
	//priority event queue(eq) for storing events
	priority_queue<event> eq;
	stack<event>timeConflicts;

	pair<int, int> search_time();
};
#endif
