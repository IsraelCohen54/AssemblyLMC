#include "pch.h"
#include "read_assembler.h"

namespace experis
{

std::string StripLeft(std::string a_string)
{
	size_t numOfSpacies = 0;

	for (char corrChar : a_string)
	{
		if (corrChar == ' ')
		{
			++numOfSpacies;
			continue;
		}
		a_string.erase(0, numOfSpacies);
		return a_string;
	}
	a_string.erase(0, numOfSpacies);
	return a_string;
}

std::string Upper(const std::string& a_string)
{
	std::string resoult{};
	for (char c : a_string)
	{
		resoult += toupper(c);
	}
	return resoult;
}

bool IsLabel(std::string a_lineOfCode)
{
	
	std::array<std::string, 13> legalCommands{ "HLT", "ADD", "SUB", "STA", "STO",
		"LDA", "BRA", "BRZ", "BRP", "INP", "OUT", "OTC", "DAT" };
	for (std::string command : legalCommands)
	{
		//std::for_each(a_lineOfCode.begin(), a_lineOfCode.end(), [](char & c){ c = ::toupper(c); });
		if (a_lineOfCode.starts_with(command)) 
		{
			return false;
		}
	//std::find(legalCommands.begin(), legalCommands.end(), command.substr(0, 2));
	}
	return true;
}

std::array<std::string, 3> ProcessAssemblyLineData(const std::string& a_assemblyLine)  //TODO [is] CONST REFERENCE + TESTINGS
{
	std::array<std::string, 3> lineAssemblyData{ std::string{""}, std::string{""}, std::string{""} };
	for (int i = 0, stringCounter = int(!IsLabel(a_assemblyLine)) ; i < a_assemblyLine.size() ; ++i)  // !IsLebal as if label exist = start from zero to hold the label
	{
		if (a_assemblyLine.at(i) == ' ')
		{
			continue;
		}
		for ( ; i != a_assemblyLine.size() && a_assemblyLine.at(i) != ' ' ; ++i)
		{
			lineAssemblyData[stringCounter] += a_assemblyLine.at(i);
		}
		++stringCounter;
	}
	return lineAssemblyData;
}

std::optional< std::vector <std::string> > TextFileToVector(std::string a_fileNameRead)
{

	std::ifstream fileToReadFrom{ a_fileNameRead };
	std::vector<std::string> result;
	if (!fileToReadFrom.good())
	{
		std::cout << "Not good - file not found\n";
		return{};
	}
	std::string untrustedFileLine;
	std::getline(fileToReadFrom, untrustedFileLine);
	while (!fileToReadFrom.eof())
	{
		untrustedFileLine = StripLeft(untrustedFileLine);
		untrustedFileLine = Upper(untrustedFileLine);
		result.push_back(untrustedFileLine);
		std::getline(fileToReadFrom, untrustedFileLine);
	}
	result.push_back(untrustedFileLine);
	return result;
}

Dict2 LabelDictFromVector(const std::vector<std::string>& a_File)
{
	Dict2 resoult{};
	size_t counter = 0;
	for (const std::string& line : a_File)
	{
		std::string lebelText = ProcessAssemblyLineData(line).at(0);
		if (lebelText == "")
		{
			++counter;
			continue;
		}
		resoult.Append(lebelText, std::to_string(counter));
		++counter;
	}
	return resoult;
}

} //experis namespace