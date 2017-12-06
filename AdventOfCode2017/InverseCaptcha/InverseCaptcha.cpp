// InverseCaptcha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int char_to_int(wchar_t c)
{
    switch (c)
    {
        case L'0':
            return 0;
        case L'1':
            return 1;
        case L'2':
            return 2;
        case L'3':
            return 3;
        case L'4':
            return 4;
        case L'5':
            return 5;
        case L'6':
            return 6;
        case L'7':
            return 7;
        case L'8':
            return 8;
        case L'9':
            return 9;
        default:
            return -1;
    }
}

int main()
{
    std::wstring input;

    std::wcin >> input;

    int firstNumber = 0;
    int previousNumber = -1;
    int sum = 0;

    firstNumber = char_to_int(input[0]);

    for (wchar_t& c : input)
    {
        int number = char_to_int(c);
        if (number == previousNumber)
        {
            sum += number;
        }

        previousNumber = number;
    }
    
    if (previousNumber == firstNumber)
    {
        sum += firstNumber;
    }

    wprintf(L"%d", sum);

    return 0;
}

