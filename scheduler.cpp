#include "scheduler.h"
#include <list>
#include <vector>
#include "event.h"

using namespace std;
scheduler::scheduler() {
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
void scheduler::reorder_busy() {
	int i, key, j;
	for (i = 1; i < 7; i++)
	{
		key = busy[i].second;
		j = i - 1;

		while (j >= 0 && busy[j].second > key)
		{
			busy[j + 1].second = busy[j].second;
			j = j - 1;
		}
		busy[j + 1].second = key;
	}
}
pair<int, int> scheduler::search_time() {
	event temp = eq.top();
	int duration = temp.get_duration();
	int startTime = temp.get_startTime();
	int endTime = temp.get_endTime();
	int specificDay = temp.get_specificDay();

	pair<int, int> returnValue;

	if (specificDay != -1) {
		if (startTime != -1) {
			for (int i = convert_time(startTime); i < 96; i++) {
				if (times[specificDay][i] != 0) {
					returnValue.first = specificDay;
					returnValue.second = -1;
					return returnValue;
				}
			}
			returnValue.first = specificDay;
			returnValue.second = convert_time(startTime);
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
						returnValue.second = convert_time(startTime);
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
						returnValue.second = convert_time(startTime);
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
						returnValue.second = convert_time(temp_start);
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
						returnValue.second = convert_time(temp_start);
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
void scheduler::make_schedule() {
	event e;
	int durationSize;
	while (!eq.empty()) {
		e = eq.top();
		durationSize = e.get_duration() / 15;
		pair<int, int> curr_event = search_time();
		if (curr_event.second == -1) {
			push_timeConflict(eq.top());
		}
		else {
			for (int i = 0; i < durationSize; i++) {
				times[curr_event.first][curr_event.second] = 1;
			}
		}
		eq.pop();
	}
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
	timeConflicts.push(e);
}