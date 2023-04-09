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
    const Dict2 a_OpCodes{std::vector<itemType>{{"HLT", 0}, {"ADD", 1}, {"SUB", 2}, {"STA", 3}, {"STO", 3},
        {"LDA", 5}, {"BRA", 6}, {"BRZ", 7}, {"BRP", 8}, {"INP", 9}, {"OUT", 9}, {"OTC", 9}, {"DAT", -1111111}}};  //TODO DAT???

    std::array<std::string, 3> res1 = experis::ProcessAssemblyLineData("one dat 1");
    std::array<std::string, 3> res2 = experis::ProcessAssemblyLineData("two dat     2");
    std::array<std::string, 3> res3 = experis::ProcessAssemblyLineData(" three     dat one ");
    std::array<std::string, 3> res4 = experis::ProcessAssemblyLineData(" three   dat  k ");
    // sec Test:
    std::array<std::string, 3> res5 = experis::ProcessAssemblyLineData("  dat 1");
    std::array<std::string, 3> res6 = experis::ProcessAssemblyLineData("dat     2");
    std::array<std::string, 3> res7 = experis::ProcessAssemblyLineData("       inp one ");
    std::array<std::string, 3> res8 = experis::ProcessAssemblyLineData(" dat  k ");
    experis::ShowLineDataToClient(res8);

    Dict2 a_dict;
    a_dict.Append("one", 1);
    a_dict.Append("two", 2);
    a_dict.Append("tree", 3);
    a_dict.Append("four", 4);
    //a_dict.Append("two", 7);
    
    std::cout << a_dict.Size()<<"\n";
    std::cout << a_dict.Val("one") << "\n";
    std::cout << a_dict.Val("two") << "\n";
    std::cout << a_dict.Val("four") << "\n";
    std::cout << a_dict.Val("2") << "\n";

    //std::cout << StripLeft("  jgvj hjbgkbh  ")<< "\n";
    //std::cout << StripLeft("werrt") << "\n";

    //this purt is the test for  
    //std::string a_string = "werrt";
    //StripLeft(a_string)
}