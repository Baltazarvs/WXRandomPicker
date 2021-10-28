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

#ifndef APPFRAME_H
#define APPFRAME_H
#include <wx/wx.h>

class AppFrame : public wxFrame
{
public:
	AppFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	wxListBox* main_lb;
	wxTextCtrl* item_insert_textarea;
	wxButton* button_insert;
	wxButton* button_pick;
	wxButton* button_delete;
	wxStatusBar* main_status;
	
private:
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnInsert(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnPick(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

enum
{
	ID_About = 1,
	ID_Insert,
	ID_Pick,
	ID_Delete,
	ID_Button_Insert,
	ID_Button_Pick,
	ID_Button_Delete,
	ID_TEXT_Main,
	ID_LIST_Main
};

#endif
