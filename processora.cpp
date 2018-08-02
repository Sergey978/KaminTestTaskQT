#include "processora.h"
#include"iostream"
#include <algorithm>
ProcessorA::ProcessorA(FileRW &file)
{
	fileSize = file.getFileSize();
	bufferSize = 8;
	minorBufferSize = bufferSize;
	curState = Read;	
	pos = 0;
	blockLength = 0;
}

void ProcessorA::readSlice()
{

	block.clear();
	if (pos + blockLength + minorBufferSize > fileSize)
	{
		minorBufferSize = fileSize - (pos + blockLength);
	}
	else
	{
		minorBufferSize = bufferSize;
	}

	block = file.readBlockFromEnd(pos + blockLength + minorBufferSize, minorBufferSize);
	curState = Find;

}


void ProcessorA::writeSlice()
{
	int readLength = 0;
	while (blockLength > 0)
	{
		if (blockLength <= minorBufferSize)
		{
			minorBufferSize = blockLength;
		}
		else
		{
			minorBufferSize = bufferSize;
		}
		block = file.readBlockFromEnd(pos - readLength, minorBufferSize);
        file.writeBlock(block);
		readLength += minorBufferSize;
		blockLength -= minorBufferSize;
	}
	minorBufferSize = bufferSize;
	blockLength = 0;
	curState = Read;
}

void ProcessorA::findDelimiter()
{
	int delimiterPos = -1;
	for (int i = 0; i < block.size(); i++)
	{
		if (block[i] == delimiter)
		{
			delimiterPos = i;
		}
	}

	if (delimiterPos >= 0)
	{
		blockLength += block.size() - delimiterPos - 1;
		// first delimiter in block 
		if (blockLength == 0)
		{
			blockLength = 1;
		}
		pos += blockLength;
		curState = Write;
		return;
	}

	// If delimiter was not find 
	blockLength += block.size();
	curState = Read;
	// if it was last block  in file then   write it
	if (pos + blockLength >= fileSize)
	{
		pos = fileSize;
		curState = Write;
	}
}

void ProcessorA::runProcess()
{
	
	while (pos != fileSize)
	{
		if (curState == Read)
		{
			readSlice();
		}

		if (curState == Find)
		{
			findDelimiter();
		}

		if (curState == Write)
		{
			writeSlice();
		}

	}

}

ProcessorA::~ProcessorA()
{
}
