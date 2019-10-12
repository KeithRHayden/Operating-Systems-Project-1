#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <random>
#include <time.h>
#include <chrono>

using namespace std;

namespace algorithms {
	struct Node {
			double arr;
			double exit;
			double remain;
			double waitTime;
			double change;
			Node *next;
		};

		Node* createTask(double lastExit, double remaining);
		void pushNode(Node*& rearPtr, double lastExit, double remaining);
		void removeNode(Node*& rearPtr);
		double getArrival(int k);
		double getBurst();
		const int testSize = 10000;	
		const int numNs = 30;	
		
		
}
#endif //QUEUE_H
