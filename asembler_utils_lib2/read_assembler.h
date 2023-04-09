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

void StripLeft(std::string& a_string);
bool IsLabel(std::string a_lineOfCode);

std::array<std::string, 3> ProcessAssemblyLineData(const std::string& a_assemblyLine);
std::optional< std::vector <std::string> > TextFileToVector(std::string a_fileNameRead);
Dict2 LabelDictFromVector(const std::vector<std::string>& a_File);


} //experis namespace