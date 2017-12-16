// CorruptionChecksum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace boost;

int main()
{
    std::wstring row;
    char_separator<wchar_t> tab_sep(L"\t");
    while (std::getline(std::wcin, row))
    {
        if (row.length() > 0)
        {
            wprintf(L"Row: %s\n", row);
            //tokenizer<char_separator<wchar_t>> tokens(row, tab_sep);
        }
    }
    return 0;
}

