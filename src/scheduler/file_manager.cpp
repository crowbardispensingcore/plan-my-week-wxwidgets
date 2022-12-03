#include "file_manager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
//default constructor 
FileManager::FileManager() {
    file_opened = false;
}
//opens a input file given filename
void FileManager::open_file(string filename) {
    ifs.open(filename);
    if (ifs.fail()) {
        cout << "ERROR! " << filename << " opening failure" << endl;
        exit(1);
    }
    file_opened = true;
    return;
}
//closes the current input file 
void FileManager::close_file() {
    if (!file_opened) {
        cout << "ERROR! No file currently opened" << endl;
    }
    else {
        ifs.close();
        file_opened = false;
    }
}
//retrieves next event in opened file and returns an event object
Event FileManager::get_event() {
    if (!file_opened) {
        cout << "ERROR! No file currently opened" << endl;
        exit(1);
    }
    else {
        string line;
        while (getline(ifs, line)) {
            return convert_event(line);
        }
    }
}
//converts event data from string to event object
Event FileManager::convert_event(string s) {
    vector<string> vars;
    stringstream ss(s);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        vars.push_back(substr);
    }
    Event e(vars[0], vars[1], stoi(vars[2]), stoi(vars[3]), stoi(vars[4]), stoi(vars[5]), stoi(vars[6]));
    return e;
}
//checks if input file stream has reached end of file
bool FileManager::eof() {
    if (ifs.eof()) {
        return true;
    }
    else {
        return false;
    }
}