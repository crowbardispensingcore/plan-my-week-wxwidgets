#pragma once

#include <wx/wx.h>

#include <iostream>
#include <vector>

#include "scheduler.h"
#include "file_manager.h"
#include "event_factory.h"

class PlannerApp: public wxApp
{
public:
    virtual bool OnInit() override;
    bool initData();
// private:
    FileManager fm;
    Scheduler scheduler;
    EventFactory eventFactory;
    
};
