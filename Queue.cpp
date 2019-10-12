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

	double genexp(double k) {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		default_random_engine newDouble(seed);
		poisson_distribution<int> exp (double(100000/k));
		return(double(exp(newDouble) / 100000)); 
	}

	double getArrival(int k) { return genexp(k); }

	double getBurst() { return genexp(double(1/0.06)); }

}
