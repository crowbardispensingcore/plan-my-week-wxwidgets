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

	while (!FM.eof()) {
		mainScheduler.push_event(FM.get_event());
		mainScheduler.top().print_event();
		mainScheduler.pop_event();
	}
	/*while (!mainScheduler.empty()) {
		mainScheduler.top().print_event();
		mainScheduler.pop_event();
	}*/

	FM.close_file();
	
}