#include "ProcessorB.h"



ProcessorB::ProcessorB(FileRW &file)
{
	fileSize = file.getFileSize();
	bufferSize = 8;
	minorBufferSize = bufferSize;
	curState = Read;
	pos = 0;
	blockLength = 0;
}


void ProcessorB::readSlice()
{
	block.clear();
    if (pos + minorBufferSize > fileSize)
	{
        minorBufferSize = fileSize - pos ;
	}
	else
	{
		minorBufferSize = bufferSize;
	}

    block = file.readBlockFromBegin(pos , minorBufferSize);
	curState = Find;

}

void ProcessorB::writeSlice()
{
	file.writeBlock(block, block.size());
    curState = Read;
}

void ProcessorB::replaceDelimiter()
{

    for (unsigned int i = 0; i < block.size(); i++)
	{
		if (block[i] == delimiter)
		{
			block[i] = newDelimiter;
		}
	}
	pos += block.size();
	curState = Write;

}

void ProcessorB::runProcess()
{
	while (pos != fileSize)
	{
		if (curState == Read)
		{
			readSlice();
		}

		if (curState == Find)
		{
			replaceDelimiter();
		}

		if (curState == Write)
		{
			writeSlice();
		}

	}
}

ProcessorB::~ProcessorB()
{
}
