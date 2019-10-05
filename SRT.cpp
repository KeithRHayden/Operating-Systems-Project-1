#include "SRT.h"

using namespace algorithms;


SRT::SRT() : rear(0), tick(0), size(0), enQ(0), sizeDone(0), n(0)  {
	
	table.create();
	for(int i = 0; i < numNs; i++ ) {
		n = i + 1;
		table.newN(n);
		test();		
	}
}

void SRT::test() {

	double lastArrived = 0; //the last added node's arrival time
	double arrival = 0; //tick time of arrival
	double remain = getBurst(); //expected time to end
	insert(arrival, remain, lastArrived); //first node;
	while (sizeDone < testSize) {
		remain = getBurst(); 
		arrival = getArrival(n) + lastArrived; 
		lastArrived = arrival;
		double expected = (tick + rear->next->remain);		
		while (rear != 0 && arrival >=  expected) { //if the newNode's arrival occurs after current node's end			
			pop();
			if (rear != 0) expected = (tick + rear->next->remain);
		}
		if(rear != 0) rear->next->remain -= (arrival - tick);
		insert(arrival, remain, lastArrived);
	}
	while (rear != 0) pop();	
	clear();
}

void SRT::insert(double arrive, double left, double lastArrive) {
	
	Node *newNode = createTask(arrive, left);
	table.addNew(rear->arr, rear->remain, lastArrive);
	if (rear == 0 ) {
		rear = newNode;
		rear->next = rear;		
	}
	else {		
		if(left >= rear->remain || left < rear->next->remain) {

			if(left < rear->next->remain) {
				++rear->next->change;
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
			while(pre != rear) { 
				if(pre->next->remain > left) {
					newNode->next = pre->next;
					pre->next = newNode;
				}
			}			
		}		
	}
	tick = arrive;
	++size;
	++enQ;
}

void SRT::pop() {

	rear->next->exit = double(tick + rear->remain);
	++rear->change;
	table.endNew(rear->arr, rear->exit, rear->waitTime, rear->change, --enQ);
	tick += rear->remain;
	removeNode(rear);
	if (rear != 0) rear->next->waitTime += (tick - rear->next->exit);
	++sizeDone;	
}

void SRT::clear() { tick = size = sizeDone = enQ = 0; }