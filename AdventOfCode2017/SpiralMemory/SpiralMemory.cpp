// SpiralMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


long int ringForNumber(_In_ long int target)
{
    // The ring is the square root of the target, minus 1, divided by 2, then rounded up
    double targetDouble = target;
    targetDouble = sqrt(targetDouble);
    targetDouble -= 1.0;
    targetDouble /= 2.0;

    return static_cast<long int>(ceil(targetDouble));
}

void getStartForRing(_In_ long int ring, _Out_ long int& ringStart, _Out_ long int& startX, _Out_ long int& startY)
{
    if (ring == 0)
    {
        ringStart = 1;
        startX = 0;
        startY = 0;
    }
    else
    {
        // Rings end at the ring number squared plus 1. The next ring starts one more than that
        long int prevRing = ring - 1;
        ringStart = 2 * prevRing;
        ringStart++;
        ringStart *= ringStart;
        ringStart++;

        // The coordinates for this number are one space to the right from the last number in the inner ring
        // Rings will end at (ring, -ring)
        startX = prevRing + 1;
        startY = -prevRing;
    }
}

int main()
{
    std::wstring row;
    std::getline(std::wcin, row);

    long int target = wcstol(row.c_str(), nullptr, 10);
    long int ring = ringForNumber(target);

    long int ringStart = 0;
    long int startX = 0;
    long int startY = 0;
    getStartForRing(ring, ringStart, startX, startY);

    wprintf(L"%d is in ring %d\n", target, ring);
    wprintf(L"Ring %d starts with %d at (%d, %d)\n", ring, ringStart, startX, startY);
    //wprintf(L"%d is at (%d, %d)\n", target, ring, ring);

    return 0;
}

