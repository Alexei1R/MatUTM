#include "mathpch.h"

#include "MatUTM/Core/Util/PlatformUtil.h"
#include <windows.h>
#include <string.h>
#include <iostream>
#include <codecvt>
#include <locale>
using namespace std;

namespace MatUTM {

	


	std::string FileDialogs::OpenFile(const char* filter)
	{
		

        wchar_t fileName[MAX_PATH];

        // Structure to store information about the open file dialog
        OPENFILENAME ofn;
        ZeroMemory(&ofn, sizeof(ofn));

        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = fileName;
        ofn.nMaxFile = MAX_PATH;
        ofn.lpstrFilter = L"Python Filles\0*.py\0";
        ofn.nFilterIndex = 1;
        ofn.lpstrFileTitle = NULL;
        ofn.nMaxFileTitle = 0;
        ofn.lpstrInitialDir = NULL;
        ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

        // Show the Open File Dialog
        if (GetOpenFileName(&ofn) == TRUE)
        {
            wcout << "Selected file: " << fileName << endl;
        }
        else
        {
            wcout << "Open file dialog was cancelled." << endl;
        }

        std::wstring w_string(fileName);
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
        std::string path = converter.to_bytes(w_string);
        
		return path;

	}

	

}
