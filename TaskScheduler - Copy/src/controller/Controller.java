package controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

import algorithms.Algorithms;

public class Controller {
		private static String welcome = "Welcome to the Task Scheduler Emulator.\n";
		private static String menu =  "\nThe following choices are available: \n"
				+ "  1  Process using First Come First Serve\n"
				+ "  2  Process using Shortest Remaining Time\n"
				+ "  3  Process using Round Robin with default quantums\n"
				+ "  4  Process using Round Robin and defined quantums\n"
				+ "  5  Quit this test program\n";
		static String input = "Please enter a int: ";
		static String low = "Please enter a double value for the low quantum: ";
		static String high = "Please enter a double value for the high quantum: ";
		private static String confirm = "Please confirm that you wish to exit (type \"Y\" or \"N\"): \n";
		private static String choice = "The input you made is not recognized. Please try again.";
		private static String goodbye = "Thank you. Goodbye....";
		private static String read = " was read.";
		private static double lowQ;
		private static double highQ;
		private static char x;
		private static Scanner sc;
		private static BufferedReader br;
		private static Algorithms al;
		private int ch;
public Controller() {
			
			
			br = new BufferedReader(new InputStreamReader(System.in));
			sc = new Scanner(System.in);
			al = new Algorithms();
			System.out.println(welcome);
}	

//User menu
public void run() {						
	try {
		do {
			ch = -1;
			while(ch < 1 || ch > 5) {					
				System.out.println(menu);
				if(!sc.hasNextInt()) {						
					sc.next();
					break;
				}
				ch = sc.nextInt();
				break;				
			}					
			switch(ch) {
				case 1:
					System.out.println( ch + read);
					al.testFCFS();
					break;						
				case 2:
					System.out.println( ch + read);
					al.testSRT();
					break;
				case 3:
					System.out.println( ch + read);
					al.testRR();
					break;
				case 4:
					System.out.println( ch + read);
					System.out.println( low );	
					while(!sc.hasNextDouble()) {
						System.out.println( choice );
						System.out.println( low );
						sc.next();
					}
					lowQ = sc.nextDouble();
					System.out.println( lowQ + read);
					System.out.println( high );
					while(!sc.hasNextDouble()) {
						System.out.println( choice );
						System.out.println( low );
						sc.next();
					}
					highQ = sc.nextDouble();
					System.out.println( highQ + read);
					al.testRR(lowQ, highQ);
					break;
				case 5:									
					System.out.print(confirm);
					br.mark(1);
					x = (char) br.read();	
					while (x == '\r' || x == '\n') {
						x = (char) br.read();
					}		
					System.out.println( x + read);
					if(x == 'N' || x == 'n') {							
						break;
					}
					else if(x == 'Y' || x == 'y') {		
						System.out.println( goodbye);
						sc.close();
						br.close();
						System.exit(0);
					}
					System.out.println(choice);
					break;	
				default:	
					System.out.println(choice);
			}
		}
		while(x !='Y' || x != 'y');  
	} catch (IOException e) {
		e.printStackTrace();
	}
}	

/*	
public void run() {	
	
	sc = new Scanner(System.in);

	do {
		
		printMenu();
		choice = getInput();
		switch (choice)
		{
		case 'a': case 'A':
			FCFS();
			break;

		case 'b': case 'B':
			SRT();
			break;

		case 'c': case 'C':
			RR();
			break;

		case 'd': case 'D':
			System.out.println("Please enter a double value for the low quantum: ");
			double lowChoice = getQuantum();
			System.out.println("Please enter a double value for the high quantum: ");
			double highChoice = getQuantum();
			RR(lowChoice, highChoice);
			break;

		case 'q': case 'Q':
			System.out.println("Quit option selected...bye");
			break;

		default:
			System.out.println(choice + " is not a valid option...try again");
		}
	} while (choice != 'q' && choice != 'Q');
	System.out.println("Press Enter or Return when ready...");
	cin.ignore();
	cin.get();
}

private void printMenu()
{
	System.out.println("\nThe following choices are available: \n"
			+ "  a  Process using First Come First Serve\n"
			+"  b  Process using Shortest Remaining Time\n"
			+ "  c  Process using Round Robin with default quantums\n"
			+ "  d  Process using Round Robin and defined quantums\n"
			+ "  q  Quit this test program\n");
}

private char getInput()
{
	char command;

	System.out.println("Enter choice: ");
	cin >> command;

	System.out.println(command + " read.");
	return command;
}

private float getQuantum() {
	double result;
	if(!sc.hasNext()) sc.nextLine();
	result;
	while (!cin.good())
	{
		System.out.println("Bad double input...");
		cin.clear();
		cin.ignore(999, '\n');
		System.out.println("Re-enter a float: ");
		cin >> result;
	}
	cin.ignore(999, '\n');
	System.out.println(result + " read.");
	return result;
}*/
}
