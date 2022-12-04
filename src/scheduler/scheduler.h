#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <utility>
#include "event.h"
class Scheduler {
public:
	Scheduler();
	void create_event();
	//pushes event into priority queue based on priority
	void push_event(Event e);
	//pops event at top of priority queue
	void pop_event();
	//returns event at top of priority queue
	Event top();
	//reorders days of the week based on how population of events low to high
	void reorder_busy();
	//converts military time to index of vector to represent that time
	int time_to_idx(int time);
	//converts index of vector to military time
	int idx_to_time(int index);
	//calculates index of event end time in vector 
	int calc_end_idx(int start_index, int duration);
	//calculates and returns length of duration in terms of vector index sizing
	int dur_length(int dur);
	//creates schedule based on priority of events 
	void make_schedule();
	//prints the weeks schedule onto terminal
	void print_schedule();
	//pushes event with time conflict onto time conflict stack
	void print_schdedule(int day);
	void push_timeConflict(Event e);
// private:
	vector<vector<int>> times;
	vector<pair<int, int>>busy;
	vector<list<Event>> events;
	//priority event queue(eq) for storing events
	priority_queue<Event> eq;
	stack<Event>timeConflicts;
	//searches for next optimal and available spot in schedule for an event and returns the day and time as a pair
	pair<int, int> search_time();
};
#endif

