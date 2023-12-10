//first come first served scheduling algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id; //process ID
    int arrival; //arrival time
    int burst; //burst time
};

void printTable(const vector<Process>& processes) {
    cout << "User-Entered Table:" << endl;
    cout << "Process\tArrival\tBurst" << endl;

    for (const Process& p : processes) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst << endl;
    }
}

void fcfs(vector<Process>& processes){
    int n = processes.size();

    //sort processes based on arrival time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival < b.arrival;
    });

    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;

    cout<<"Process\tArrival\tBurst\tWaiting\tTurnaround\n";

    int currentTime = 0;

    for(const Process& p : processes){
        //waiting time for current process
        int waitTime = max(0, currentTime - p.arrival);

        //turnaround time for current process
        int turnaroundTime = waitTime + p.burst;

        //update total waiting and turnaround time
        totalWaitTime += waitTime;
        totalTurnAroundTime += turnaroundTime;

        //display results for the current time
        cout<<p.id<<"\t"<<p.arrival<<"\t"<<p.burst<<"\t"<<waitTime<<"\t\t"<<turnaroundTime<<"\n";

        //update current time
        currentTime += p.burst;
    }

    //calculate and display average waiting and turnaround time 
    double averageWaitingTime = static_cast<double>(totalWaitTime) / n;
    double averageTurnaroundTime = static_cast<double>(totalTurnAroundTime) / n;

    cout<<"Average waiting time = "<<averageWaitingTime<<"\n";
    cout<<"Average turnaround time = "<<averageTurnaroundTime<<"\n";

}

int main() {
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;

    vector<Process> processes(n);

    for(int i = 0; i < n; i++){
        processes[i].id = i + 1;
        cout<<"Enter arrival time for process "<<i + 1<<" : ";
        cin>>processes[i].arrival;
        cout<<"Enter burst time for process "<<i + 1<<" : ";
        cin>>processes[i].burst;
    }

    printTable(processes);
    fcfs(processes);
    return 0;
}
