#pragma once

#include <wx/wx.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class AddNewEventDialog : public wxDialog {
public:
    AddNewEventDialog(
        wxWindow *parent, wxWindowID id,
        const wxString &title,
        const wxPoint &pos = wxDefaultPosition,
        const wxSize &size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE,
        const wxString &name = wxASCII_STR(wxDialogNameStr)
    );

private:
    string eventName;
    string description;
    int day;
    vector<bool> repeatingDays;
    int startTime;
    int endTime;
    int durationMinute;
    int priority;
};