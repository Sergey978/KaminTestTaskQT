#include "filerw.h"
#include <fstream>
#include <iterator>




FileRW::FileRW()
{

	inputFile.open("example.txt", std::ios::binary);
	outputFile.open("example_out.txt", std::ofstream::out);

}

std::vector<char> FileRW::readBlockFromEnd(const int beginPoint, int dataSize)
{
	std::vector<char> block;

	if (!inputFile.is_open())
	{
		std::cout << "file was not opened \n";
		return block;
	}

	// Stop eating new lines in binary mode!!!
	inputFile.unsetf(std::ios::skipws);

	// get file size:
	std::streampos fileSize = getFileSize();

	// reserve capacity
	block.reserve(dataSize);

	// read the data:
	if (beginPoint <= fileSize)
	{
		inputFile.seekg(-beginPoint, std::ios_base::end);
		char *buff = new  char[dataSize];
		inputFile.read(buff, dataSize);
		block.insert(block.begin(), buff, buff + dataSize);
		delete[]buff;
	}

    return block;
}

std::vector<char> FileRW::readBlockFromBegin(const int beginPoint, int dataSize)
{
    std::vector<char> block;

    if (!inputFile.is_open())
    {
        std::cout << "file was not opened \n";
        return block;
    }

    // Stop eating new lines in binary mode!!!
    inputFile.unsetf(std::ios::skipws);

    // get file size:
    std::streampos fileSize = getFileSize();

    // reserve capacity
    block.reserve(dataSize);

    // read the data:
    if (beginPoint <= fileSize)
    {
        inputFile.seekg(beginPoint, std::ios_base::beg);
        char *buff = new  char[dataSize];
        inputFile.read(buff, dataSize);
        block.insert(block.begin(), buff, buff + dataSize);
        delete[]buff;
    }

    return block;
}





void FileRW::writeBlock(std::vector<char> data, int dataSize)
{

	if (!outputFile)
	{
		std::cout << "file not \n\n";
	}

	for (int i = 0; i < dataSize; i++)
		outputFile << data[i];

}

long FileRW::getFileSize()
{

	if (!inputFile.is_open())
	{
		std::cout << "file was not opened \n";
	}

	std::streampos fileSize;
	inputFile.seekg(0, std::ios::end);
	fileSize = inputFile.tellg();
	return fileSize;
}

FileRW::~FileRW()
{
	inputFile.close();
	outputFile.close();
}

