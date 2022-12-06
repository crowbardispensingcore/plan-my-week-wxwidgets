#pragma once

#include <iostream>
#include <string>
#include "time.h"

using namespace std;

class MilitaryTime : public Time{
    public:
        MilitaryTime();
        int getMinutes();
        int getHours();
        int calcDuration(MilitaryTime time1,MilitaryTime time2);
        void setMinute(int minute);
        void setHour(int hour);
        string mil_to_std(int time);
        string dur_to_std(int duration);
        MilitaryTime(string name, string description, int duration, 
		int startTime, int endTime, int priority, int specificDay);
    protected:
        double seconds;
        double minutes;
        double hours;
};