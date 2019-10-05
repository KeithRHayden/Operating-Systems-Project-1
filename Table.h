#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace algorithms {
	
	class Table {
	
		public:
			Table();
			void create();
			void newN(int n);
			void addNew(double timeIn, double burst, double lastArrive);
			void endNew(double arrTime, double exitTime, double waitTimes, double changes, int inQ);
			void print();
			void clear();
			int getTestSize();
			int getNumN();

		private:
			static const int CAPACITY = 10000;
			static const int numN = 30;
			string file1; //file that will hold output
			static const int numFields = 24;
			double nums[numN][numFields]; //snapshots the stats at every push
			int curX;

			void getFileName();


			
	};
}
#endif //TABLE_H

