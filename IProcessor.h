#pragma once
#include"filerw.h"

class IProcessor
{
public:

	IProcessor()
	{
		
	}
	virtual void runProcess() = 0;
	virtual ~IProcessor()
	{
	}
};

