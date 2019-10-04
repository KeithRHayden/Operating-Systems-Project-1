#ifndef FCFS_H
#define FCFS_H

#include <iostream>
#include "Queue.h"

namespace algorithms {
	using namespace std;
	class FCFS {
	public:
		FCFS();
		void test();

	private:
		const int capacity = testSize;

		void push(double arrive, double left);
		void pop();

		Node* rear;
		double tick; //time 1 tick is 1/10 of a milisec
		int size; //total number of processes added to scheduler queue
		int enQ; //currently in queue

	};
}
#endif //FCFS_H
