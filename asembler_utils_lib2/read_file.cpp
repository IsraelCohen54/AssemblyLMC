
#include "read_file.h"


std::optional< std::vector<int> > ReadIntFromFile(std::ifstream& fileToReadFrom)
{
	std::vector<int> result;
	if (!fileToReadFrom.good())
	{
		std::cout << "Not good - file not found\n";
		return{};
	}
	std::string untrust_fileText;
	std::getline(fileToReadFrom, untrust_fileText);
	while (!fileToReadFrom.eof())
	{
		if (!GetIntFromString(untrust_fileText).has_value())
		{
			return{};
		}
		result.push_back(GetIntFromString(untrust_fileText).value());
		std::getline(fileToReadFrom, untrust_fileText);
	}
	result.push_back(GetIntFromString(untrust_fileText).value());
	return result;
}

void PrintFromVectorOfInts(std::vector<int> a_nums)
{
	for (int num : a_nums)
	{
		std::cout << num << '\n';
	}
}

void PrintFromVectorToOpCodes(std::vector<int> a_nums)
{
	size_t inomirator = 0;
	for (int num : a_nums)
	{
		std::cout << num << "\t->" << inomirator << "\t" << IntToOpCode(num) << '\n';
		++inomirator;
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

void WriteIntVectorToBinaryFile(std::vector<int> nums, std::string a_fileNameToWrite)
{
	std::ofstream binaryFile{ a_fileNameToWrite, std::ios_base::binary };
	for (int num : nums)
	{
		TwoBytesCHAR NumInBytes = Decode(num);
		binaryFile.put(NumInBytes.at(0));
		binaryFile.put(NumInBytes.at(1));
	}
}

void PrintBinaryFile(std::string a_binaryFileNameToReadFron)
{
	std::ifstream binaryFile{ a_binaryFileNameToReadFron, std::ios_base::binary };
	int MSB = binaryFile.get();
	int LSB = binaryFile.get();
	TwoBytesCHAR numInBytes{ MSB,LSB };
	int num = Encode(numInBytes);
	std::cout << num << "\n";
	while (!binaryFile.eof())
	{
		MSB = binaryFile.get();
		LSB = binaryFile.get();
		TwoBytesCHAR numInBytes{ MSB,LSB };
		num = Encode(numInBytes);
		std::cout << num << "\n";
	}
}

void ReadLabelsFromFile(std::string a_libalsFileName)
{
	std::ifstream fileToReadFrom{ a_libalsFileName };
	if (!fileToReadFrom.good())
	{
		std::cout << "Not good - file not found\n";
		return;
	}
	std::string untrustedFileLine;
	std::getline(fileToReadFrom, untrustedFileLine);
	std::array <std::string, 100> dataLabels{ "" };
	while (untrustedFileLine != "DATA")
	{
		if (untrustedFileLine.starts_with(":"))
		{
			std::string lableName = untrustedFileLine.substr(1, std::string::end);
		}
	}
}