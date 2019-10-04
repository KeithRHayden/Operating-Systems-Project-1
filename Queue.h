#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <random>
#include <time.h>

using namespace std;

namespace algorithms {
	struct Node {
			int index;
			double exit;
			double remain;
			Node *next;
		};
	//class Queue {
		
	//public:
		
		
		//Node *rear;

		Node* createTask();
		int getTestSize();
		double getArrival();
		double getBurst();
		//double getArrivalStart();
		//double getBurstStart();

	//private:					
		const double aStarter = (10000 * (1 / 30));
		const double bStarter = (10000 * (1 / 25));
		const int aRange = int(10000 - aStarter);
		const int bRange = int(10000 - bStarter);
		const int testSize = 5;


	//};
		
		
}
#endif //QUEUE_H
