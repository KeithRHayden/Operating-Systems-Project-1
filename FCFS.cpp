#include "FCFS.h"

using namespace algorithms;

FCFS::FCFS() : rear(0), tick(0), size(0), enQ(0) {
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "Hello from the FCFS." << endl;
	cout << "--------------------------------------------------------------------------------\n\n";
	test();
	cout << endl << "we are now exiting the FCFS" << endl;
}

void FCFS::test()
{
	cout << "Hello from the tester\n";
	double lastArrived = 0; //the last added node's arrival time
	double arrival = 0; //tick time of arrival
	double remain = getBurst(); //expected time to end
	push(arrival, remain); //first node;
	while (size < capacity) {
		remain = getBurst(); //remaining time of node
		arrival = getArrival() + lastArrived; //tick time of arrival
		lastArrived = arrival;
		double expected = (tick + rear->next->remain);
		while (rear != 0 && arrival >=  expected) { //if the newNode's arrival occurs after current node's end
			pop();			
			if (rear != 0) expected = (tick + rear->next->remain);
			cout << "\nWe are here" << endl;
		}
		if( rear != 0 ) rear->next->remain -= (arrival - tick);		
		push(arrival, remain); 
	}
	while (rear != 0) {
		pop();
	}
	cout << "exiting tester" << endl;
}

void FCFS::push(double arrive, double left) {
	cout << "This is the push and the node that is added is ";
	if (rear == 0 ) {
		rear = new Node;
		rear->next = rear;		
	}
	else {
		Node *newNode = new Node;
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;
	}	
	rear->index = size;
	cout << "the index " << rear->index;
	rear->exit = arrive;
	cout << " the arrival time " << rear->exit;
	rear->remain = left;
	cout << " and the remaining time " << rear->remain;
	tick = arrive;
	cout << " and the tick is now " << tick << endl;
	++enQ;
	++size; //This is the number of processes already added
	//insert table function to track the node and snapshot	
	cout << "Exiting push" << endl;
}
void FCFS::pop() {
	cout << "Inside pop, and we are popping the headnode" << endl;	
	if(rear == 0) { return; } //empty queue
	cout << "It has the index " << rear->next->index << " it arrived at " << rear->next->exit;
	tick = tick + rear->next->remain;
	rear->next->remain = 0;
	cout << " and it has " << rear->next->remain << " ticks left and the tick is now " << tick << endl;
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
	cout << "We are now exiting the pop" << endl;
}
