// CorruptionChecksum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace boost;

using wtokenizer = tokenizer<char_separator<wchar_t>, std::wstring::const_iterator, std::wstring>;

int main()
{
    std::wstring row;
    long int answer = 0;
    char_separator<wchar_t> tab_sep(L"\t");
    while (std::getline(std::wcin, row))
    {
        if (row.length() > 0)
        {
            wprintf(L"Row: ");
            wtokenizer tokens(row, tab_sep);
            bool firstCell = true;
            long int smallest = 0;
            long int biggest = 0;

            for (const std::wstring& cell : tokens)
            {
                long int cellNumber = wcstol(cell.c_str(), nullptr, 10);
                wprintf(L"(%d) ", cellNumber);

                if (firstCell)
                {
                    smallest = cellNumber;
                    biggest = cellNumber;
                    firstCell = false;
                }
                else
                {
                    if (cellNumber < smallest)
                    {
                        smallest = cellNumber;
                    }
                    if (cellNumber > biggest)
                    {
                        biggest = cellNumber;
                    }
                }
            }
            long int rowNumber = biggest - smallest;
            answer += rowNumber;
            wprintf(L"\n");
        }
    }

    wprintf(L"Answer: %d", answer);

    return 0;
}

