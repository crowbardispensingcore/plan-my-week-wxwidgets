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
// private:
    string name;
    string description;
    int day;
    vector<bool> repeatingDays;
    int startTime;
    int endTime;
    int durationMinute;
    int priority;

    wxTextCtrl* nameInputCtrl;
    wxTextCtrl* descriptionInputCtrl;
    wxChoice* dayChoice;
    wxTextCtrl* repeatingDaysInputCtrl;
    wxTextCtrl* startTimeInputCtrl;
    wxTextCtrl* endTimeInputCtrl;
    wxChoice* priorityChoice;

    wxCheckBox* monCheckBox;
    wxCheckBox* tueCheckBox;
    wxCheckBox* wedCheckBox;
    wxCheckBox* thuCheckBox;
    wxCheckBox* friCheckBox;
    wxCheckBox* satCheckBox;
    wxCheckBox* sunCheckBox;


private:
    virtual bool TransferDataFromWindow() override;
    void onClickOkUpdate();
};