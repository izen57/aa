#include <iostream>
#include <thread>

#include "conveyor.h"


int main() 
{
	std::setlocale(LC_ALL, "");
    std::setbuf(stdout, NULL);
    Conveyor *conveyor_obj = new Conveyor();

	std::cout << "Линейная обработка:\n";
    conveyor_obj->run_linear(5);
	std::cout << std::endl;

	std::cout << "Параллельная обработка:\n";
    conveyor_obj->run_parallel(5);

    delete conveyor_obj;

    return 0;
}
