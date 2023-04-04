#include "pch.h"
#include "read_assembler.h"

bool IsLebal(std::string a_lineOfCode)
{
	std::array<std::string, 13> legalComands{ "HLT", "ADD", "SUB", "STA", "STO",
		"LDA", "BRA", "BRZ", "BRP", "INP", "OUT", "OTC", "DAT" };
	for (std::string command : legalComands)
	{
		if (a_lineOfCode.starts_with(command))
		{
			return false;
		}
		//std::find(legalComands.begin(), legalComands.end(), command.substr(0, 2));
	}
	return true;

}