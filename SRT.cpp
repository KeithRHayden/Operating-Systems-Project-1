#include "SRT.h"

using namespace algorithms;

SRT::SRT() : rear(0), tick(0), size(0), enQ(0)  {
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "Hello from the SRT." << endl;
	cout << "--------------------------------------------------------------------------------\n\n";
	test();
}

void SRT::test()
{
	cout << "Hello from the tester\n";
	double lastArrived = 0; //the last added node's arrival time
	double arrival = 0; //tick time of arrival
	double remain = getBurst(); //expected time to end
	insert(arrival, remain); //first node;
	while (size < capacity) {
		remain = getBurst(); //remaining time of node
		arrival = getArrival() + lastArrived; //tick time of arrival
		lastArrived = arrival;
		double expected = (tick + rear->next->remain);
		while (rear != 0 && arrival >=  expected) { //if the newNode's arrival occurs after current node's end			
			pop();
			if (rear != 0) expected = (tick + rear->next->remain);
		}
		if(rear != 0) rear->next->remain -= (arrival - tick);
		insert(arrival, remain);		 
	}
	while (rear != 0) {
		pop();
	}
}

void SRT::insert(double arrive, double left) {
	cout << "This is the push and the node that is added is ";
	Node *newNode = new Node;
	newNode->index = size;
	cout << "the index " << newNode->index;
	newNode->exit = arrive;
	cout << " the arrival time " << newNode->exit;
	newNode->remain = left;
	cout << " and the remaining time " << newNode->remain;
	if (rear == 0 ) {
		rear = newNode;
		rear->next = rear;		
	}
	else {		
		if(left >= rear->remain || left < rear->next->remain) {
			if(left < rear->next->remain) {
				//update the node, it was kicked out of execution
				//and the wait time prior to current execution is added
				rear->next->exit = arrive;
			}			
			newNode->next = rear->next;
			rear->next = newNode;			
			if(left >= rear->remain) {
				rear = newNode;
			}			
		}
		else {
			Node *pre = rear->next;
			while(pre != rear) { //already checked at tail ends
				if(pre->next->remain > left) {
					newNode->next = pre->next;
					pre->next = newNode;
				}
			}
			
		}		
	}	
	tick = arrive;
	++enQ;
	++size; //This is the number of processes already added
	//insert table function to track the node and snapshot	
}
void SRT::pop() {
	cout << "Inside pop, and we are popping the headnode" << endl;	
	if(rear == 0) { return; } //empty queue
	cout << "It has the index " << rear->next->index << " it arrived at " << rear->next->exit;
	tick = tick + rear->next->remain;
	rear->next->remain = 0;
	cout << " and it has " << rear->next->remain << " ticks left" << endl;
	if(rear->next == rear) { //only one in the queue
		rear->next = 0;
		delete rear;
		rear = 0;
	}
	else {
		Node *cur = rear->next;
		rear->next = cur->next;
		delete cur;
	}
	--enQ;
	//insert table function to flag the node and snapshot
}
