#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <optional>
#include <cassert>
#include <algorithm>
#include "Dict2.h"

namespace experis
{
const Dict2 commandDict{ std::vector<ItemType>{ {"HLT", "0"}, {"ADD", "1"}, {"SUB", "2"},
{"STA", "3"}, {"STO", "3"}, {"LDA", "5"}, {"BRA", "6"}, {"BRZ", "7"}, {"BRP", "8"},
{"INP", "901"}, {"OUT", "902"}, {"OTC", "922"},{"DAT", ""}} };

std::string StripLeft(std::string a_string);
std::string Upper(const std::string& a_string);
bool IsNumeric(std::string a_string);
bool IsLabel(std::string a_lineOfCode);

std::array<std::string, 3> ProcessAssemblyLineData(const std::string& a_assemblyLine);
std::optional< std::vector <std::string> > TextFileToVector(std::string a_fileNameRead);
Dict2 LabelDictFromVector(const std::vector<std::string>& a_File);
std::string AsemblyLineToCode(std::string a_asemblyLine, Dict2 a_labelDict);
void PrintAsemblyCode(const std::vector<std::string>& a_File, Dict2 a_labelDict);


} //experis namespace