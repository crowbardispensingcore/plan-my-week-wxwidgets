#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <fstream>
#include "event.h"

using namespace std;

class fileManager {
public:
    fileManager();
    void open_file(string filename);    //opens a given filename
    void close_file();    //closes the current open file 
    event get_event();    //retrieves next event in opened file and returns an event object
private:
    ifstream ifs;
    ofstream ofs;
    bool file_opened;

    event convert_event(string s);    //converts comma seperated line into event object
};
#endif
