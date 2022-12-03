#include "add_new_event_dialog.h"

AddNewEventDialog::AddNewEventDialog(
    wxWindow *parent, wxWindowID id,
    const wxString &title,
    const wxPoint &pos,
    const wxSize &size,
    long style,
    const wxString &name
) :
    wxDialog(parent, id, title, pos, size, style, name),
    name("New Event"),
    description("A new event is created."),
    day(0),
    repeatingDays(7, false),
    startTime(900),
    endTime(1030),
    durationMinute(startTime - endTime),
    priority(3),
    nameInputCtrl(nullptr),
    descriptionInputCtrl(nullptr),
    dayChoice(nullptr),
    repeatingDaysInputCtrl(nullptr),
    startTimeInputCtrl(nullptr),
    endTimeInputCtrl(nullptr),
    priorityChoice(nullptr)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    
    
    const int labelWidth = 150;
    // name
    wxBoxSizer* nameSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* nameLabel = new wxStaticText(this, wxID_ANY, "Event Name");
    nameLabel->SetMinSize(wxSize(labelWidth, nameLabel->GetMinHeight()));
    nameSizer->Add(nameLabel);
    nameInputCtrl = new wxTextCtrl(this, wxID_ANY);
    nameSizer->Add(nameInputCtrl, 1);
    mainSizer->Add(nameSizer, 0, wxEXPAND | wxALL, 5);

    // description
    wxBoxSizer* descriptionSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* descriptionLabel = new wxStaticText(this, wxID_ANY, "Event Description");
    descriptionLabel->SetMinSize(wxSize(labelWidth, descriptionLabel->GetMinHeight()));
    descriptionSizer->Add(descriptionLabel);
    descriptionInputCtrl = new wxTextCtrl(this, wxID_ANY);
    descriptionSizer->Add(descriptionInputCtrl, 1);
    mainSizer->Add(descriptionSizer, 0, wxEXPAND | wxALL, 5);

    // day choice
    wxBoxSizer* daySizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* dayLabel = new wxStaticText(this, wxID_ANY, "Day of Event");
    dayLabel->SetMinSize(wxSize(labelWidth, dayLabel->GetMinHeight()));
    daySizer->Add(dayLabel);
    wxArrayString daysOfWeek;
    daysOfWeek.push_back("Monday");
    daysOfWeek.push_back("Tuesday");
    daysOfWeek.push_back("Wednesday");
    daysOfWeek.push_back("Thursday");
    daysOfWeek.push_back("Friday");
    daysOfWeek.push_back("Saturday");
    daysOfWeek.push_back("Sunday");
    dayChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, daysOfWeek);
    daySizer->Add(dayChoice);
    mainSizer->Add(daySizer, 0, wxEXPAND | wxALL, 5);

    // repeating days
    wxBoxSizer* repeatingDaysSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* repeatingDaysLabel = new wxStaticText(this, wxID_ANY, "Repeat");
    repeatingDaysLabel->SetMinSize(wxSize(labelWidth, repeatingDaysLabel->GetMinHeight()));
    repeatingDaysSizer->Add(repeatingDaysLabel);
    // repeatingDaysInputCtrl = new wxTextCtrl(this, wxID_ANY);
    // repeatingDaysSizer->Add(repeatingDaysInputCtrl, 1);
    monCheckBox = new wxCheckBox(this, wxID_ANY, "MON");
    tueCheckBox = new wxCheckBox(this, wxID_ANY, "TUE");
    wedCheckBox = new wxCheckBox(this, wxID_ANY, "WED");
    thuCheckBox = new wxCheckBox(this, wxID_ANY, "THU");
    friCheckBox = new wxCheckBox(this, wxID_ANY, "FRI");
    satCheckBox = new wxCheckBox(this, wxID_ANY, "SAT");
    sunCheckBox = new wxCheckBox(this, wxID_ANY, "SUN");
    repeatingDaysSizer->Add(monCheckBox);
    repeatingDaysSizer->Add(tueCheckBox);
    repeatingDaysSizer->Add(wedCheckBox);
    repeatingDaysSizer->Add(thuCheckBox);
    repeatingDaysSizer->Add(friCheckBox);
    repeatingDaysSizer->Add(satCheckBox);
    repeatingDaysSizer->Add(sunCheckBox);
    mainSizer->Add(repeatingDaysSizer, 0, wxEXPAND | wxALL, 5);

    // start time
    wxBoxSizer* timeSizer = new wxBoxSizer(wxHORIZONTAL);
    // wxBoxSizer* startTimeSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* startTimeLabel = new wxStaticText(this, wxID_ANY, "Start Time ~ End Time");
    startTimeLabel->SetMinSize(wxSize(labelWidth, startTimeLabel->GetMinHeight()));
    timeSizer->Add(startTimeLabel);
    startTimeInputCtrl = new wxTextCtrl(this, wxID_ANY);
    timeSizer->Add(startTimeInputCtrl, 1);
    // mainSizer->Add(startTimeSizer, 0, wxEXPAND | wxALL, 5);
    wxStaticText* timeInputSplitLabel = new wxStaticText(this, wxID_ANY, "    ~    ");
    timeSizer->Add(timeInputSplitLabel);
    // end time
    // wxBoxSizer* endTimeSizer = new wxBoxSizer(wxHORIZONTAL);
    // wxStaticText* endTimeLabel = new wxStaticText(this, wxID_ANY, "End Time");
    // endTimeLabel->SetMinSize(wxSize(80, endTimeLabel->GetMinHeight()));
    // timeSizer->Add(endTimeLabel);
    endTimeInputCtrl = new wxTextCtrl(this, wxID_ANY);
    timeSizer->Add(endTimeInputCtrl, 1);
    mainSizer->Add(timeSizer, 0, wxEXPAND | wxALL, 5);

    // priority
    wxBoxSizer* prioritySizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* priorityLabel = new wxStaticText(this, wxID_ANY, "Priority (Smaller Number = Higher Priority)");
    priorityLabel->SetMinSize(wxSize(labelWidth + 120, priorityLabel->GetMinHeight()));
    prioritySizer->Add(priorityLabel);
    wxArrayString priorities;
    priorities.push_back("0");
    priorities.push_back("1");
    priorities.push_back("2");
    priorities.push_back("3");
    priorities.push_back("4");
    priorityChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, priorities);
    prioritySizer->Add(priorityChoice);
    mainSizer->Add(prioritySizer, 0, wxEXPAND | wxALL, 5);


    // Modal buttons
    wxSizer* modalButtonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(modalButtonSizer, 0, wxALIGN_RIGHT | wxBOTTOM, 5);

    SetSizer(mainSizer);
    SetMinSize(wxSize(400, 100));
    Fit();
}

void AddNewEventDialog::onClickOkUpdate() {

}

bool AddNewEventDialog::TransferDataFromWindow() {
    name = nameInputCtrl->GetValue();
    description = descriptionInputCtrl->GetValue();
    day = dayChoice->GetSelection();

    return true;
}