#pragma once
#include "IProcessor.h"
class ProcessorC :
	public IProcessor
{
public:

	ProcessorC(FileRW &file);
	enum State { Read, Write, Find };

	void readSlice();
	void writeSlice();
	void removeDelimiter();
	void runProcess();
	virtual ~ProcessorC();

private:
	FileRW file;
	State curState;
	char delimiter = ' ';
	long fileSize;
	std::vector<char> block;
	long pos;
	int bufferSize;
	int minorBufferSize;
	int blockLength;
};

