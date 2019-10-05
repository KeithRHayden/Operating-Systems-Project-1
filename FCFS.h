#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include "Queue.h"
#include "Table.h"

namespace algorithms {
	using namespace std;
	class FCFS {
	public:
		FCFS();
		void test();

	private:

		Node* rear;
		double tick; 
		int size; //total number of processes added to scheduler queue
		int sizeDone;
		int enQ; //currently in queue
		int n;
		Table table;

		void push(double arrive, double bursts, double lastArrive);
		void pop();
		void clear();		

	};
}
#endif //FCFS_H
