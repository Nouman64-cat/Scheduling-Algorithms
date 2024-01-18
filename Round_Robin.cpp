#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int pid; // Process ID
    int arrivalTime; // Arrival Time of the process
    int burstTime; // Burst Time of the process
    int remainingTime; // Remaining execution time of the process
    int completionTime; // Completion time of the process
};

// Function to find the completion time of each process
void findCompletionTime(vector<Process>& processes, int n, int quantum) {
    int currentTime = 0;
    queue<int> q; // Queue to keep track of processes
    vector<bool> inQueue(n, false); // To check if a process is already in the queue

    // Initially, add all processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime == 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        inQueue[i] = false;

        // Process the next process
        int timeSlice = min(quantum, processes[i].remainingTime);
        processes[i].remainingTime -= timeSlice;
        currentTime += timeSlice;

        // Check if other processes have arrived by now
        for (int j = 0; j < n; j++) {
            if (!inQueue[j] && processes[j].remainingTime > 0 && processes[j].arrivalTime <= currentTime) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        // If the current process is not finished, add it to the end of the queue
        if (processes[i].remainingTime > 0) {
            q.push(i);
            inQueue[i] = true;
        } else {
            processes[i].completionTime = currentTime;
        }
    }
}

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "Enter quantum: ";
    cin >> quantum;

    findCompletionTime(processes, n, quantum);

    // Display processes along with completion time
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\n";
    for (const auto& p : processes) {
        cout << " " << p.pid << "\t\t"
             << p.arrivalTime << "\t\t"
             << p.burstTime << "\t\t"
             << p.completionTime << endl;
    }

    return 0;
}
