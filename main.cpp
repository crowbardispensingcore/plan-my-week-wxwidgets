#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "scheduler.h"
#include "event.h"

using namespace std;
event convertEvent(string s) {   //test code to convert a string into a event object 
	vector<string> vars;
	stringstream ss(s);
	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		vars.push_back(substr);
	}
	event e(vars[0], vars[1], stoi(vars[2]), stoi(vars[3]), stoi(vars[4]), stoi(vars[5]), stoi(vars[6]));
	return e;
}
int main() {
	ifstream ifs;
	string filename = "testfile.txt";
	string line;
	ifs.open(filename);

	if (ifs.fail()) {
		cout << "ERROR! " << filename << " opening failure" << endl;
		exit(1);
	}
	while (getline(ifs, line)) {
		event e = convertEvent(line);
		e.print_event();   //print the elements of a event object
	}
	ifs.close();
}