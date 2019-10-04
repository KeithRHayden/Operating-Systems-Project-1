#ifndef RR_H
#define RR_H

#include <iostream>

#include "Queue.h"

namespace algorithms {
	using namespace std;
	class RR {
		public:
			RR();	
			RR(double high, double low);
			void test();
			
		

		private:
			const double DEFAULT_LOW = 100;
			const double DEFAULT_HIGH = 600;
			double qlow;
			double qhigh;
			int capacity = testSize;
			Node* rear;
			double tick; //time 1 tick is 1/10 of a milisec
			int size; //total number of processes added to scheduler queue
			int enQ; //currently in queue

			void push(double arrive, double left);
			void pop();

	
	};
}
#endif