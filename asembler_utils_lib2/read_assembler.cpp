#include "pch.h"
#include "read_assembler.h"


namespace experis
{

std::string  StripLeft(std::string a_string)
{
	size_t numOfSpasies = 0;
	for (char corrChar : a_string)
	{
		if (corrChar == ' ')
		{
			++numOfSpasies;
		}
		else
		{
			a_string.erase(0, numOfSpasies);
			return a_string;
		}
	}
}

//TODO if i make this function active it giving me an linker eror im sure it something stupid i 
//will be happy if you can take a look at this 


bool IsLebal(std::string a_lineOfCode)
	{
		
		std::array<std::string, 13> legalCommands{ "HLT", "ADD", "SUB", "STA", "STO",
			"LDA", "BRA", "BRZ", "BRP", "INP", "OUT", "OTC", "DAT" };
		for (std::string command : legalCommands)
		{
		if (a_lineOfCode.starts_with(command)) 
			{
				return false;
			}
		//std::find(legalCommands.begin(), legalCommands.end(), command.substr(0, 2));
	}
		return true;
}

std::array<std::string, 3> ProcessAssemblyLineData(const std::string& a_assemblyLine)
{
	std::array<std::string, 3> lineAssemblyData{ std::string{""}, std::string{""}, std::string{""} };
	for (int i = 0, stringCounter = 0 ; i < a_assemblyLine.size() ; ++i)
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
		result.push_back(untrustedFileLine);
		std::getline(fileToReadFrom, untrustedFileLine);
	}
	result.push_back(untrustedFileLine);
	return result;
}

Dict2 LabelDictFromVector(std::vector<std::string> a_File)
{
	Dict2 resoult{};
	size_t counter = 0;
	for (std::string line : a_File)
	{
		std::string lebelText = ProcessAssemblyLineData(line).at(0);
		if (lebelText == "")
		{
			++counter;
			continue;
		}
		resoult.Append(lebelText, counter);
		++counter;
	}
}

} //experis namespace