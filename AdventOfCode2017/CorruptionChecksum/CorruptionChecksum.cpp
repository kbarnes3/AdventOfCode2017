// CorruptionChecksum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    std::wstring row;
    while (std::getline(std::wcin, row))
    {
        if (row.length() > 0)
        {
            wprintf(L"Row: %s\n", row);
        }
    }
    return 0;
}

