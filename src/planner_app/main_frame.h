#pragma once

#include <wx/wx.h>

#include <string>

#include "event.h"
#include "planner_app.h"

using std::string;

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, PlannerApp* app);

private:
    PlannerApp* app;

    wxSizer* mainFrameSizer;
    wxPanel* dayPanels[7];

    void addNewDayPanel(wxSizer* parentSizer, string day, int index);
    void addNewEventPanel(wxSizer* parentSizer, wxPanel* parentPanel, std::list<Event>::iterator it);

    // Events
    void onHello(wxCommandEvent& event);
    void onAbout(wxCommandEvent& event);
    void onExit(wxCommandEvent& event);
    void onCreateNewEvent(wxCommandEvent& event);

    void initMenu();
};

enum
{
    Id_CreateNewEvent = 1
};
