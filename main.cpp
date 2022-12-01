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
	mainScheduler.push_event(FM.get_event());    //this line gets the next event from testfile
	mainScheduler.top().print_event();           //this line gets the event from top of queue and prints it to terminal
	mainScheduler.pop_event();                   //this line pops the top event from queue

	/*while (!FM.eof()) {
		mainScheduler.push_event(FM.get_event());
	}*/
	/*while (!mainScheduler.empty()) {
		mainScheduler.top().print_event();
		mainScheduler.pop_event();
	}*/

	FM.close_file();
	
}