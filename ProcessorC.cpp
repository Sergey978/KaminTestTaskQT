#include "ProcessorC.h"


ProcessorC::ProcessorC(FileRW &file)
{

    fileSize = file.getFileSize();
    bufferSize = 8;
    minorBufferSize = bufferSize;
    curState = Read;
    pos = 0;
    blockLength = 0;
}

void ProcessorC::readSlice()
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

void ProcessorC::writeSlice()
{
    file.writeBlock(block, block.size());
    curState = Read;
}

void ProcessorC::removeDelimiter()
{
    auto i = std::begin(block);

    while (i != block.end())
    {
        if (*i == delimiter)
        {
            i = block.erase(i);
        }
        else {
            i++;
        }
    }

    pos += block.size();
    curState = Write;

}

void ProcessorC::runProcess()
{
    while (pos != fileSize)
    {
        if (curState == Read)
        {
            readSlice();
        }

        if (curState == Find)
        {
            removeDelimiter();
        }

        if (curState == Write)
        {
            writeSlice();
        }

    }
}

ProcessorC::~ProcessorC()
{
}
