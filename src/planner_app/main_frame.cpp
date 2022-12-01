#include <iostream>
#include <wx/wx.h>
#include "main_frame.h"

using namespace std;

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Hello,    MainFrame::OnHello)
    EVT_MENU(ID_Bonjour,  MainFrame::OnBonjour)
    EVT_MENU(ID_GutenTag, MainFrame::OnGutenTag)
    EVT_MENU(wxID_ABOUT,  MainFrame::OnAbout)
    EVT_MENU(wxID_EXIT,   MainFrame::OnExit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title,
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

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    cout << "OnExit: Exiting Hello World app!" << endl;
    Close(true);
}

void MainFrame::OnHello(wxCommandEvent& event)
{
    wxMessageBox("Hello, world!",
                 "OnHello", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBonjour(wxCommandEvent& event)
{
    wxMessageBox("Bonjour, monde!",
                 "OnBonjour", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnGutenTag(wxCommandEvent& event)
{
    wxMessageBox("Guten Tag, Welt!",
                 "OnGutenTag", wxOK | wxICON_INFORMATION);
}
