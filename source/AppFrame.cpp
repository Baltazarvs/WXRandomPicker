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

#include "AppFrame.h"
#include <sstream>

AppFrame::AppFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size), main_lb(nullptr)
{
	wxMenu* menu_picker = new wxMenu;
	menu_picker->Append(ID_Pick, "&Pick", "Random picks the item.");
	menu_picker->Append(ID_Insert, "&Insert", "Inserts item that is specified in field.");
	menu_picker->Append(ID_Delete, "&Delete", "Delete selected item from list.");
	menu_picker->AppendSeparator();
	menu_picker->Append(wxID_EXIT, "&Exit\tAlt-F4", "Exit this app.");

	wxMenu* menu_help = new wxMenu;
	menu_help->Append(ID_About, "&About", "About this program.");	
	
	wxMenuBar* menu_bar = new wxMenuBar;
	menu_bar->Append(menu_picker, "&Picker");
	menu_bar->Append(menu_help, "&Help");
	SetMenuBar(menu_bar);

	int widths[] = { 300, 200 };
	main_status = CreateStatusBar(2);
	main_status->SetFieldsCount(2, widths);
	main_status->SetStatusWidths(2, widths);
	
	wxBoxSizer* top_side_sizer = new wxBoxSizer(wxVERTICAL);
	
	top_side_sizer->Add(this->main_lb = new wxListBox(this, ID_LIST_Main, wxDefaultPosition, wxDefaultSize), 1, wxEXPAND, 0);
	top_side_sizer->Add(this->item_insert_textarea = new wxTextCtrl(this, ID_TEXT_Main, wxEmptyString, wxDefaultPosition, wxDefaultSize), 0, wxEXPAND, 0);
	top_side_sizer->Add(this->button_pick = new wxButton(this, ID_Button_Pick, "PICK", wxDefaultPosition, wxDefaultSize), 0, wxEXPAND, 0);
	top_side_sizer->Add(this->button_insert = new wxButton(this, ID_Button_Insert, "Insert", wxDefaultPosition, wxDefaultSize), 0, wxEXPAND, 0);
	top_side_sizer->Add(this->button_delete = new wxButton(this, ID_Button_Delete, "Delete", wxDefaultPosition, wxDefaultSize), 0, wxEXPAND, 0);
	SetSizer(top_side_sizer);
	
	srand(time(nullptr));
	return;
}

void AppFrame::OnExit(wxCommandEvent& event)
{
	int confirm = wxMessageBox("Do you really want to exit?", "Exit?", wxYES_NO | wxICON_QUESTION);
	if(confirm == wxYES)
		Close(true);
	return;
}

void AppFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("Created 2021 Baltazarus.\nIt\'s free. Do whatever you want with it.", "About", wxOK | wxICON_INFORMATION);
	return;
}

void AppFrame::OnPick(wxCommandEvent& event)
{
	if(this->main_lb->GetCount() < 2)
		wxMessageBox("Specify at least two items for picking.", "Item Needed", wxOK | wxICON_INFORMATION);
	else
	{
		wxString string_temp = this->main_lb->GetString(rand() % this->main_lb->GetCount());
		wxMessageBox(string_temp, "Item Picked", wxOK | wxICON_INFORMATION);
		std::ostringstream oss;
		oss << "Last Picked: " << string_temp;
		this->main_status->SetStatusText(oss.str().c_str(), 1);
	}
	return;
}

void AppFrame::OnInsert(wxCommandEvent& event)
{
	wxString str_temp = this->item_insert_textarea->GetLineText(0);
	std::string len_tmp(str_temp);
	if(str_temp.length() < 1)
		wxMessageBox("Specify something to be able to insert.", "Specify?", wxOK | wxICON_INFORMATION);
	else
	{
		wxArrayString str_arr;
		str_arr.Add(this->item_insert_textarea->GetLineText(0));
		this->main_lb->InsertItems(str_arr, 0);
		this->item_insert_textarea->Clear();
	}
	return;
}

void AppFrame::OnDelete(wxCommandEvent& event)
{
	if(this->main_lb->GetSelection() == wxNOT_FOUND)
		wxMessageBox("No item selected for deleting.", "Cannot Delete", wxOK | wxICON_INFORMATION);
	else
		this->main_lb->Delete(this->main_lb->GetSelection());
	return;
}
