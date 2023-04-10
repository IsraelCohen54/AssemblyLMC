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

using TwoBytesCHAR = std::array<unsigned char, 2>;

std::optional< std::vector<int> > ReadIntFromFile(std::ifstream& fileToReadFrom);
void PrintFromVectorOfInts(std::vector<int> a_nums);
void PrintFromVectorToOpCodes(std::vector<int> a_nums);

TwoBytesCHAR Decode(int a_num);
int Encode(TwoBytesCHAR a_array);

void WriteIntVectorToBinaryFile(std::vector<int> nums, std::string a_fileNameToWrite);
void PrintBinaryFile(std::string a_fileNameToWrite);








