#include "pch.h"
#include "read_assembler.h"


namespace experis
{

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

} //experis namespace