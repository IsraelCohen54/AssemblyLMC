#pragma once

#include "framework.h"

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <optional>
#include <cassert>
#include <array>
#include <cassert>
#include "read_assembler.h" // used for writing file after reading it...

namespace experis
{

using TwoBytesCHAR = std::array<unsigned char, 2>;

void PrintFromVectorOfInts(std::vector<int> a_nums);
TwoBytesCHAR Decode(int a_num);
int Encode(TwoBytesCHAR a_array);

void WriteStrVectorToBinaryFile(std::vector<std::string> nums, std::string a_fileNameToWrite);
void WriteFileAsemblyCode(std::vector<std::string> a_fileDataInVec, Dict2& a_labelDict, std::string& a_path, bool a_isBinaryOutput);
void PrintBinaryFile(std::string a_fileNameToWrite);

} //experis namespace