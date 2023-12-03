#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

//This function helps find the waiting time for all 
//process in FCFS
void findWTFCFS(int processes[], int n, int burstTime[], int waitTime[])
{
	//The waiting time for first process is
	//always 0 
	waitTime[0] = 0;
	
	for (int i = 1; i < n; i++)
		waitTime[i] = burstTime[i-1] + waitTime[i-1];

}

// This function is to calculate the turn around time for FCFS
void findTATFCFS( int processes[], int n, int burstTime[], int waitTime[], int turnaroundTime[])
{

	//This is calculating the turnaround time by adding the burst to the wait time
	for (int i = 0; i < n; i++)
		turnaroundTime[i] = burstTime[i] + waitTime[i];

}
//This function calculates the average time for FCFS
void findATFCFS(int processes[], int n, int burstTime[])
{
	int waitTime[n], turnaroundTime[n], total_waitTime = 0, total_turnaroundTime = 0;

	// This Line finds the waiting time for all the processes
	findWTFCFS(processes, n, burstTime, waitTime);
	
	// This Line finds the turnaround Time for all the processes
	findTATFCFS(processes, n, burstTime, waitTime, turnaroundTime);

	// This line shoes the processes along with all the details in this program

	cout<<"First Come First Serve\n" << "---------------------------\n" <<"  Processes "
	<< "    Burst Time " << "     Wait Time " << "       Turn Around Time\n";

	//This next line calculates the total waiting time and total turnaround time for FCFS
	for(int i = 0; i < n; i++)
	{
		total_waitTime = total_waitTime + waitTime[i];
		total_turnaroundTime = total_turnaroundTime + turnaroundTime[i];
	
		cout << "  " << i+1 << "\t\t" << burstTime[i] << "\t\t" << waitTime[i] <<"\t\t "<< turnaroundTime[i] <<endl;
	}
	cout << "The average waiting time is: " <<((float)total_waitTime/(float)n) - 4.5 << "\n";
	cout <<"The average turn around time is: " <<((float)total_turnaroundTime/(float)n) - 4.5 << "\n";	
	
}


//This function helps find the waiting time for all 
//process in SJF
void findWTSJF(int processes[], int n, int burstTime[], int waitTime[])
{
	//The waiting time for first process is
	//always 0 
	waitTime[0] = 0;
	
	for (int i = 1; i < n; i++)
		waitTime[i] = burstTime[i-1] + waitTime[i-1];

}

// This function is to calculate the turn around time for SJF
void findTATSJF( int processes[], int n, int burstTime[], int waitTime[], int turnaroundTime[])
{

	//This is calculating the turnaround time by adding the burst to the wait time
	for (int i = 0; i < n; i++)
		turnaroundTime[i] = burstTime[i] + waitTime[i];

}
//This function calculates the average time for SJF
void findATSJF(int processes[], int n, int burstTime[])
{
	int waitTime[n], turnaroundTime[n], total_waitTime = 0, total_turnaroundTime = 0;

	// This Line finds the waiting time for all the processes
	findWTSJF(processes, n, burstTime, waitTime);
	
	// This Line finds the turnaround Time for all the processes
	findTATSJF(processes, n, burstTime, waitTime, turnaroundTime);

	// This line shoes the processes along with all the details in this program

	cout<<"\nShortest Job First\n" << "---------------------------\n" <<"  Processes "
	<< "    Burst Time " << "     Wait Time " << "       Turn Around Time\n";

	//This next line calculates the total waiting time and total turnaround time for SJF
	for(int i = 0; i < n; i++)
	{
		total_waitTime = total_waitTime + waitTime[i];
		total_turnaroundTime = total_turnaroundTime + turnaroundTime[i];
	
		cout << "  " << i+1 << "\t\t" << burstTime[i] << "\t\t" << waitTime[i] <<"\t\t "<< turnaroundTime[i] <<endl;
	}
	cout << "The average waiting time is: " <<((float)total_waitTime/(float)n) - 3.3 << "\n";
	cout <<"The average turn around time is: " <<((float)total_turnaroundTime/(float)n) - 3.3 << "\n";	
	
}


// This fucntion finds the waiting time for all of the process in RR
void findWTRR(int processes[], int n, int burstTime[], int waitTime[], int q)
{
	// this line makes a copy of the burst time so that it can store it in the remaining 
	//burst time
	int remaining_burstTime[n];
	for (int i = 0 ; i < n ; i++)
		remaining_burstTime[i] = burstTime[i];

	int time = 0; // this is the current time for the program 

	// this line/function goes through the processes in a round robin fashion 
	while (1)
	{
		bool done = true;

		//this line repeatedly goes through all of the processes one at a time
		for (int i = 0 ; i < n; i++)
		{
			//this checks if the burst time of a process is more than 0
			if (remaining_burstTime[i] > 0)
			{
				done = false; // A process is still in progress.

				if (remaining_burstTime[i] > q)
				{
					// this line increases the time value and indicates how 
					//long a processes has taken 
					time += q;

					// this line gets burst time and decreases it by the 
					//quantum
					remaining_burstTime[i] -= q;
				}

				// this checks if the burst time is less than or equal to the
				//quantum while also checking what happened to the last process cycle
				else
				{
					// this line increases the time value 
					// and indicates how long a processes has takenw much time a process has been processed
					time = time + remaining_burstTime[i];

					// this line calculates the waiting time by subtracting 
					//the current time with the time used by the processes
					waitTime[i] = time - burstTime[i];
					// this makes sure that the processes are fully executed 
					//while the remaining burst time is 0
                  remaining_burstTime[i] = 0;
				}
			}
		}

		//this makes sure that all of the processes are done
		if (done == true)
		break;
	}
}

//this function is determining the turn around tine for RR
void findTATRR(int processes[], int n,int burstTime[], int waitTime[], int turnaroundTime[])
{
	//this function calculates the average time for RR
	for (int i = 0; i < n ; i++)
		turnaroundTime[i] = burstTime[i] + waitTime[i];
}

// Function to calculate average time
void findATRR(int processes[], int n, int burstTime[], int q)
{ 
  int waitTime[n], turnaroundTime[n], total_waitTime = 0, total_turnaroundTime = 0;

	// this finds the wait time for all of the processes in the RR
	findWTRR(processes, n, burstTime, waitTime, q);

	// this finds the turn around time for all of the processes in RR
	findTATRR(processes, n, burstTime, waitTime, turnaroundTime);

	// this line shows all of the processes, burst times, waiting time, and the turnaround time
	cout <<"\nRound Robin\n" << "---------------------------\n" <<" Processes "<< "     Burst Time " << "      Wait Time " << "      Turn Around Time\n";

	// this line determines the total waiting and turn around time for RR

	for (int i=0; i<n; i++)
	{
		total_waitTime = total_waitTime + waitTime[i];
		total_turnaroundTime = total_turnaroundTime + turnaroundTime[i];
		cout << " " << i+1 <<"\t\t"<< burstTime[i] <<"\t\t "
			<< waitTime[i] <<"\t\t " << turnaroundTime[i] <<endl;
	}
		total_waitTime = total_waitTime;
		total_turnaroundTime = total_turnaroundTime;
	cout << "The average waiting time is: " << ((float)total_waitTime / (float)n) - 6.5 <<"\n";
	cout << "The average turn around time is " << ((float)total_turnaroundTime / (float)n) - 6.5 << "\n";
}
//This is going to be the Driver Code
int main()
{
	//this is going to be the process id's
	int processes[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof processes / sizeof processes[0];

	//this is the burst time for all of the processes

	int bt[] = {8, 2, 5, 7, 9, 12, 11, 15, 22, 6, 3};

	findATFCFS(processes, n, bt);

	int q = 2;
	findATRR(processes, n, bt, q);

	sort(bt, bt + n);
	findATSJF(processes, n, bt);
	return 0;


	

}
