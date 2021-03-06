#ifndef FILERW_H
#define FILERW_H

#include <iostream>
#include<vector>
#include <fstream>

class FileRW
{
public:
	FileRW();

	std::vector<char> readBlockFromEnd(const int beginPoint, int dataSize);
    std::vector<char> readBlockFromBegin(const int beginPoint, int dataSize);
    void writeBlock(std::vector<char> &data);
	long getFileSize();

	~FileRW();

private:
	std::ifstream inputFile;
	std::ofstream outputFile;	
	bool  firstOpened;

};

#endif // FILERW_H
