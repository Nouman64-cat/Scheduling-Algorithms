#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Process {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining burst time
    int completion; // Completion time
};

bool compareArrival(const Process& a, const Process& b) {
    return a.arrival < b.arrival;
}

bool compareRemaining(const Process& a, const Process& b) {
    return a.remaining < b.remaining;
}

void srtf(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;
    int completedProcesses = 0;

    // Sorting based on arrival time
    sort(processes.begin(), processes.end(), compareArrival);

    while (completedProcesses < n) {
        int minRemaining = INT_MAX;
        int minIndex = -1;

        // Find the process with the shortest remaining time among those arrived
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival <= currentTime && processes[i].remaining > 0 &&
                processes[i].remaining < minRemaining) {
                minRemaining = processes[i].remaining;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            currentTime++;
        } else {
            // Execute the process
            processes[minIndex].remaining--;
            currentTime++;

            // Check if the process is completed
            if (processes[minIndex].remaining == 0) {
                processes[minIndex].completion = currentTime;
                completedProcesses++;
            }
        }
    }

    // Display the schedule
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\n";
    for (const Process& p : processes) {
        cout << p.id << "\t" << p.arrival << "\t\t" << p.burst << "\t\t" << p.completion << "\n";
    }

    // Calculate and display average waiting and turnaround time
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    for (int i = 0; i < n; ++i) {
        totalWaitingTime += static_cast<double>(processes[i].completion - processes[i].arrival - processes[i].burst);
        totalTurnaroundTime += static_cast<double>(processes[i].completion - processes[i].arrival);
    }

    double averageWaitingTime = totalWaitingTime / n;
    double averageTurnaroundTime = totalTurnaroundTime / n;

    // Display average wait time and turn around time
    cout << "Average waiting time = " << averageWaitingTime << "\n";
    cout << "Average turnaround time = " << averageTurnaroundTime << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes : ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time of process " << i + 1 << " : ";
        cin >> processes[i].arrival;
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> processes[i].burst;
        processes[i].remaining = processes[i].burst;
    }

    srtf(processes);
    return 0;
}
