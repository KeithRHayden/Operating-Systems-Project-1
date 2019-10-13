package scheduler;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Table {
	
	/*"Indices Guide
	 * 0 num pushes
	 * 1 num pops
	 * 2 total time
	 * 3 total wait
	 * 4 total switches
	 * 5 total arrival periods
	 * 6 total burst periods
	 * 7 num in ready queue
	 * 8 min wait
	 * 9 max wait
	 * 10 min exe time
	 * 11 max exe time
	 * 12 switches
	 * 13 max switches
	 * 14 avg throughput
	 * 15 avg sec/process
	 * 16 avg wait
	 * 17 average switches
	 * 18 average arrival
	 * 19 average burst
	 * 20 average in ready
	 * 21 min in ready
	 * 22 max in ready
	 * 23 lambda
	 * 
	 */
	
	ArrayList<ArrayList<Double>> printer = new ArrayList<ArrayList<Double>>();
	private static int index = 0;
	
	private static String header = "num pushes,num pops,time,wait,switches,"
									+ "arrival periods,total burst periods,"
									+ "num in ready queue,min wait,max wait,"
									+ "min exe time,max exe time,switches,"
									+ "max switches,avg throughput,avg sec/process,"
									+ "avg wait,average switches,average arrival,"
									+ "average burst,average in ready,min in ready,"
									+ "max in ready,lambda\n";
	private static String comma = ",";
	private static String endline = "\n";
	
	public Table() { printer.add(new ArrayList<Double>()); }
	
	public void newLambda() {
		
		printer.add(new ArrayList<Double>());
		++index;
		
	}
	
	public void addData(Node node) {
		
		if(printer.get(index).size() == 0) {
			printer.get(index).add((Double)(double)(ReadyQueue.pushes));
			printer.get(index).add((Double)(double)(ReadyQueue.pops));
			printer.get(index).add(node.termination);
			printer.get(index).add(node.waitTime);
			printer.get(index).add((Double)(double)(node.contextSwitch));
			printer.get(index).add(node.arrivalPeriod);
			printer.get(index).add(node.burst);
			printer.get(index).add((Double)(double)(ReadyQueue.size));
			printer.get(index).add(node.waitTime);
			printer.get(index).add(node.waitTime);
			double exeTime = node.termination - node.arrival;
			printer.get(index).add(exeTime);
			printer.get(index).add(exeTime);
			printer.get(index).add((Double)(double)(node.contextSwitch));
			printer.get(index).add((Double)(double)(node.contextSwitch));
			printer.get(index).add((Double)(double)(ReadyQueue.pops/printer.get(index).get(2)));
			printer.get(index).add((Double)(double)(printer.get(index).get(2)/ReadyQueue.pops));
			printer.get(index).add((Double)(double)(printer.get(index).get(3)/ReadyQueue.pops));
			printer.get(index).add((Double)(double)(printer.get(index).get(4)/ReadyQueue.pops));
			printer.get(index).add((Double)(double)(printer.get(index).get(5)/ReadyQueue.pops));
			printer.get(index).add((Double)(double)(printer.get(index).get(6)/ReadyQueue.pops));
			printer.get(index).add((Double)(double)(printer.get(index).get(7)/ReadyQueue.pops));
			printer.get(index).add((Double)(double)(ReadyQueue.size));
			printer.get(index).add((Double)(double)(ReadyQueue.size));
			printer.get(index).add((Double)(double)(ReadyQueue.lambda));
		}
		else {
			printer.get(index).set(0, (Double)(double)(ReadyQueue.pushes));
			printer.get(index).set(1, (Double)(double)(ReadyQueue.pops));
			printer.get(index).set(2, node.termination);
			printer.get(index).set(3, (printer.get(index).get(3) + node.waitTime));
			printer.get(index).set(4, (Double)(double)(printer.get(index).get(4) + node.contextSwitch));
			printer.get(index).set(5, (printer.get(index).get(5) + node.arrivalPeriod));
			printer.get(index).set(6, (printer.get(index).get(5) + node.burst));
			printer.get(index).set(7, (Double)(double)(printer.get(index).get(7) + ReadyQueue.size));
			if(printer.get(index).get(8) > node.waitTime) printer.get(index).set(8, node.waitTime);
			if(printer.get(index).get(9) < node.waitTime) printer.get(index).set(9, node.waitTime);
			double exeTime = node.termination - node.arrival;
			if(printer.get(index).get(10) > exeTime) printer.get(index).set(10, exeTime);
			if(printer.get(index).get(11) < exeTime) printer.get(index).set(11, exeTime);
			if(printer.get(index).get(12) > node.contextSwitch) printer.get(index).set(12, (Double)(double)(node.contextSwitch));
			if(printer.get(index).get(13) < node.contextSwitch) printer.get(index).set(13, (Double)(double)(node.contextSwitch));
			printer.get(index).set(14, (Double)(double)(ReadyQueue.pops/printer.get(index).get(2)));
			printer.get(index).set(15, (Double)(double)(printer.get(index).get(2)/ReadyQueue.pops));
			printer.get(index).set(16, (Double)(double)(printer.get(index).get(3)/ReadyQueue.pops));
			printer.get(index).set(17, (Double)(double)(printer.get(index).get(4)/ReadyQueue.pops));
			printer.get(index).set(18, (Double)(double)(printer.get(index).get(5)/ReadyQueue.pops));
			printer.get(index).set(19, (Double)(double)(printer.get(index).get(6)/ReadyQueue.pops));
			printer.get(index).set(20, (Double)(double)(printer.get(index).get(7)/ReadyQueue.pops));
			if(printer.get(index).get(21) > node.contextSwitch) printer.get(index).set(21, (Double)(double)(ReadyQueue.size));
			if(printer.get(index).get(22) < node.contextSwitch) printer.get(index).set(22, (Double)(double)(ReadyQueue.size));
			printer.get(index).set(23, (Double)(double)(ReadyQueue.lambda));
		}
		
		
	}
	
	public void print(String path) {

		File file = new File(path);
		FileWriter fw;
		try {
			file.createNewFile();
		} catch (IOException e1) {
			System.out.println("File was not created.");
		}		
		try {			
			if(ReadyQueue.lambda == 1) {
				fw = new FileWriter(path);
				fw.append(header);
			}
			else fw = new FileWriter(path, true);			
			for( ArrayList<Double> x : printer) {
				for ( Double n : x) {
					fw.append(n.toString());
					fw.append(comma);
				}
				fw.append(endline);
			}
			fw.flush();
			fw.close();
		} catch (IOException e) {
			System.out.println("File was not written to. \nPlease close the file first.");
		}	
		
	}
	
	public void clear() {
		
		printer.forEach((n)-> n.clear());
		printer.clear();
		index = -1;
		
	}
	
}
