#include "pch.h"
#include "read_assembler.h"

namespace experis
{

bool IsLebal(std::string a_lineOfCode)
{
	std::array<std::string, 13> legalCommands{ "HLT", "ADD", "SUB", "STA", "STO",
		"LDA", "BRA", "BRZ", "BRP", "INP", "OUT", "OTC", "DAT" };
	for (std::string command : legalCommands) //Todo [ar] add '&'! consider const as well.
	{
		//TODO [ar] when you PUSH your work, make sure it would compile before you do so
		// , as otherwise it would make it hard for other programmer to check their work 
		// with compiler... || ...
		//              ... \/ ...
		/*if (a_lineOfCode.starts_with(command)) 
		{
			return false;
		}*/
		//std::find(legalCommands.begin(), legalCommands.end(), command.substr(0, 2));
	}
	return true;

}

std::array<std::string, 3> ProcessAssemblyLineData(const std::string& a_assemblyLine)
{
	std::string label{""};  
	std::string opCode{""};
	std::string usedLabelOrMemAdress{""};

	for (int i = 0 ; i < a_assemblyLine.size() ; ++i)
	{
		if (a_assemblyLine.at(i) == ' ')
		{
			continue;
		}
		// TODO [is] check if OP code...
	}
	return std::array<std::string, 3> {label, opCode, usedLabelOrMemAdress};
}

} //experis namespace