#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <optional>
#include <cassert>  // TODO [ar] twice! notice that it's unneeded, better add "#include<>" only when you need it
#include "Dict2.h"

// TODO [ar] namespace always! I know you might don't like it too much, but it's important...
namespace experis
{

std::string  StripLeft(std::string a_string);
bool IsLebal(std::string a_lineOfCode);

std::array<std::string, 3> ProcessAssemblyLineData(const std::string& a_assemblyLine);
std::optional< std::vector <std::string> > TextFileToVector(std::string a_fileNameRead);
Dict2 LabelDictFromVector(std::vector<std::string> a_File);


} //experis namespace