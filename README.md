# Scheduling-Algorithms
This C++ repository demonstrates three classic process scheduling algorithms - First Come First Served (FCFS), Shortest Job First (SJF), and Shortest Remaining Time First (SRTF). These algorithms play a crucial role in operating system design, determining the order in which processes are executed.

# 1. First Come First Served (FCFS)
Description:
FCFS is a simple and intuitive scheduling algorithm that executes processes in the order they arrive. This non-preemptive algorithm ensures that the first process to arrive is the first to be executed, leading to a sequential execution pattern.

Code Highlights:
User input for arrival and burst times.
Processes are sorted based on arrival times.
Schedule, completion times, and average waiting/turnaround times are displayed.
Usage:
Enter the number of processes.
Input arrival time and burst time for each process.
Obtain the schedule and performance metrics.
# 2. Shortest Job First (SJF)
Description:
SJF, a non-preemptive scheduling algorithm, selects the process with the shortest burst time first. This optimization minimizes the total processing time, leading to efficient resource utilization.

Code Highlights:
Processes are sorted based on arrival times.
Burst times are considered for dynamic process selection.
Average waiting and turnaround times are calculated and displayed.
Usage:
Enter the number of processes.
Input arrival time and burst time for each process.
View the optimized schedule and performance metrics.
# 3. Shortest Remaining Time First (SRTF)
Description:
SRTF is a preemptive version of SJF, dynamically selecting the process with the shortest remaining burst time. This preemptive approach aims to further reduce waiting and turnaround times.

Code Highlights:
Processes are sorted based on arrival times.
Dynamic process selection based on remaining burst time.
Average waiting and turnaround times are calculated and displayed.
Usage:
Enter the number of processes.
Input arrival time and burst time for each process.
Observe the dynamic schedule and performance metrics.
Conclusion
This repository provides a practical implementation of fundamental scheduling algorithms, offering insights into their behavior and efficiency. Users can explore, understand, and adapt the code for educational or real-world scenarios.
