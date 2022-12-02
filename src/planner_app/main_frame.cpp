#include <iostream>

#include "main_frame.h"

using std::cout;
using std::endl;

MainFrame::MainFrame(const wxString& title,
                 const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    initMenu();

    CreateStatusBar();
    SetStatusText("Welcome to Plan My Week!");
}


void MainFrame::initMenu() {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(Id_CreateNewEvent, "Add New Event...\tCtrl-H",
                     "Add a new event to the planner");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "Exit...\tCtrl-X",
                     "Exit the application");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    this->Bind(wxEVT_MENU, &MainFrame::onCreateNewEvent, this, Id_CreateNewEvent);
    this->Bind(wxEVT_MENU, &MainFrame::onAbout, this, wxID_ABOUT);
    this->Bind(wxEVT_MENU, &MainFrame::onExit, this, wxID_EXIT);
    SetMenuBar(menuBar);
}



void MainFrame::onAbout(wxCommandEvent& event)
{
    wxMessageBox(
        "This planner application generates a weekly schedule for you based on the events you provided",
        "About Plan My Week",
        wxOK | wxICON_INFORMATION
    );
}

void MainFrame::onExit(wxCommandEvent& event)
{
    cout << "OnExit: Exiting Hello World app!" << endl;
    Close(true);
}

void MainFrame::onCreateNewEvent(wxCommandEvent& event)
{
    wxMessageBox("Hello, world!",
                 "OnHello", wxOK | wxICON_INFORMATION);
}