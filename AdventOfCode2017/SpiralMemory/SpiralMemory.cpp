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

    long int ring = static_cast<long int>(ceil(targetDouble));
    wprintf(L"%d is in ring %d\n", target, ring);

    return ring;
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

    wprintf(L"Ring %d starts with %d at (%d, %d)\n", ring, ringStart, startX, startY);
}

enum class SpiralDirection
{
    Up,
    Left,
    Down,
    Right,
};

void getPositionForTarget(_In_ long int target, _Out_ long int& x, _Out_ long int& y)
{
    long int ring = ringForNumber(target);

    long int i = 0;

    getStartForRing(ring, i, x, y);

    SpiralDirection currentDirection = SpiralDirection::Up;
    i++;

    for (; i <= target; i++)
    {
        switch (currentDirection)
        {
            case SpiralDirection::Up:
                y++;
                if (y == ring)
                {
                    currentDirection = SpiralDirection::Left;
                }
                break;
            case SpiralDirection::Left:
                x--;
                if (x == -ring)
                {
                    currentDirection = SpiralDirection::Down;
                }
                break;
            case SpiralDirection::Down:
                y--;
                if (y == -ring)
                {
                    currentDirection = SpiralDirection::Right;
                }
                break;
            case SpiralDirection::Right:
                x++;
                break;
        }
    }

    wprintf(L"%d is at (%d, %d)\n", target, x, y);
}

long int getDistanceForTarget(_In_ long int target)
{
    long int x = 0;
    long int y = 0;
    getPositionForTarget(target, x, y);

    long int distance = abs(x);
    distance += abs(y);

    wprintf(L"%d is %d steps away from the center\n", target, distance);

    return distance;
}

int main()
{
    std::wstring row;
    std::getline(std::wcin, row);

    long int target = wcstol(row.c_str(), nullptr, 10);

    getDistanceForTarget(target);

    return 0;
}

