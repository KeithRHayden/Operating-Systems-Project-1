#include "Queue.h"

namespace algorithms {

	Node* createTask()
	{
		Node *cur = new Node;
		cur->index = 0;
		cur->exit = 0;
		cur->remain = 0;
		cur->next = 0;
		std::cout << "--------------------------------------------------------------------------------\n\n";
		std::cout << "Hello from the CreateTask." << endl;
		std::cout << "--------------------------------------------------------------------------------\n\n";
		return cur;
	}

	int getTestSize() { return testSize; }
	double getArrival() { return double(rand() % aRange + aStarter); }
	double getBurst() { return double(rand() % bRange + bStarter); }
	//double getArrivalStart() { return aStarter; }
	//double getBurstStart() { return bStarter; }

}
