#include "pch.h"
#include "read_file.h"

namespace experis
{

void PrintFromVectorOfInts(std::vector<int> a_nums)
{
	for (int num : a_nums)
	{
		std::cout << num << '\n';
	}
}

TwoBytesCHAR Decode(int a_num)
{
	assert(a_num >= 0 && a_num <= USHRT_MAX);
	unsigned char MSB = a_num / 256;
	unsigned char LSB = a_num % 256;
	return TwoBytesCHAR{ MSB, LSB };
}

int Encode(TwoBytesCHAR a_array)
{
	return a_array[0] * 256 + a_array[1];
}

void WriteStrVectorToBinaryFile(std::vector<std::string> a_nums, std::string a_fileNameToWrite)
{
	std::ofstream binaryFile{ a_fileNameToWrite, std::ios_base::binary };
	for (std::string str : a_nums)
	{
		if (str == "\n")
		{
			continue;
		}
		int num = std::stoi(str);
		TwoBytesCHAR NumInBytes = Decode(num);
		binaryFile.put(NumInBytes.at(0));
		binaryFile.put(NumInBytes.at(1));
	}
	return;
}

void WriteFileAsemblyCode(std::vector<std::string> a_fileDataInVec, Dict2& a_labelDict, std::string& a_path, bool a_isBinaryOutput)
{
	std::ofstream txtFileWriter{ a_path };
	std::vector<std::string> assemblyNums{};
	if (a_isBinaryOutput)
	{
		for (const std::string& line : a_fileDataInVec)
		{
			if (line == "")
			{
				continue;
			}
			assemblyNums.push_back(AsemblyLineToCode(line, a_labelDict) + "\n");
		}
		WriteStrVectorToBinaryFile(assemblyNums, a_path);
	}
	else
	{
		for (const std::string& line : a_fileDataInVec)
		{
			if (line == "")
			{
				continue;
			}
			txtFileWriter << AsemblyLineToCode(line, a_labelDict) << "\n";
		}
	}
}

void PrintBinaryFile(std::string a_binaryFileNameToReadFron)
{
	std::ifstream binaryFile{ a_binaryFileNameToReadFron, std::ios_base::binary };
	int MSB = binaryFile.get();
	int LSB = binaryFile.get();
	TwoBytesCHAR numInBytes{ unsigned char(MSB), unsigned char(LSB) };
	int num = Encode(numInBytes);
	std::cout << num << "\n";
	while (!binaryFile.eof())
	{
		MSB = binaryFile.get();
		LSB = binaryFile.get();
		TwoBytesCHAR numInBytes{ unsigned char(MSB), unsigned char(LSB) };
		num = Encode(numInBytes);
		std::cout << num << "\n";
	}
}

} //experis namespace
