#include "Table.h"

using namespace algorithms;

Table::Table() : curX(0) {}

void Table::create() {	
	getFileName();	
	ofstream file;	
    file.open(file1, ios::out | ios::app); 
	if(!file) {
		cout << "There was an error in file creation.\n";
		file.clear();
		file.close();
		create();
		return;
	}
	cout << "File created successfully.\n";
	file.clear();	  
   	file.close(); 
}

void Table::newN(int n) { 
	curX = n; 
	for(int i = 0; i < numFields; i++) {
		if ( i == 5 || i == 13 || i == 17 || i == 21) nums[curX][i] = 100;
		nums[curX][i] = 0;
	}
}

void Table::addNew(double timeIn, double burst, double lastArrive) {

	double helper = nums[curX][0];
	helper += 1;
	nums[curX][0] = (double)(helper);
	helper = nums[curX][5];
	helper += (timeIn - lastArrive);
	nums[curX][5] = helper;
	helper = nums[curX][6];
	helper += burst;
	nums[curX][6] = helper;
	helper = nums[curX][6];
	double helper2 = nums[curX][0];
	nums[curX][7] = double(helper/helper2);
	lastArrive = timeIn;
}

void Table::endNew(double arrTime, double exitTime, double waitTimes, double changes, int inQ){

	double helper, helper2;
	helper = nums[curX][10];
	helper += 1;
	nums[curX][10] = helper;
	nums[curX][1] = exitTime;
	helper = nums[curX][1];
	helper2 = nums[curX][10];
	nums[curX][2] = double(helper/helper2);
	double tAround = double(exitTime - arrTime);
	helper = nums[curX][8];
	nums[curX][8] = helper + tAround;
	helper = nums[curX][3];
	helper = nums[curX][4];
	if(tAround > helper) nums[curX][3] = tAround;
	if(tAround < helper2) nums[curX][4] = tAround;
	helper = nums[curX][8];
	helper2 = nums[curX][10];
	nums[curX][9] = double( helper / helper2 );
	helper = nums[curX][11];
	helper2 = nums[curX][12];
	if(inQ > helper) nums[curX][11] = inQ;
	if(inQ < helper2) nums[curX][12] = inQ;
	helper = nums[curX][13];
	helper2 = nums[curX][10];
	nums[curX][13] = helper + inQ;
	nums[curX][14] = double(helper/ helper2);
	helper = nums[curX][15];
	helper2 = nums[curX][16];
	if(changes > helper) nums[curX][15] = changes;
	if(changes < helper2) nums[curX][16] = changes;
	helper = nums[curX][17];
	helper2 = nums[curX][10];
	nums[curX][17] = helper + changes;
	nums[curX][18] = double(helper/helper2);
	helper = nums[curX][21];
	nums[curX][21] = helper + waitTimes;
	helper = nums[curX][19];
	helper2 = nums[curX][20];
	if(waitTimes > helper) nums[curX][19] = waitTimes;
	if(waitTimes < helper2) nums[curX][20] = waitTimes;
	helper = nums[curX][21];
	helper2 = nums[curX][10];
	nums[curX][22] = double( helper/helper2 );
	helper = nums[curX][22];
	helper2 = nums[curX][7];
	nums[curX][23] = double( helper + helper2 );
}

void Table::print() {

	ofstream printer;
	printer.open(file1);
	if(printer.good()) { //0					1			2						3
		printer << "n,number of proceses pushed,total ticks,avg ticks per process,max tick,"//3
				<< "min tick,total arrival periods,total bursts,average burst,total turnaround,"//8
				<< "avg turnaround,total completed,max ready,min ready,total ready,"//13
				<< "avg ready,max switch,min switch,total switch,avg switch,"//18
				<< "max wait,min wait,total wait,avg wait,cpuUtil,\n";//23
	}
	printer.clear();
	if(printer.good()) {
		for(int i = 0; i < numN; i++) {
			for(int j = 0; j < numFields; j++) {
				if(j == 0) { printer << "1/" << (i+1) << ","; }
				printer << nums[i][j] << ",";
			}
			printer << endl;
			printer.clear();
		}
	}
	printer.close();
	clear();
}

void Table::clear() { file1 = curX = 0; }

int Table::getTestSize() { return CAPACITY; }

int Table::getNumN() { return numN;}

void Table::getFileName() {

	cout << "Enter name for csv file (do not include csv or any space)" << endl;
	cout << "This will be the three time slice catagories:" << endl;	
	cin >> file1;
	file1 += ".csv";
	cout << file1 << " is the file you chose." << endl;
}

