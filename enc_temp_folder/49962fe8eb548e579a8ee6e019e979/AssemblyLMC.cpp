#include <iostream>
#include "read_assembler.h"

namespace experis
{

} // experis namespace

int main()
{
    std::cout << "Hello Worchgvjbknlk;mld2!\n";

    std::array<std::string, 3> res1 = experis::ProcessAssemblyLineData("one dat 1");
    std::array<std::string, 3> res2 = experis::ProcessAssemblyLineData("two dat     2");
    std::array<std::string, 3> res3 = experis::ProcessAssemblyLineData(" three     dat one ");
    std::array<std::string, 3> res4 = experis::ProcessAssemblyLineData(" three   dat  k ");
    int k = 5;
}