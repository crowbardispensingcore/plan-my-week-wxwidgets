#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "scheduler.h"
#include "event.h"
#include "file_manager.h"
#include "event_factory.h"

using namespace std;
int main() {
	string filename = "testfile.txt";
	FileManager FM;
	FM.open_file(filename);

	Scheduler mainScheduler;
	EventFactory evntFac;

	while (!FM.eof()) {
		mainScheduler.push_event(FM.get_event());
	}
	mainScheduler.make_schedule();

	mainScheduler.push_event(evntFac.create_custom_event("Walk Dog", "Time to walk the doggy", 60, -1, -1, 5, -1));
	mainScheduler.make_schedule();
	mainScheduler.print_schedule();


	FM.close_file();
	
}