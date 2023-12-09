//shortest job first (Non - preemptive case)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id; //process ID
    int arrival; //arrival time
    int burst; //burst time
    int completion; //completion time
};

bool compareArrival(const Process& a, const Process& b){
    return a.arrival < b.arrival;
}

bool compareBurst(const Process& a, const Process& b){
    return a.burst < b.burst;
}


void sjf(vector<Process>& processes){
    int n = processes.size();

    //sorting based on arrival time 
    sort(processes.begin(), processes.end(), compareArrival);

    int currentTime = 0;

    for(int i = 0; i < n; i++){
        //wait until the process arrives
        while(currentTime < processes[i].arrival){
            currentTime++;
        }

        //sort the remaining processes based on burst time
        sort(processes.begin() + i, processes.end(), compareBurst);

        //assign completion time to current process
        processes[i].completion = currentTime + processes[i].burst;

        //update current time
        currentTime += processes[i].burst;
    }

    // Display the schedule
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\n";
    for (const Process& p : processes) {
        cout << p.id << "\t" << p.arrival << "\t\t" << p.burst << "\t\t" << p.completion << "\n";
    }

    //calculate and display average waiting and turnaround time
    double totalWaitingTime = static_cast<double>(processes[0].completion - processes[0].arrival - processes[0].burst);
    double totalTurnaroundTime = static_cast<double>(processes[0].completion - processes[0].arrival);

    for(int i = 1; i < n; i++){
        totalWaitingTime += static_cast<double>(processes[i].completion - processes[i].arrival - processes[i].burst);
        totalTurnaroundTime += static_cast<double>(processes[i].completion - processes[i].arrival);
    }

    double averageWaitingTime = totalWaitingTime / n;
    double averageTurnaroundTime = totalTurnaroundTime / n;

    //display average wait time and turn around time
    cout<<"Average waiting time = "<<averageWaitingTime<<"\n";
    cout<<"Average turnaround time = "<<averageTurnaroundTime<<"\n";
    
}


int main() {
    int n;
    cout<<"Enter number of processes : ";
    cin>> n;

    vector<Process> processes(n);

    for(int i = 0; i < n; i++){
        processes[i].id = i + 1;
        cout<<"Enter arrival time of process "<<i + 1<<" : ";
        cin>>processes[i].arrival;
        cout<<"Enter burst time of process "<<i + 1<<" : ";
        cin>>processes[i].burst;
    }

    sjf(processes);
    return 0;
}
