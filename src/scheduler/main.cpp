// #include <iostream>
// #include <fstream>
// #include <string>
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <vector>
// #include "scheduler.h"
// #include "event.h"
// #include "file_manager.h"

// using namespace std;
// int main() {
// 	string filename = "testfile.txt";
// 	fileManager FM;
// 	FM.open_file(filename);

// 	scheduler mainScheduler;

// 	while (!FM.eof()) {
// 		mainScheduler.push_event(FM.get_event());
// 	}
// 	mainScheduler.make_schedule();
// 	mainScheduler.print_schedule();


// 	FM.close_file();
	
// }