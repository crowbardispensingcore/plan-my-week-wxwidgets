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
	//reorders days of the week based on how population of events low to high
	void reorder_busy();
	int convert_time(int time);
	int find_startTime(int index);
	void push_timeConflict(event e);
	void make_schedule();
	void print_schedule();
	int find_end_index(int start_index, int duration);
	int convert_duration(int dur);
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
