#include <iostream>
#include "read_assembler.h"
#include "read_file.h"

namespace experis
{

static constexpr bool FILE_BINARY_OUTPUT = true;
static constexpr bool FILE_TXT_OUTPUT = false;

void ShowLineDataToClient(const std::array<std::string, 3>& a_lmcData)
{
    for (const std::string& str : a_lmcData)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void TestDict()
{
    Dict2 a_dict;
    a_dict.Append("one", "1");
    a_dict.Append("two", "2");
    a_dict.Append("tree", "3");
    a_dict.Append("four", "4");
    //a_dict.Append("two", "7");

    std::cout << a_dict.Size() << "\n";
    std::cout << a_dict.Val("one") << "\n";
    std::cout << a_dict.Val("two") << "\n";
    std::cout << a_dict.Val("four") << "\n";
    std::cout << a_dict.Val("2") << "\n";
}

void TestStripLeft()
{
    std::cout << StripLeft("  jgvj hjbgkbh  ") << "->";
    std::cout << StripLeft("werrt  ghjj") << "->";

    std::string a_string = "werrt";
    std::cout<<StripLeft(a_string)<<"->";
}

void TestUpper()
{
    std::vector<std::string> test{ "fghh"," fchgjjh ", "    ", "", "GH jh IHY ", "788", " 666 ",
    "gg 9 IG 7 bhkjh7UY" };
    for (std::string a_string : test)
    {
        std::cout << a_string << "->" << Upper(a_string) << "\n";
    }
}

void TestProcessAssemblyLineData()
{
    std::array<std::string, 3> res1 = experis::ProcessAssemblyLineData("one dat 1");
    std::array<std::string, 3> res2 = experis::ProcessAssemblyLineData("two dat     2");
    std::array<std::string, 3> res3 = experis::ProcessAssemblyLineData(" three     dat one ");
    std::array<std::string, 3> res4 = experis::ProcessAssemblyLineData(" three   dat  k ");
    //sec Test:
    std::array<std::string, 3> res5 = experis::ProcessAssemblyLineData("  dat 1");
    std::array<std::string, 3> res6 = experis::ProcessAssemblyLineData("dat     2");
    std::array<std::string, 3> res7 = experis::ProcessAssemblyLineData("       inp one ");
    std::array<std::string, 3> res8 = experis::ProcessAssemblyLineData(" dat  k ");
}

std::vector<std::string> TestTextFileToVector(std::string a_fileNameRead)
{
    std::optional< std::vector <std::string> > lines= TextFileToVector(a_fileNameRead);
    if (lines.has_value())
    {
        for (std::string line : lines.value())
        {
            std::cout << line << "\n";
        }
        return lines.value();
    }
    else
    {
        std::cout << "file not found";
        return{};
    }
}

struct FileWrongInputCommandsException : std::exception
{
    experis::FileWrongInputCommandsException(const std::string& a_cmd);
    std::string m_cmd;
};

FileWrongInputCommandsException::FileWrongInputCommandsException(const std::string& a_cmd)
: m_cmd{a_cmd}
{
}

void CheckBinFlag(const std::string& a_type)
{
    if (a_type != "/bin")
    {
        throw(FileWrongInputCommandsException(a_type));
    }
}

std::string ChangeExtension(std::string a_extention, std::string a_path)
{
    a_path = a_path.substr(0,a_path.size() - 3);
    a_path += a_extention;
    return a_path;
}

} // experis namespace

int main(int argc, const char **argv)
{
    using namespace experis;
    bool isBoolOutput{};
    std::string path = argv[1]; // TODO check if argv exist & valid
    std::optional<std::vector<std::string>> fileDataInVec{TextFileToVector(path)};
    if (fileDataInVec.has_value())
    {
        if (argc == 2)
        {
            bool isBoolOutput = FILE_TXT_OUTPUT;
            path = ChangeExtension("lmc", path);
        }
        else if (argc == 3)
        {
            CheckBinFlag(std::string(argv[2]));
            path = ChangeExtension("bin", path);
            isBoolOutput = FILE_BINARY_OUTPUT;
        }
        else if (argc == 4)
        {
            path = std::string(argv[2]);
            bool isBoolOutput = FILE_TXT_OUTPUT;
        }
        else if (argc == 5)
        {
            CheckBinFlag(std::string(argv[2]));
            path = std::string(argv[3]);
            isBoolOutput = FILE_BINARY_OUTPUT;
        }
        else 
        {   //TODO add throw expeption...
            std::cout << "wrong input numbers of arguments";
        }
        Dict2 labelDict = LabelDictFromVector(fileDataInVec.value());
        WriteFileAsemblyCode(fileDataInVec.value(), labelDict, path, isBoolOutput);
        //PrintBinaryFile(path); // only if binary output => (argc == 3 || 5)
    }
    else
    {   //TODO add throw expeption...
        std::cout << "file is vacant\n";
    }
    return 0;
}

//std::vector<std::string> test{ TestTextFileToVector("sample.asm") };
//Dict2 labalDict = LabelDictFromVector(test);
//labalDict.PrintDict();
//  PrintAsemblyCode(test, labalDict);
//TestUpper();
//commandDict.PrintDict();
//TestStripLeft();
//experis::ShowLineDataToClient(res8);