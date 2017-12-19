// SpiralMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


long int ringForNumber(long int target)
{
    // The ring is the square root of the target, minus 1, divided by 2, then rounded up
    double targetDouble = target;

    return static_cast<long int>(ceil(targetDouble));
}


int main()
{
    std::wstring row;
    std::getline(std::wcin, row);

    long int target = wcstol(row.c_str(), nullptr, 10);

    wprintf(L"%d is at (%d, %d)", target, 0, 0);

    return 0;
}

