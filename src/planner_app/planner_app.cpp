#include <wx/wx.h>

#include "planner_app.h"
#include "main_frame.h"


#include "event.h"


using std::cout;
using std::endl;

bool PlannerApp::OnInit()
{
    cout << "OnInit: Initializing Planner app..." << endl;

    cout << "Initializing local data..." << endl;
    initData();


    MainFrame *mainFrame = new MainFrame(
        "Plan My Week",
        wxPoint(50, 50),
        wxSize(450, 340),
        this
    );

    mainFrame->Show(true);
    return true;
}

bool PlannerApp::initData() {
    vector<string> localData = {
        "CMPE 146,Lecture for embedded systems,140,900,1120,0,0",
        "CMPE 135,Lecture for Object Oriented Design,75,1345,1500,0,0",
        "Lunch,Lunch Time,60,1200,1300,2,0",
        "Dinner,Dinner Time,60,1800,1900,2,0",
        "Workout,Workout Time,60,1900,2000,3,0",
        "Sleep,Sleep Time,450,100,-1,1,1",
        "CMPE 146,Lecture for embedded systems,140,900,1120,0,2",
        "CMPE 135,Lecture for Object Oriented Design,75,1345,1500,0,2",
        "Lunch,Lunch Time,60,1200,1300,2,2",
        "Dinner,Dinner Time,60,1800,1900,2,2",
        "Workout,Workout Time,60,1900,2000,3,2",
        "Sleep,Sleep Time,450,100,-1,1,2",
        "Lunch,Lunch Time,60,1200,1300,2,3",
        "Dinner,Dinner Time,60,1800,1900,2,3",
        "Sleep,Sleep Time,450,100,-1,1,3",
        "CMPE 146,Lecture for embedded systems,140,900,1120,0,4",
        "Lunch,Lunch Time,60,1200,1300,2,4",
        "Dinner,Dinner Time,60,1800,1900,2,4",
        "Sleep,Sleep Time,450,100,-1,1,4",
        "Lunch,Lunch Time,60,1200,1300,2,5",
        "Dinner,Dinner Time,60,1800,1900,2,5",
        "Sleep,Sleep Time,450,100,-1,1,5",
        "Lunch,Lunch Time,60,1200,1300,2,6",
        "Dinner,Dinner Time,60,1800,1900,2,6",
        "Play Games,Time to play Val,60,-1,-1,5,-1",
        "Shopping,Getting new Drip,60,-1,-1,5,-1"
    };

    string filename = "./src/scheduler/testfile.txt";
	fm.open_file(filename);
    
    // while (!fm.eof()) {
    //     scheduler.push_event(fm.get_event());
    // }

    for (int i = 0; i < localData.size(); i++) {
        scheduler.push_event(fm.convert_event(localData[i]));
    }

    fm.close_file();

    scheduler.make_schedule();

    return true;
}


// Create a new application object.
wxIMPLEMENT_APP(PlannerApp);
