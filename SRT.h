#ifndef SRT_H
#define SRT_H

#include <iostream>
#include "Queue.h"
#include "Table.h"

namespace algorithms {
	using namespace std;
	class SRT {
	public:
		SRT();
		void test();

		private:
		void insert(double arrive, double left, double lastArrive);
		void pop();
		void clear();

		Node* rear;
		double tick; //time 1 tick is 1/10 of a milisec
		int size; //total number of processes added to scheduler queue
		int enQ; //currently in queue
		int sizeDone;
		int n;
		Table table;
		
	};
}
#endif //SRT_H