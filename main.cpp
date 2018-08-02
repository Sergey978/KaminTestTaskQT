#include <iostream>
#include "processora.h"
#include"Factory.h"

using namespace std;

int main(int argc, char* argv[])
{

    std::cout  << argv[1] << std::endl;
    FileRW *file = new FileRW;
    IProcessor *proc ;
    Factory *myFactory = new Factory(*file);


    char const *option =  argv[1];

    if (*option == 'A')
    {
         proc = myFactory->createProcessor(Factory::A);
    }

    if (*option == 'B')
    {
        proc = myFactory->createProcessor(Factory::B);

    }
    else if (*option == 'C')
    {

        proc = myFactory->createProcessor(Factory::C);
    }

    proc->runProcess();


    delete file;
    return 0;
}
