#ifndef PROCESSORA_H
#define PROCESSORA_H

#include<vector>
#include "filerw.h"
#include "IProcessor.h"

class ProcessorA: public IProcessor
{
public:

	ProcessorA(FileRW &file);
	enum State { Read, Write, Find };
	
	void readSlice();
	void writeSlice();
	void findDelimiter();
	void runProcess();
	virtual ~ProcessorA();
		

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

#endif // PROCESSORA_H
