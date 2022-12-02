#pragma once

#include <wx/wx.h>

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
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
