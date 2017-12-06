// InverseCaptcha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    std::wstring input;

    std::wcin >> input;

    for (wchar_t& c : input)
    {
        wprintf(L"%c", c);
    }
    wprintf(L"\n");

    return 0;
}

