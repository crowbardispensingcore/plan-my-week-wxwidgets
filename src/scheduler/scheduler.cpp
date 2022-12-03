#include "scheduler.h"
#include <list>
#include <vector>
#include "event.h"

using namespace std;
Scheduler::Scheduler() {
	times.resize(7);
	events.resize(7);
	busy.resize(7);
	for (int i = 0; i < 7; i++) {
		busy[i].first = i;
		busy[i].second = 0;
		for (int j = 0; j < 96; j++) {
			times[i].push_back(0);
		}
	}
}
void Scheduler::create_event() {

}
//pushes event into priority queue based on priority
void Scheduler::push_event(Event e) {
	eq.emplace(e);
}
//pops event at top of priority queue
void Scheduler::pop_event() {
	eq.pop();
}
//returns event at top of priority queue
Event Scheduler::top() {
	return eq.top();
}
//reorders days of the week based on how population of events low to high
//Uses Insertion Sort 
void Scheduler::reorder_busy() {
	int i, j;
	pair<int, int> key;
	for (i = 1; i < 7; i++)
	{
		key = busy[i];
		j = i - 1;

		while (j >= 0 && busy[j].second > key.second)
		{
			busy[j + 1] = busy[j];
			j = j - 1;
		}
		busy[j + 1] = key;
	}
}
//converts military time to index of vector to represent that time
int Scheduler::time_to_idx(int time) {
	int first, second, third, fourth, final;
	final = 0;
	first = time / 1000;
	second = (time - first * 1000) / 100;
	third = ((time - first * 1000) - (second * 100)) / 10;
	fourth = ((time - first * 1000) - (second * 100)) - (third * 10);

	int hour, minutes;
	hour = first * 10 + second;
	hour *= 60;
	minutes = third * 10 + fourth;
	final = hour + minutes;

	return (final / 15) - 1;
}
//converts index of vector to military time
int Scheduler::idx_to_time(int index) {
	int startTime = (index + 1) * 15;  //time in minutes 
	int hour = startTime / 60;
	int minute = startTime % 60;

	startTime = hour * 100;
	startTime += minute;
	return startTime;
}
//calculates index of event end time in vector 
int Scheduler::calc_end_idx(int start_index, int duration) {
	int returnvalue = start_index;
	int temp = duration;
	returnvalue += temp / 15;
	if (temp % 15 != 0) {
		returnvalue += 1;
	}
	return returnvalue;
}
//calculates and returns length of duration in terms of vector index sizing
int Scheduler::dur_length(int dur) {
	int duration = dur;
	duration = duration / 15;
	duration *= 15;
	if (dur % 15 != 0) {
		duration += 15;
	}
	return duration;
}
//searches for next optimal and available spot in schedule for an event and returns the day and time as a pair
pair<int, int> Scheduler::search_time() {
	Event curr_event = eq.top();
	int duration = dur_length(curr_event.get_duration());
	int startTime = curr_event.get_startTime();
	int endTime = curr_event.get_endTime();
	int specificDay = curr_event.get_specificDay();

	pair<int, int> returnValue;

	if (specificDay != -1) {    //if there is a specific day requested
		if (startTime != -1) {  //if there is a specific start time requested
			int start_index = time_to_idx(startTime);
			int end_index = calc_end_idx(start_index, duration);
			for (int i = start_index; i <= end_index; i++) {
				if (times[specificDay][i] != 0) {
					returnValue.first = specificDay;
					returnValue.second = -1;
					return returnValue;
				}
			}
			returnValue.first = specificDay;
			returnValue.second = time_to_idx(startTime);
			return returnValue;
		}
		else {
			int temp_duration = duration;
			int temp_start = 32;
			for (int i = 32; i < 96; i++) {
				if (times[specificDay][i] != 0) {
					temp_duration = duration;
					if (i < 95) {
						temp_start = i + 1;
					}
				}
				else {
					temp_duration -= 15;
					if (temp_duration == 0) {
						returnValue.first = specificDay;
						returnValue.second = temp_start;
						return returnValue;
					}
				}
			}
			temp_start = 0;
			for (int i = 0; i < 32; i++) {
				if (times[specificDay][i] != 0) {
					temp_duration = duration;
					if (i < 31) {
						temp_start = i + 1;
					}
				}
				else {
					temp_duration -= 15;
					if (temp_duration == 0) {
						returnValue.first = specificDay;
						returnValue.second = temp_start;
						return returnValue;
					}
				}
			}
			returnValue.first = specificDay;
			returnValue.second = -1;
			return returnValue;
		}
	}
	else {
		int temp_duration = duration;
		int temp_start = 32;
		reorder_busy();
		for (int j = 0; j < 7; j++) {
			for (int i = 32; i < 96; i++) {
				if (times[busy[j].first][i] != 0) {
					temp_duration = duration;
					if (i < 95) {
						temp_start = i + 1;
					}
				}
				else {
					temp_duration -= 15;
					if (temp_duration == 0) {
						returnValue.first = busy[j].first;
						returnValue.second = temp_start;
						return returnValue;
					}
				}
			}
			temp_start = 0;
			for (int i = 0; i < 32; i++) {
				if (times[busy[j].first][i] != 0) {
					temp_duration = duration;
					if (i < 31) {
						temp_start = i + 1;
					}
				}
				else {
					temp_duration -= 15;
					if (temp_duration == 0) {
						returnValue.first = busy[j].first;
						returnValue.second = temp_start;
						return returnValue;
					}
				}
			}
		}
		returnValue.first = -1;
		returnValue.second = -1;
		return returnValue;
	}
}
//creates schedule based on priority of events 
void Scheduler::make_schedule() {
	Event e;
	int durLength;
	list<Event>::iterator it;
	while (eq.size() > 1) {
		e = eq.top();
		durLength = dur_length(e.get_duration()) / 15;
		pair<int, int> curr_event = search_time();
		if (curr_event.first != -1 && curr_event.second != -1) {
			e.set_startTime(idx_to_time(curr_event.second));
			e.set_endTime(idx_to_time(curr_event.second + durLength));
			e.set_specificDay(curr_event.first);
			for (int i = 0; i < 7; i++) {
				if (busy[i].first == curr_event.first) {
					busy[i].second += durLength;
					break;
				}
			}
		}
		if (curr_event.second == -1) {
			push_timeConflict(eq.top());
		}
		else {
			for (int i = curr_event.second; i < curr_event.second + durLength; i++) {
				times[curr_event.first][i] = 1;
			}
			it = events[curr_event.first].begin();
			if (events[curr_event.first].empty()) {
				events[curr_event.first].push_back(e);
			}
			else {
				while (e.get_endTime() > it->get_startTime()) {
					it++;
					if (it == events[curr_event.first].end()) {
						break;
					}
				}
				events[curr_event.first].emplace(it, e);
			}
		}
		eq.pop();
	}
}
//prints the weeks schedule onto terminal
void Scheduler::print_schedule() {
	list<Event>::iterator it;
	string day;
	for (int i = 0; i < 7; i++) {
		it = events[i].begin();
		switch (i) {
		case 0:
			cout << "Monday" << endl;
			break;
		case 1:
			cout << "Tuesday" << endl;
			break;
		case 2:
			cout << "Wednesday" << endl;
			break;
		case 3:
			cout << "Thursday" << endl;
			break;
		case 4:
			cout << "Friday" << endl;
			break;
		case 5:
			cout << "Saturday" << endl;
			break;
		case 6:
			cout << "Sunday" << endl;
			break;
		default:
			break;
		}
		for (it = events[i].begin(); it != events[i].end(); ++it) {
			it->print_event();
			cout << endl;
		}
		cout << endl;
	}
	if (!timeConflicts.empty()) {
		cout << "TIME CONFLICTS" << endl;
		while (!timeConflicts.empty()) {
			timeConflicts.top().print_event();
			cout << endl;
			timeConflicts.pop();
		}
	}
}
//pushes event with time conflict onto time conflict stack
void Scheduler::push_timeConflict(Event e) {
	timeConflicts.push(e);
}