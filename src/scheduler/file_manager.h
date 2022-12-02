#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <fstream>
#include "event.h"

using namespace std;

class fileManager {
public:
    //default constructor 
    fileManager();
    //opens a input file given filename
    void open_file(string filename);    
    //closes the current input file
    void close_file();   
    //retrieves next event in opened file and returns an event object
    event get_event();    
    //checks if input file stream has reached end of file
    bool eof();
private:
    ifstream ifs;    
    ofstream ofs;
    bool file_opened;
    //converts event data from string to event object
    event convert_event(string s);   
};
#endif
