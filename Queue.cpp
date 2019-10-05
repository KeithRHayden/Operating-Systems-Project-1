#include "Queue.h"


namespace algorithms {

	Node* createTask(double lastExit, double remaining)
	{
		Node *cur = new Node;
		cur->arr = lastExit;
		cur->exit = lastExit;
		cur->remain = remaining;
		cur->waitTime = 0;
		cur->change = 0;
		cur->next = 0;
		return cur;
	}

	void pushNode(Node*& rearPtr, double lastExit, double remaining) {
		
		Node *target = createTask(lastExit, remaining);				
		if (rearPtr == 0 ) {
			rearPtr = target;
			rearPtr->next = rearPtr;		
		}
		else {

			target->next = rearPtr->next;
			rearPtr->next = target;
			rearPtr = target;
		}
	}
	

	void removeNode(Node*& rearPtr) {

		if(rearPtr == 0) return; //empty queue	
		rearPtr->next->remain = 0;	
		if(rearPtr->next == rearPtr) { //only one in the queue
			rearPtr->next = 0;
			delete rearPtr;
			rearPtr = 0;
		}
		else {
			Node *cur = rearPtr->next;
			rearPtr->next = cur->next;
			delete cur;
		}
	}

	double getArrival(int k) { 
		double arrive = double(double(1)/k);
		return arrive; 
	}

	double getBurst() { 
		srand(time(0));
		double burst = double(double(rand() % 100 + 20)/1000);
		return burst;
	}

}
