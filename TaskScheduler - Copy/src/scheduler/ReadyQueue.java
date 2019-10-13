package scheduler;

import java.util.ArrayList;
import java.util.Random;

public class ReadyQueue {

	//public double total;	
	private ArrayList<Node> queue = new ArrayList<Node>();
	private static Table table = new Table();
	public static Random ran = new Random(System.currentTimeMillis());
	public static int size = 0;
	private static double tick = 0;
	private static double last = 0;
	private static double expected = 0;
	private double arrive = 0;
	private double burst = 0;
	public static int pops = 0;
	public static int pushes = 0;
	public static int lambda = 0;
	
	public void add() {
		//System.out.println("\nI am in add()");
		queue.add(new Node(size, last, arrive, burst));		
		tick = last;		
		if (queue.size() > 1) {
			queue.get(0).remaining -= (last - tick);	
			//track helper
			//System.out.println("The ticks and remaining are being updated to " + tick + " ticks and " + queue.get(0).remaining + " remaining");		
		} 
		size++;
		//track helpers
		/*System.out.println("The size of the queue is now " + queue.size());
		System.out.println("The queue added: at index " + queue.get(queue.size()-1).index
							+ " with arrival at " + queue.get(queue.size() - 1).arrival);
		System.out.println(" with period of " + queue.get(queue.size() - 1).arrivalPeriod
							+ " with burst of " + queue.get(queue.size() - 1).burst);
		System.out.println(" with termination at " + queue.get(queue.size() - 1).termination
							+ " with remaining of " + queue.get(queue.size() -1 ).remaining);
		System.out.println(" with a wait of " + queue.get(queue.size()-1).waitTime
							+ " and a switch of " + queue.get(queue.size()-1).contextSwitch);
		System.out.println("The tick is now " + tick);*/


	}
	
	public void insert() {
	
		//int index = queue.size();
		if (queue.size() == 0) {
			
			queue.add(new Node(size, last, arrive, burst));
			tick = last;
		}
		else {
			boolean trigger = false;
			queue.get(0).remaining -= (last - tick);
			tick = last;
			//a track helper
			//System.out.println("The ticks and remaining are being updated to " + tick + " ticks and " + queue.get(0).remaining + " remaining");	
			for( int i = 0; i < queue.size(); i++) {
				if(queue.get(i).remaining > burst ) {					
					queue.add(i, new Node(size, last, arrive, burst));
					if ( i == 0) {
						queue.get(1).termination = last;
						queue.get(1).contextSwitch += 1;						
					}
					
					trigger = true;
					//index = i;
					break;
				}
				
			}			
			if(!trigger) queue.add(new Node(size, last, arrive, burst));
			
		}
		size++;
			//track helpers
			/*if(queue.size() > 0) System.out.println("The queue is not empty");
			else System.out.println("We are empty");
			//track helpers
				System.out.println("The size of the queue is now " + queue.size());
				System.out.println("The queue added: at index " + index 
									+ " with arrival at " + queue.get(queue.size() - 1).arrival);
				System.out.println(" with period of " + queue.get(queue.size() - 1).arrivalPeriod
									+ " with burst of " + queue.get(queue.size() - 1).burst);
				System.out.println(" with termination at " + queue.get(queue.size() - 1).termination
									+ " with remaining of " + queue.get(queue.size() -1 ).remaining);
				System.out.println(" with a wait of " + queue.get(queue.size()-1).waitTime
									+ " and a switch of " + queue.get(queue.size()-1).contextSwitch);
				System.out.println("The tick is now " + tick);
		
			System.out.println();*/
		
	}
	
	public void pop() {
		//System.out.println("\nI am in pop()");

		if( queue.size() > 0) {
			
			tick += queue.get(0).remaining;			
			//track helper
			//System.out.println("\nThe ticks will increase by " + queue.get(0).remaining + " ticks");
			queue.get(0).remaining = 0;
			queue.get(0).termination = tick;
			if(queue.size() > 1) queue.get(1).waitTime += (tick - queue.get(1).termination);		
			pops++;
			table.addData(queue.get(0));
			queue.remove(0);
		}
		//track helpers
		System.out.println("There are " + queue.size() + " tasks in the queue and " + pops + " tasks have been popped");
		System.out.println("The ticks are " + tick + "\n");
		
	}
	
	public void reduce(double quantum) {
		//track helper
		
		//System.out.println("\nWe are in reduce and the quantum is " + quantum);
		if ( quantum < queue.get(0).remaining ) advance(quantum);
		else pop();
	}
	
	public void advance(double time) {
		//System.out.println("\nI am in advance()");
		//System.out.println("The queue size is " + queue.size());
		if (queue.size() > 0) {
			tick += time;
			//track helper
			//System.out.println("The tick will now increase by " + time + " ticks");
			queue.get(0).termination = tick;
			queue.get(0).contextSwitch += 1;	
			//System.out.println("The exit time for the head node is " + queue.get(0).termination
			//		+ " and the context switch is now " + queue.get(0).contextSwitch);
			if(queue.size() > 1) {
				queue.add(queue.get(0));
				queue.get(1).waitTime += (tick - queue.get(1).termination);
				queue.remove(0);
			}
			
			//track helpers
			//System.out.println("The tick is now " + tick);
			//System.out.println("The head node is moved to the end");
			
		}
		
	}
	
	public void getExpected() {
		if(queue.size() == 0) expected = tick;
		else expected = (double)(tick + queue.get(0).remaining);
	}
	
	public void getExpected(double counter) {
		if(queue.size() == 0) expected = tick;
		else if (counter > queue.get(0).remaining) {
			expected = (double)(tick + queue.get(0).remaining);
		} else expected = (double)(tick + counter);
	}
	
	public void getArrival() { 
		arrival();
		last += arrive;
	}

	public void getBurst() { burst(); }
		
	public boolean empty() { return (queue.size() == 0); }
	
	public boolean notReady() { return (expected < last); }
	
	public void setLambda(int k) { 
		lambda = k; 
		table.newLambda();
	}
	
	//not producing the correct average 
	/*private double genexp(double k) {
		double x = 0;
		while (x == 0 ) {
			x = (double)(-Math.log((double)(ran.nextDouble()))/k);
		}
		return x;
	}*/
	
	private void arrival() { 
		arrive = 0;
		while( arrive <= 0) arrive = (double)((ran.nextGaussian() + 1) / lambda); 
	}
	
	private void burst() { 
		burst = 0;
		while (burst <= 0 ) burst = (double)((ran.nextGaussian() + 6)/100); 
	}
	
	public void clear(String path) {
		table.print(path);
		table.clear();
		queue.clear();
		size = 0;
		tick = 0;
		last = 0;
		arrive = 0;
		pops = 0;
		pushes = 0;
		lambda = 0;
	}
}
