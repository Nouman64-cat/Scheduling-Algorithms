//first come first served scheduling algorithm

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Process {
	int id; //process ID
	int arrival; //arrival time
	int burst; //burst time
	int completion; //completion time
	int waiting; //waiting time
	int turnaround; //turnaround time
};

void printTable(const vector<Process>& processes) {
	cout << "User-Entered Table:" << endl;
	cout << "Process\tArrival\tBurst" << endl;

	for (const Process& p : processes) {
		cout << p.id << "\t" << p.arrival << "\t" << p.burst << endl;
	}
}

void fcfs(vector<Process>& processes) {
	int n = processes.size();

	//sort processes based on arrival time
	sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
		return a.arrival < b.arrival;
		});

	int TOTAL_WAIT_TIME = 0;
	int TOTAL_TURNAROUND_TIME = 0;

	cout << "Process\tArrival\tBurst\tWaiting\tTurnaround" << endl;

	int currentTime = 0;

	for (Process& p : processes) {
		//waiting time for current process
		p.waiting = max(0, currentTime - p.arrival);

		//completion time for current process
		p.completion = currentTime + p.burst;

		//turn around time for current process
		p.turnaround = p.waiting + p.burst;

		//update total waiting and turnaround time
		TOTAL_WAIT_TIME += p.waiting;
		TOTAL_TURNAROUND_TIME += p.turnaround;

		//display results for current time
		cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.waiting << "\t" << p.turnaround << endl;

		currentTime += p.burst;
	}

	//calculate and display average waiting and turn around time 
	double AVERAGE_WAITING = static_cast<double>(TOTAL_WAIT_TIME) / n;
	double AVERAGE_TURNAROUND = static_cast<double>(TOTAL_TURNAROUND_TIME) / n;

	cout << "Average waiting time : " << AVERAGE_WAITING << endl;
	cout << "Average turnaround time : " << AVERAGE_TURNAROUND << endl;
}

int main() {
	int n;
	cout << "Enter number of processes: ";
	cin >> n;

	vector<Process> processes(n);

	for (int i = 0; i < n; i++) {
		processes[i].id = i + 1;
		cout << "Enter arrival time for the process " << i + 1 << " : ";
		cin >> processes[i].arrival;
		cout << "Enter burst time for the process " << i + 1 << " : ";
		cin >> processes[i].burst;
	}

	printTable(processes);
	fcfs(processes);

	return 0;
}
