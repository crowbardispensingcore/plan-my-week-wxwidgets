#pragma once

#include "add_new_event_dialog.h"

AddNewEventDialog::AddNewEventDialog(
    wxWindow *parent, wxWindowID id,
    const wxString &title,
    const wxPoint &pos = wxDefaultPosition,
    const wxSize &size = wxDefaultSize,
    long style = wxDEFAULT_DIALOG_STYLE,
    const wxString &name = wxASCII_STR(wxDialogNameStr)
) :
    wxDialog(parent, id, title, pos, size, style, name),
    eventName("New Event"),
    description("A new event is created."),
    day(0),
    repeatingDays(7, false),
    startTime(900),
    endTime(1030),
    durationMinute(startTime - endTime),
    priority(3),
{


}