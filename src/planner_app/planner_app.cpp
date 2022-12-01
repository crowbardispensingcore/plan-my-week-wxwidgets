#include <wx/wx.h>
#include "planner_app.h"
#include "HelloWorldFrame.h"

using namespace std;

bool PlannerApp::OnInit()
{
    cout << "OnInit: Initializing Planner app..." << endl;

    HelloWorldFrame *frame = new HelloWorldFrame("Hello World",
                                                 wxPoint(50, 50),
                                                 wxSize(450, 340) );
    frame->Show(true);
    return true;
}

// Create a new application object.
wxIMPLEMENT_APP(PlannerApp);
