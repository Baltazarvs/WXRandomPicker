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

bool MainApp::OnInit()
{
	AppFrame* main_frame = new AppFrame("WXRandomPicker v1.0", wxPoint(100, 100), wxSize(800, 600));
	main_frame->Show(true);
	return true;
}
