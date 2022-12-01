#include "scheduler.h"
#include <list>
#include <vector>
#include "event.h"

using namespace std;
scheduler::scheduler() {
	times.resize(7);
	events.resize(7);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 96; j++) {
			times[i].push_back(0);
		}
	}
}
void scheduler::create_event() {

}
void scheduler::push_event(event e) {
	eq.emplace(e);
}
void scheduler::pop_event() {
	eq.pop();
}
event scheduler::top() {
	return eq.top();
}
void scheduler::append_event() {
	if (eq.empty()) {
		cout << "ERROR! Nothing in queue to append" << endl;
		return;
	}
	else {
		return;
	}
}
int scheduler::search_time() {
	event temp = eq.top();
	int duration = temp.get_duration();
	int startTime = temp.get_startTime();
	int endTime = temp.get_endTime();
	int specificDay = temp.get_specificDay();

	if (startTime != -1) {

	}
	if (specificDay != -1) {
		//for(int i = 32; i < )
	}
	return 0;
}

bool scheduler::empty() {
	if (eq.empty()) {
		return true;
	}
	else {
		return false;
	}
}
