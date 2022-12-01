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

	if (specificDay != -1) {
		if (startTime != -1) {
			for (int i = convert_time(startTime); i < 96; i++) {

			}
		}
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

int scheduler::convert_time(int time) {
	int first, second, third, fourth, final;
	final = 0;
	first = time / 1000;
	second = (time - first * 1000) / 100;
	third = ((time - first * 1000) - (second * 100)) / 10;
	fourth = ((time - first * 1000) - (second * 100)) - (third * 10);

	int hour , minutes;
	hour = first * 10 + second;
	hour *= 60;
	minutes = third * 10 + fourth;
	final = hour + minutes;

	return (final / 15)-1;

	return 0;
}
void scheduler::push_timeConflict(event e) {
	timeConflicts.emplace(e);
}