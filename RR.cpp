#include "RR.h"

using namespace algorithms;

RR::RR() : rear(0), tick(0), size(0), sizeDone(0), enQ(0), qCounter(0) {

	table.create();
	curQ = DEFAULT_LOW;
	for(int i = 0; i < 30; i++ ) {
		n = i + 1;
		table.newN(i);
		test();		
	}
	table.print();
	table.create();
	curQ = DEFAULT_HIGH;
	for(int i = 0; i < 30; i++ ) {
		n = i + 1;
		table.newN(i);
		test();		
	}
	table.print();
}

RR::RR(double low, double high) : rear(0), tick(0), size(0), enQ(0), qCounter(0) {
	
	table.create();
	curQ = low;
	for(int i = 0; i < numNs; i++ ) {
		n = i + 1;
		table.newN(i);
		test();		
	}

	table.create();
	curQ = high;
	for(int i = 0; i < numNs; i++ ) {
		n = i + 1;
		table.newN(i);
		test();		
	}
}

void RR::test() {
	
	double lastArrived = 0; //the last added node's arrival time
	double arrival = 0; //tick time of arrival
	double remain = getBurst(); //expected time to end
	qCounter = curQ;
	push(arrival, remain, lastArrived); //first node
	while (sizeDone < testSize) {
		remain = getBurst(); 
		arrival = getArrival(n) + lastArrived;
		lastArrived = arrival;
		double expected = (qCounter < rear->next->remain) ? (tick + qCounter) : (tick + rear->next->remain);
		while (rear != 0 && arrival >=  expected) {
			reduce(); 
			qCounter = curQ; 
			if (rear != 0) expected = (qCounter < rear->next->remain) ? (tick + qCounter) : (tick + rear->next->remain);
		}
		if( rear != 0 ) {
			rear->next->remain -= (arrival - tick);	
			qCounter -=	(arrival - tick);
		}
		push(arrival, remain, lastArrived); 
	}
	while (rear != 0) {
		reduce();
		qCounter = curQ;
	}
	clear();
}

void RR::push(double arrive, double left, double lastArrive) {
	
	pushNode(rear, arrive, left);
	table.addNew(rear->arr, rear->remain, lastArrive);
	tick = arrive;
	++size;
	++enQ;
}

void RR::pop() {
		
	
	rear->next->exit = double(tick + rear->remain);
	++rear->change;
	table.endNew(rear->arr, rear->exit, rear->waitTime, rear->change, --enQ);
	tick += rear->remain;
	removeNode(rear);
	if(rear != 0) rear->next->waitTime += (tick - rear->next->exit);
	++sizeDone;	
}

void RR::reduce() {

	if (qCounter >= rear->next->remain) pop();
	else {		
		rear->next->remain -= qCounter;
		++rear->next->change;
		tick += qCounter;
		if(rear != 0 || rear->next != rear) rear = rear->next;
		rear->next->waitTime += (tick - rear->next->exit);
	}
}

void RR::clear() { 	tick = size = sizeDone = enQ = curQ = qCounter = 0; }
