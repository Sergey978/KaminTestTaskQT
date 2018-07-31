#pragma once
#include "IProcessor.h"
class ProcessorB :
	public IProcessor
{
public:
	
	ProcessorB(FileRW &file);
	enum State { Read, Write, Find };

	void readSlice();
	void writeSlice();
	void replaceDelimiter();
	void runProcess();
	virtual ~ProcessorB();

private:
	FileRW file;
	State curState;
	char delimiter = ',';
	char newDelimiter = '.';
	long fileSize;
	std::vector<char> block;
	long pos;
	int bufferSize;
	int minorBufferSize;
	int blockLength;
};

