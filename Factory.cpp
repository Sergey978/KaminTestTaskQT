#include "Factory.h"
#include "processora.h"
#include"ProcessorB.h"
#include"ProcessorC.h"



Factory::Factory(FileRW &inputFile)
{
	file = &inputFile;
}

IProcessor * Factory::createProcessor(ProcessorType type)
{
	IProcessor * proc;

	if (type == A)
	{
		proc = new ProcessorA(*file);
	}
	else if (type == B)
	{
        proc = new ProcessorB(*file);
	}

	else if (type == C)
	{
        proc = new ProcessorC(*file);
	}
	else
    {

        proc = new ProcessorA(*file);
    }

	return proc;
}


Factory::~Factory()
{
}
