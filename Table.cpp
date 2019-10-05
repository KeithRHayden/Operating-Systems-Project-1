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

	//double test0 = timeIn - lastArrive;
	//double test1 = (timeIn - lastArrive);
	//double test2 = 0;
	//double test3 = nums[curX][5] + test0;
	//double test4 = (nums[curX][5] + test0);
	//double test5 = nums[curX][5] + test1;
	//double test6 = (nums[curX][5] + test1);= (nums[curX][5] + timeIn - lastArrive)
	//cout << test0 << ", " << test1 << ", " << test2 << ", " << test3 << ", " << test4 << ", " << test5 << ", " << test6 << endl;
	nums[curX][0] = nums[curX][0] + 1;
	nums[curX][5] = 100;
	cout << nums[curX][5] << endl;
	nums[curX][6] = nums[curX][6] + burst;
	nums[curX][7] = double(nums[curX][6]/nums[curX][0]);
	lastArrive = timeIn;
}

void Table::endNew(double arrTime, double exitTime, double waitTimes, double changes, int inQ){

	nums[curX][10] = nums[curX][10] + 1;
	nums[curX][1] = exitTime;
	nums[curX][2] = double(nums[curX][1]/nums[curX][10]);
	double tAround = double(exitTime - arrTime);
	nums[curX][8] = nums[curX][8] + tAround;
	if(tAround > nums[curX][3]) nums[curX][3] = tAround;
	if(tAround < nums[curX][4]) nums[curX][4] = tAround;
	nums[curX][9] = double(nums[curX][8] / nums[curX][10]);
	if(inQ > nums[curX][11]) nums[curX][11] = inQ;
	if(inQ < nums[curX][12]) nums[curX][12] = inQ;
	nums[curX][13] = nums[curX][13] + inQ;
	nums[curX][14] = double(nums[curX][13]/nums[curX][10]);
	if(changes > nums[curX][15]) nums[curX][15] = changes;
	if(changes < nums[curX][16]) nums[curX][16] = changes;
	nums[curX][17] = nums[curX][17] + changes;
	nums[curX][18] = double(nums[curX][17]/nums[curX][10]);
	nums[curX][21] = nums[curX][21] + waitTimes;
	if(waitTimes > nums[curX][19]) nums[curX][19] = waitTimes;
	if(waitTimes < nums[curX][20]) nums[curX][20] = waitTimes;
	nums[curX][22] = double(nums[curX][21] / nums[curX][10]);
	nums[curX][23] = double(nums[curX][22] + nums[curX][7]);
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

