
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
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
	float getQuantum();

	char choice;
	float lowChoice;
	float highChoice;

};

#endif //CONTROLLER_H
