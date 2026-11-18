#include <iostream>
#include <vector>
#include <fstream>
#include "book.h"

namespace HanYoonseo2649055
{
    void readWriteBookDataFile(std::ifstream& fin, std::ofstream& fout)
    {//fin: std::cin, fout: std::cout
        std::vector<book> v;
        std::streambuf* origBuf{std::cout.rdbuf()};
        std::cout.rdbuf(nullptr);
        while (!fin.eof())
        {
            book b;fin >> b;
            v.push_back(b);
        }
        std::cout.rdbuf(origBuf);

        for (const auto& vi : v)
        {
            fout << vi;
        }
    }
}

int main()
{
    using namespace HanYoonseo2649055;
    std::ifstream fin{ "bookData.txt" };
    if (fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        std::exit(1);
    }

    std::ofstream fout{ "out.txt" };
    if (fout.fail())
    {
        std::cout << "Output file opening failed.\n";
        std::exit(1);
    }

    readWriteBookDataFile(fin, fout);

    fin.close();
    fout.close();

    book b;
    std::streambuf* origBuf{std::cout.rdbuf()};
    std::cout.rdbuf(nullptr);
    fin >> b;
    std::cout.rdbuf(origBuf);
    std::cout << b;

    return 0;
}