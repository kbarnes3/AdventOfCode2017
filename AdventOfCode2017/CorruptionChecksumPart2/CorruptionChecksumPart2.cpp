// CorruptionChecksumPart2.cpp : Defines the entry point for the console application.
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
            std::set<long int> cells;

            for (const std::wstring& cell : tokens)
            {
                long int cellNumber = wcstol(cell.c_str(), nullptr, 10);
                wprintf(L"(%d) ", cellNumber);
                cells.insert(cellNumber);
            }
            std::set<long int>::const_reverse_iterator bigNumber = cells.crbegin();
            while (bigNumber != cells.crend())
            {
                std::set<long int>::const_reverse_iterator smallNumber = bigNumber;
                smallNumber++;

                while (smallNumber != cells.crend())
                {
                    long int remainder = *bigNumber % *smallNumber;
                    if (remainder == 0)
                    {
                        // Found the pair that works
                        long int quotient = *bigNumber / *smallNumber;
                        wprintf(L"| %d / %d = %d\n", *bigNumber, *smallNumber, quotient);
                        answer += quotient;
                        break;
                    }
                    smallNumber++;
                }

                // If we broke out of the inner loop early, we found what we were looking for
                if (smallNumber != cells.crend())
                {
                    break;
                }
                bigNumber++;
            }
        }
    }

    wprintf(L"Answer: %d", answer);

    return 0;
}

