#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int burstTime;
    int priority;
};

bool comparePriority(Process a, Process b) {
    return a.priority < b.priority; // Lower number indicates higher priority
}

void priorityScheduling(vector<Process>& processes, int n) {
    sort(processes.begin(), processes.end(), comparePriority);

    int currentTime = 0;
    cout << "Process execution order: ";
    for (const auto& p : processes) {
        cout << "P" << p.pid << " ";
        currentTime += p.burstTime; // Update the total time
    }
    cout << "\nTotal Time: " << currentTime << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter burst time and priority for process " << i + 1 << ": ";
        cin >> processes[i].burstTime >> processes[i].priority;
        processes[i].pid = i + 1;
    }

    priorityScheduling(processes, n);

    return 0;
}
