#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int burstTime;
    int priority;
    int arrivalTime;
    int remainingTime;
};

// Custom comparator for priority queue (highest priority first; if equal, earlier arrival time first)
struct Comparator {
    bool operator()(const Process& a, const Process& b) {
        if (a.priority == b.priority)
            return a.arrivalTime > b.arrivalTime;
        return a.priority > b.priority;
    }
};

void preemptivePriorityScheduling(vector<Process>& processes) {
    priority_queue<Process, vector<Process>, Comparator> pq;
    vector<int> startTimes(processes.size(), -1);
    vector<int> completionTimes(processes.size(), 0);
    int currentTime = 0;
    int completed = 0;

    // Main loop
    while (completed != processes.size()) {
        // Add all processes that have arrived by currentTime
        for (auto &proc : processes) {
            if (proc.arrivalTime == currentTime) {
                pq.push(proc);
            }
        }

        if (!pq.empty()) {
            Process current = pq.top();
            pq.pop();

            // For first time execution, record start time
            if (startTimes[current.pid - 1] == -1) {
                startTimes[current.pid - 1] = currentTime;
            }

            // Process for one unit of time
            currentTime++;
            current.remainingTime--;

            // Check and add any new arrivals
            for (auto &proc : processes) {
                if (proc.arrivalTime == currentTime) {
                    pq.push(proc);
                }
            }

            // If completed, record completion time; else, add back to queue
            if (current.remainingTime == 0) {
                completionTimes[current.pid - 1] = currentTime;
                completed++;
            } else {
                pq.push(current);
            }
        } else {
            // If no process is ready, increment time
            currentTime++;
        }
    }

    // Display the results
    cout << "PID\tArrival\tBurst\tStart\tCompletion\n";
    for (int i = 0; i < processes.size(); ++i) {
        cout << i + 1 << "\t"
             << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t"
             << startTimes[i] << "\t"
             << completionTimes[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    preemptivePriorityScheduling(processes);

    return 0;
}
