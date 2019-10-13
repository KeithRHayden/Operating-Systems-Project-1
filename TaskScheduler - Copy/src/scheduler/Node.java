package scheduler;

public class Node {
	
	public int index;
	public double arrival;
	public double arrivalPeriod;
	public double termination;
	public double waitTime;
	public int contextSwitch;
	public double burst;
	public double remaining;
	
	public Node(int ind, double arr, double arrP, double serviceT) {
		index = ind;
		arrival = arr;
		arrivalPeriod = arrP;
		termination = arr;
		waitTime = 0;
		contextSwitch = 0;
		burst = serviceT;
		remaining = burst;	
	}
}
