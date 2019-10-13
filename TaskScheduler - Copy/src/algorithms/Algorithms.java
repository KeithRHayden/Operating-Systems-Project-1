package algorithms;

import scheduler.ReadyQueue;

public class Algorithms {
	
	private String n = "\n############################################\n";
	private static double LOW_QUANTUM = 0.01;
	private static double HIGH_QUANTUM = 0.2;
	private static double[] curQ;
	private static ReadyQueue q = new ReadyQueue();
	private static int testSize = 10000;
	private static int range = 30;
	
	


	public void testFCFS() {
		System.out.println("We are in the testFCFS");
		for(int i = 0; i < range; i++) {
			q.setLambda(i+1);
			System.out.println(n + "This is lambda " + ReadyQueue.lambda + n);
			q.getBurst();		
			/*
			 * add the first node so the queue wont be empty and 
			 * has something to refer to for time
			 */
			q.add();
			while(ReadyQueue.pops < testSize) {
				/*
				 * loop adding nodes until 10,000 pops have happened
				 */
				q.getArrival();
				q.getBurst();
				/*
				 * if the arriving node is expected to come after
				 * the head node is done with its turn then ignore 
				 * the arrival until it is with in the time a
				 * head node is active
				 */
				q.getExpected(); 
				while(!q.empty() && q.notReady()) {
					q.pop();
					if(ReadyQueue.pops == testSize) break;
					q.getExpected();
				}
				/*
				 * once with in the time of a head's active
				 * turn in execution, add the node and increase the 
				 * ticks
				 */
				q.add();
			}
			q.clear("FCFS.csv");
		}		
		
	}
	
	public void testSRT() {
		System.out.println("We are in the testSRT");
		for(int i = 0; i < range; i++) {
			q.setLambda(i+1);
			System.out.println(n + "This is lambda " + ReadyQueue.lambda + n);
			q.getBurst();			
			q.insert();
			while(ReadyQueue.pops < testSize) {
				q.getArrival();
				q.getBurst();
				q.getExpected();
				while(!q.empty() && q.notReady()) {
					q.pop();
					if(ReadyQueue.pops == testSize) break;
					q.getExpected();
				}
				q.insert();
			}
			q.clear("SRT.csv");
		}
	}
	
	public void testRR() {
		
		curQ = new double[] { LOW_QUANTUM, HIGH_QUANTUM };
		
		for ( double cur : curQ ) {
			System.out.println("We are in the testRR default");
			double qCounter = cur;
			for(int i = 0; i < range; i++) {
				q.setLambda(i+1);
				System.out.println(n + "This is lambda " + ReadyQueue.lambda + n);
				q.getBurst();			
				q.add();
				while(ReadyQueue.pops < testSize) {
					q.getArrival();
					q.getBurst();
					q.getExpected(qCounter);
					while(!q.empty() && q.notReady()) {
						q.reduce(qCounter);
						if(ReadyQueue.pops == testSize) break;
						q.getExpected(qCounter);
					}
					q.add();
				}
				if(cur == LOW_QUANTUM) q.clear("RR_def_low.csv");
				if(cur == HIGH_QUANTUM) q.clear("RR_def_high.csv");
			}
		}		
	}
	
	public void testRR(double low, double high) {
		
		curQ = new double[] { low, high };
		
		for ( double cur : curQ ) {
			System.out.println("We are in the testRR default");
			double qCounter = cur;
			for(int i = 0; i < range; i++) {
				q.setLambda(i+1);
				System.out.println(n + "This is lambda " + ReadyQueue.lambda + n);
				q.getBurst();			
				q.add();
				while(ReadyQueue.pops < testSize) {
					q.getArrival();
					q.getBurst();
					q.getExpected(qCounter);
					if(!q.empty() && q.notReady()) {
						q.reduce(qCounter);
						if(ReadyQueue.pops == testSize) break;
						q.getExpected(qCounter);
					}
					q.add();
				}
				if(cur == low) q.clear("RR_def_low.csv");
				if(cur == high) q.clear("RR_def_high.csv");
			}
		}
	}
}	
	
