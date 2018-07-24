#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// HWID
std::string retrieved;
std::string hwid; //HWID
std::string hwid2; //Another HWID
std::string hwid3; //ANOTHER HWID
std::string hwids;
int hash; //Hashed HWID

#include "Functions.h"

int WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
	gethwid();

	std::ofstream myfile("hwid.txt");
	if (myfile.is_open())
	{
		myfile << hash;
		myfile.close();
		MessageBox(0, "HWID Succesfully Recorded!", "HWID Generation", MB_ICONINFORMATION);
	}
	else MessageBox(0, "Failed to create/modify \"hwid.txt\"!", "HWID Generation", MB_ICONERROR);
}