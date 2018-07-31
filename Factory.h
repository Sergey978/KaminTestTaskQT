#pragma once
#include"IProcessor.h"
#include"filerw.h"

class Factory
{
public:
	enum ProcessorType{A = 0, B, C};
	Factory(FileRW &file);
	IProcessor *createProcessor(ProcessorType type);
	virtual ~Factory();

private:
	FileRW *file;
};

