#pragma once

#include <iostream>
#include <string>
using namespace std;

class Time{
    public:
        //Virtual Function
        Time(){}
        virtual int getMinutes()=0;
        virtual int getHours()=0;
        virtual string mil_to_std(int time)=0;
};
