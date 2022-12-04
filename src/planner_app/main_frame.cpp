#include <iostream>

#include "main_frame.h"
#include "add_new_event_dialog.h"


using std::cout;
using std::endl;

MainFrame::MainFrame(const wxString& title,
                 const wxPoint& pos, const wxSize& size, PlannerApp* app)
    : 
    wxFrame(NULL, wxID_ANY, title, pos, size),
    app(app)
{
    initMenu();

    mainFrameSizer = new wxBoxSizer(wxHORIZONTAL);
    mainFrameSizer->AddSpacer(50);


    // Monday panel
    // wxSizer* monSizer = new wxBoxSizer(wxVERTICAL);
    // wxPanel* monPanel = new wxPanel(this, wxID_ANY);
    // monSizer->AddSpacer(20);
    // monSizer->Add(new wxStaticText(monPanel, wxID_ANY, "Monday"), 0, wxALIGN_CENTER, 0);
    // monSizer->AddSpacer(20);
    // for (int i = 0; i < 10; i++) {
    //     addNewEventPanel(monSizer, monPanel);
    // }
    // monPanel->SetSizer(monSizer);
    // mainFrameSizer->Add(monPanel);
    // mainFrameSizer->AddSpacer(50);


    addNewDayPanel(mainFrameSizer, "Monday", 0);
    addNewDayPanel(mainFrameSizer, "Tuesday", 1);
    addNewDayPanel(mainFrameSizer, "Wednesday", 2);
    addNewDayPanel(mainFrameSizer, "Thursday", 3);
    addNewDayPanel(mainFrameSizer, "Friday", 4);
    addNewDayPanel(mainFrameSizer, "Saturday", 5);
    addNewDayPanel(mainFrameSizer, "Sunday", 6);
    
    SetSizer(mainFrameSizer);
    Fit();
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
    AddNewEventDialog* dialog = new AddNewEventDialog(this, wxID_ANY, "Add A New Event");
    if (dialog->ShowModal() == wxID_OK) {
        wxMessageBox(
            wxString::Format(
                "Event name: %s\nEvent description: %s\n",
                dialog->name,
                dialog->description
            )
        );
        for (int i = 0; i < 7; i++) {
            dayPanels[i]->DestroyChildren();
        }
        addNewDayPanel(mainFrameSizer, "LOLOLOLOL", 0);
        SetSizer(mainFrameSizer);
        Fit();
        Refresh();
    }

    dialog->Destroy();
}

void MainFrame::addNewDayPanel(wxSizer* parentSizer, string day, int index) {
    wxSizer* daySizer = new wxBoxSizer(wxVERTICAL);
    dayPanels[index] = new wxPanel(this, wxID_ANY);
    daySizer->AddSpacer(20);
    daySizer->Add(new wxStaticText(dayPanels[index], wxID_ANY, day), 0, wxALIGN_CENTER, 0);
    daySizer->AddSpacer(20);

    std::list<Event>::iterator it;
    for (it = app->scheduler.events[index].begin(); it != app->scheduler.events[index].end(); ++it) {
        addNewEventPanel(daySizer, dayPanels[index], it);
    }
    dayPanels[index]->SetSizer(daySizer);
    parentSizer->Add(dayPanels[index]);
    parentSizer->AddSpacer(50);
}

void MainFrame::addNewEventPanel(wxSizer* parentSizer, wxPanel* parentPanel, std::list<Event>::iterator it) {
    string name = it->name;
    string description = it->description;
    int startTime = it->startTime;
    int endTime = it->endTime;
    int duration = it->duration;


    wxPanel* eventPanel = new wxPanel(parentPanel, wxID_ANY);
    eventPanel->SetMinSize(wxSize(250, 100));
    eventPanel->SetBackgroundColour(wxColor(75, 186, 134));
    wxSizer* eventSizer = new wxBoxSizer(wxVERTICAL);

    // Event name
    wxStaticText* eventLabel = new wxStaticText(eventPanel, wxID_ANY, name);
    eventLabel->SetForegroundColour(wxColor(*wxBLACK));
    eventSizer->Add(eventLabel, 0, wxALIGN_CENTER, 0);

    eventSizer->AddSpacer(5);
    
    // Event time
    wxStaticText* timeLabel = new wxStaticText(
        eventPanel, wxID_ANY,
        wxString::Format("%d ~ %d", startTime, endTime)
    );
    timeLabel->SetForegroundColour(wxColor(*wxBLACK));
    eventSizer->Add(timeLabel, 0, wxALIGN_CENTER, 0);
    // Event duration
    wxStaticText* durationLabel = new wxStaticText(
        eventPanel, wxID_ANY,
        wxString::Format("%d minutes", duration)
    );
    durationLabel->SetForegroundColour(wxColor(*wxBLACK));
    eventSizer->Add(durationLabel, 0, wxALIGN_CENTER, 0);

    eventSizer->AddSpacer(5);

    // Event duration
    wxStaticText* descriptionLabel = new wxStaticText(
        eventPanel, wxID_ANY,
        wxString::Format("  %s", description)
    );
    descriptionLabel->SetForegroundColour(wxColor(*wxBLACK));
    descriptionLabel->Wrap(parentPanel->GetSize().GetX());
    eventSizer->Add(descriptionLabel, 0, wxALIGN_CENTER, 0);

    eventPanel->SetSizer(eventSizer);

    parentSizer->Add(eventPanel);
    parentSizer->AddSpacer(20);
}