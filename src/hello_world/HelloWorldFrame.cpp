#include <iostream>
#include <wx/wx.h>
#include "HelloWorldFrame.h"

using namespace std;

wxBEGIN_EVENT_TABLE(HelloWorldFrame, wxFrame)
    EVT_MENU(ID_Hello,    HelloWorldFrame::OnHello)
    EVT_MENU(ID_Bonjour,  HelloWorldFrame::OnBonjour)
    EVT_MENU(ID_GutenTag, HelloWorldFrame::OnGutenTag)
    EVT_MENU(wxID_ABOUT,  HelloWorldFrame::OnAbout)
    EVT_MENU(wxID_EXIT,   HelloWorldFrame::OnExit)
wxEND_EVENT_TABLE()

HelloWorldFrame::HelloWorldFrame(const wxString& title,
                 const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Status string: Hello!");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Bonjour, "&Bonjour...\tCtrl-B",
                     "Status string: Bonjour!");
    menuFile->Append(ID_GutenTag, "&Guten Tag...\tCtrl-G",
                     "Status string: Guten Tag!");
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X",
                     "Status string: Quit Wx-helloworld");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to the Hello World app!");
}

void HelloWorldFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void HelloWorldFrame::OnExit(wxCommandEvent& event)
{
    cout << "OnExit: Exiting Hello World app!" << endl;
    Close(true);
}

void HelloWorldFrame::OnHello(wxCommandEvent& event)
{
    wxMessageBox("Hello, world!",
                 "OnHello", wxOK | wxICON_INFORMATION);
}

void HelloWorldFrame::OnBonjour(wxCommandEvent& event)
{
    wxMessageBox("Bonjour, monde!",
                 "OnBonjour", wxOK | wxICON_INFORMATION);
}

void HelloWorldFrame::OnGutenTag(wxCommandEvent& event)
{
    wxMessageBox("Guten Tag, Welt!",
                 "OnGutenTag", wxOK | wxICON_INFORMATION);
}
