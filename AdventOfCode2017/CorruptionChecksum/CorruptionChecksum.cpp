// CorruptionChecksum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace boost;

using wtokenizer = tokenizer<char_separator<wchar_t>, std::wstring::const_iterator, std::wstring>;

int main()
{
    std::wstring row;
    char_separator<wchar_t> tab_sep(L"\t");
    while (std::getline(std::wcin, row))
    {
        if (row.length() > 0)
        {
            wprintf(L"Row: ");
            wtokenizer tokens(row, tab_sep);

            for (const std::wstring& s : tokens)
            {
                long int cell = wcstol(s.c_str(), nullptr, 10);
                wprintf(L"(%d) ", cell);
            }
            wprintf(L"\n");
        }
    }
    return 0;
}

