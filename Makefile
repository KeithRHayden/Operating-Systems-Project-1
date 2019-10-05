scheduler: Queue.o driver.o Controller.o FCFS.o SRT.o RR.o Table.o
	g++ Queue.o driver.o Controller.o FCFS.o SRT.o RR.o Table.o -o scheduler
Queue.o: Queue.cpp Queue.h
	g++ -Wall -ansi -pedantic -std=c++11 -c Queue.cpp
driver.o: driver.cpp Controller.h 
	g++ -Wall -ansi -pedantic -std=c++11 -c driver.cpp
Controller.o: Controller.cpp Controller.h 
	g++ -Wall -ansi -pedantic -std=c++11 -c Controller.cpp
FCFS.o: FCFS.cpp FCFS.h Queue.h Table.h
	g++ -Wall -ansi -pedantic -std=c++11 -c FCFS.cpp
SRT.o: SRT.cpp SRT.h Queue.h Table.h
	g++ -Wall -ansi -pedantic -std=c++11 -c SRT.cpp
RR.o: RR.cpp RR.h Queue.h Table.h
	g++ -Wall -ansi -pedantic -std=c++11 -c RR.cpp
Table.o: Table.cpp Table.h Table.h
	g++ -Wall -ansi -pedantic -std=c++11 -c Table.cpp
clean:
	@rm -rf RR.o SRT.o FCFS.o Queue.o Controller.o driver.o Table.o scheduler
cleanall:
	@rm -rf Table.o Table.cpp Table.h RR.o SRT.o FCFS.o Queue.o Controller.o driver.o scheduler RR.cpp SRT.cpp FCFS.cpp Queue.cpp Controller.cpp driver.cpp RR.h SRT.h FCFS.h Queue.h Controller.h driver.h

