/***********************************************************************************

   Created 2021 Baltazarus
   
   This code is part of my wxWidgets simple program series
   where I demonstrate how good C++ is for other GUI API-s.
   Now this program is simple. Just fill up the field, 
   click Insert. Repeat this two times because random select requires
   at least 2 items.
   Pick will select randomly item from that list, and display
   a wxMessageBox with text that contains item the Pick randomly
   selected. Delete will delete selected item in wxListBox. 
   
   Btw, copy it and edit, it's free :)
   
***********************************************************************************/

#include "MainApp.h"

wxBEGIN_EVENT_TABLE(AppFrame, wxFrame)
	EVT_BUTTON(ID_Button_Pick, AppFrame::OnPick)
	EVT_BUTTON(ID_Button_Insert, AppFrame::OnInsert)
	EVT_BUTTON(ID_Button_Delete, AppFrame::OnDelete)
	EVT_MENU(ID_Pick, AppFrame::OnPick)
	EVT_MENU(ID_Insert, AppFrame::OnInsert)
	EVT_MENU(ID_Delete, AppFrame::OnDelete)
	EVT_MENU(wxID_EXIT, AppFrame::OnExit)
	EVT_MENU(ID_About, AppFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MainApp);
