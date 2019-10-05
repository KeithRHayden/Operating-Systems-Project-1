#ifndef RR_H
#define RR_H

#include <iostream>

#include "Queue.h"
#include "Table.h"

namespace algorithms {
	using namespace std;
	class RR {
		public:
			RR();	
			RR(double high, double low);
			void test();
			
		

		private:
			const double DEFAULT_LOW = 0.01;
			const double DEFAULT_HIGH = 0.2;
			Node* rear;
			double tick; //time 1 tick is 1/10 of a milisec
			int size; //total number of processes added to scheduler queue
			int sizeDone;
			int enQ; //currently in queue
			double curQ; //current quantum used
			double qCounter;
			int n;
			Table table;

			void push(double arrive, double left, double lastArrive);
			void pop();
			void reduce();
			void clear();
	
	};
}
#endif