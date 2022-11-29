#include "scheduler.h"
#include <list>
#include <vector>
#include "event.h"

using namespace std;
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
schedule::schedule() {
	times.resize(7);
	events.resize(7);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 96; j++) {
			times[i].push_back(0);
		}
	}
}
