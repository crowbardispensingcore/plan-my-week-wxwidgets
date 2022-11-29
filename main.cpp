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

using namespace std;
int main() {
	string filename = "testfile.txt";
	fileManager FM;
	FM.open_file(filename);

	scheduler mainScheduler;
	mainScheduler.push_event(FM.get_event());
	mainScheduler.push_event(FM.get_event());

	event e = mainScheduler.top();
	e.print_event();

	mainScheduler.pop_event();

	event f = mainScheduler.top();
	f.print_event();


	FM.close_file();
	
}