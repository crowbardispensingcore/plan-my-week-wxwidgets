#include <wx/wx.h>
#include "HelloWorldApp.h"
#include "HelloWorldFrame.h"

using namespace std;

bool HelloWorldApp::OnInit()
{
    cout << "OnInit: Initializing Hello World app!" << endl;

    HelloWorldFrame *frame = new HelloWorldFrame("Hello World",
                                                 wxPoint(50, 50),
                                                 wxSize(450, 340) );
    frame->Show(true);
    return true;
}

// Create a new application object.
wxIMPLEMENT_APP(HelloWorldApp);
