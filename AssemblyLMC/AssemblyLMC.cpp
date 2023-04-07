#include <iostream>
#include "read_assembler.h"

namespace experis
{

void ShowLineDataToClient(const std::array<std::string, 3>& a_lmcData)
{
    for (const std::string& str : a_lmcData)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

} // experis namespace

int main(int argc, const char **argv)
{
    using namespace experis;
    // TODO DELETE: TEST CASES: (V all)
    //std::array<std::string, 3> res1 = experis::ProcessAssemblyLineData("one dat 1");
    //std::array<std::string, 3> res2 = experis::ProcessAssemblyLineData("two dat     2");
    //std::array<std::string, 3> res3 = experis::ProcessAssemblyLineData(" three     dat one ");
    //std::array<std::string, 3> res4 = experis::ProcessAssemblyLineData(" three   dat  k ");
    //experis::ShowLineDataToClient(res4);

    Dict2 a_dict;
    a_dict.Append("one", 1);
    a_dict.Append("two", 2);
    a_dict.Append("tree", 3);
    a_dict.Append("four", 4);
    a_dict.Append("two", 7);

    std::cout << a_dict.Size()<<"\n";
    std::cout << a_dict.Val("one") << "\n";
    std::cout << a_dict.Val("two") << "\n";
    std::cout << a_dict.Val("four") << "\n";
    std::cout << a_dict.Val("2") << "\n";




}