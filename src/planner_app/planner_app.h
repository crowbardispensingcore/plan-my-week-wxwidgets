#ifndef HELLOWORLDAPP_H_
#define HELLOWORLDAPP_H_

#include <iostream>
#include <wx/wx.h>

using namespace std;

class PlannerApp: public wxApp
{
public:
    virtual bool OnInit() override;
};

#endif /* HELLOWORLDAPP_H_ */
