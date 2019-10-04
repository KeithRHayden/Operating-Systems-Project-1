
#include "Controller.h"

Controller::Controller()
{

	do {
		printMenu();
		choice = getInput();
		switch (choice)
		{
		case 'a': case 'A':
			FCFS();
			break;

		case 'b': case 'B':
			SRT();
			break;

		case 'c': case 'C':
			RR();
			break;

		case 'd': case 'D':
			cout << "Please enter a double value for the low quantum: ";
			lowChoice = getQuantum();
			cout << "Please enter a double value for the high quantum: ";
			highChoice = getQuantum();
			RR(lowChoice, highChoice);
			break;

		case 'q': case 'Q':
			cout << "Quit option selected...bye" << endl;
			break;

		default:
			cout << choice << " is not a valid option...try again"
				<< endl;
		}
	} while (choice != 'q' && choice != 'Q');
	cout << "Press Enter or Return when ready...";
	cin.ignore();
	cin.get();
}

void Controller::printMenu()
{
	cout << endl;
	cout << "The following choices are available: " << endl;
	cout << "  a  Process using First Come First Serve" << endl;
	cout << "  b  Process using Shortest Remaining Time" << endl;
	cout << "  c  Process using Round Robin with default quantums" << endl;
	cout << "  d  Process using Round Robin and defined quantums" << endl;
	cout << "  q  Quit this test program" << endl;
}

char Controller::getInput()
{
	char command;

	cout << "Enter choice: ";
	cin >> command;

	cout << command << " read." << endl;
	return command;
}

double Controller::getQuantum() {
	double result;
	cin >> result;
	while (!cin.good())
	{
		cerr << "Bad double input..." << endl;
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Re-enter a double: ";
		cin >> result;
	}
	cin.ignore(999, '\n');
	cout << result << " read." << endl;
	return result;
}
