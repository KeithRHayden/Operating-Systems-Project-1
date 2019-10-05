#include "FCFS.h"

using namespace algorithms;

FCFS::FCFS() : rear(0), tick(0), size(0), sizeDone(0), enQ(0) {

	table.create();
	for(int i = 0; i < numNs; ++i ) {
		cout << "This is " << i << " out of " << numNs << endl;
		n = 1 + i;
		table.newN(n);
		test();	
	}
	table.print();
}

void FCFS::test() {

	double lastArrived = 0; //the last added node's arrival time
	double arrival = 0; //tick time of arrival
	double remain = getBurst(); //expected time to end
	push(arrival, remain, lastArrived); //first node;
	while (sizeDone < testSize) {
		arrival = getArrival(n) + lastArrived; 
		lastArrived = arrival;
		remain = getBurst(); 
		double expected = (tick + rear->next->remain);
		while (rear != 0 && arrival >=  expected) {
			pop();			
			if (rear != 0) expected = (tick + rear->next->remain);
		}
		if( rear != 0 ) rear->next->remain -= (arrival - tick);	
		push(arrival, remain, lastArrived); 
	}
	while (rear != 0) pop();
	clear();
}

void FCFS::push(double arrive, double bursts, double lastArrive) {

	pushNode(rear, arrive, bursts);
	table.addNew(rear->arr, rear->remain, lastArrive);
	tick = arrive;
	++size;
	++enQ;	
}

void FCFS::pop() {

	rear->next->exit = double(tick + rear->remain);
	++rear->change;
	table.endNew(rear->arr, rear->exit, rear->waitTime, rear->change, --enQ);
	tick += rear->remain;
	removeNode(rear);		
	if(rear != 0) rear->next->waitTime += (tick - rear->next->arr);
	++sizeDone; 
}

void FCFS::clear() { tick = size = sizeDone = enQ = 0; }