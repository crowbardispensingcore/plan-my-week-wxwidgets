#include <wx/wx.h>
#include "planner_app.h"
#include "main_frame.h"

#include "scheduler.h"
#include "event.h"
#include "file_manager.h"

using namespace std;

bool PlannerApp::OnInit()
{
    cout << "OnInit: Initializing Planner app..." << endl;

    MainFrame *mainFrame = new MainFrame(
        "Plan My Week",
        wxPoint(50, 50),
        wxSize(450, 340)
    );

    mainFrame->Show(true);
    return true;
}


// Create a new application object.
wxIMPLEMENT_APP(PlannerApp);
