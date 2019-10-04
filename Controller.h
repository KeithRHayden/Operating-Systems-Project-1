
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "FCFS.h"
#include "SRT.h"
#include "RR.h"

using namespace std;
using namespace algorithms;

class Controller
{
public:
	Controller();

private:
	
	void printMenu();
	char getInput();
	double getQuantum();

	char choice;
	double lowChoice;
	double highChoice;

};

#endif //CONTROLLER_H
