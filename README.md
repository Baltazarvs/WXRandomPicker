# WXRandomPicker
This code is part of my wxWidgets simple program series where I demonstrate how good C++ is for other GUI API-s. Now this program is simple. Just fill up the field, click Insert. Repeat this two times because random select requires at least 2 items. Pick will select randomly item from that list, and display a wxMessageBox with text that contains item the Pick randomly selected. Delete will delete selected item in wxListBox. 

## What is this?

This is a simple program created in C++ with wxWidgets.
It demonstrates some functions that can be used with wxWidgets through small program.

## How to build this?

There is two known ways how to compile this manually.

## **CMake**

Create a subdirectory inside file where CMakeLists.txt is located. I would create a dir named **build**

```bash
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
./WXRandomPicker
```

And after you finished, just run WXRandomPicker like **./WXRandomPicker**.


## **G++**

BTW, you are in the cloned repository where sources are located.
```bash
cd source
g++ Main.cpp MainApp.cpp AppFrame.cpp `wx-config --cxxflags --libs` -o WXRandomPicker
./WXRandomPicker
```
For this method, you must have wxWidgets installed!

There is no many ways I can provide for teaching you how to build this. If first one fails, second will not for sure.

Created 2021 Baltazarus.
