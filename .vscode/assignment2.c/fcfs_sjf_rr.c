#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include<limits.h>

#define MAX_PROCESSES 100

typedef struct {
    char label[10];
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
} Process;

void fcfs(Process processes[], int num_processes) {
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;
        printf("Process %s: Started at %d, Finished at %d\n", processes[i].label, current_time, current_time + processes[i].burst_time);
        current_time += processes[i].burst_time;
    }
}

void round_robin(Process processes[], int num_processes, int quantum) {
    int current_time = 0;
    int remaining_processes = num_processes;
    while (remaining_processes > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_burst_time > 0) {
                if (processes[i].remaining_burst_time <= quantum) {
                    current_time += processes[i].remaining_burst_time;
                    printf("Process %s: Started at %d, Finished at %d\n", processes[i].label, current_time - processes[i].remaining_burst_time, current_time);
                    processes[i].remaining_burst_time = 0;
                    remaining_processes--;
                } else {
                    current_time += quantum;
                    processes[i].remaining_burst_time -= quantum;
                    printf("Process %s: Started at %d, Paused at %d\n", processes[i].label, current_time - quantum, current_time);
                }
            }
        }
    }
}

void srbf(Process processes[], int num_processes) {
    Process processes1[num_processes];
    for(int i=0;i<num_processes;i++){
        processes1[i].arrival_time=processes[i].arrival_time;
        processes1[i].burst_time=processes[i].burst_time;
        processes1[i].remaining_burst_time=processes[i].remaining_burst_time;
    }
    int current_time = 0;
    int remaining_processes = num_processes;
    while (remaining_processes > 0) {
        int min_burst_time = INT_MAX;
        int min_process_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes1[i].arrival_time <= current_time && processes1[i].remaining_burst_time > 0) {
                if (processes1[i].remaining_burst_time < min_burst_time) {
                    min_burst_time = processes1[i].remaining_burst_time;
                    min_process_index = i;
                }
            }
        }
        if (min_process_index != -1) {
            current_time += processes1[min_process_index].remaining_burst_time;
            printf("Process %s: Started at %d, Finished at %d\n", processes1[min_process_index].label, current_time - processes1[min_process_index].remaining_burst_time, current_time);
            processes1[min_process_index].remaining_burst_time = 0;
            remaining_processes--;
        } else {
            current_time++;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    char label[10];
    int arrival_time, burst_time;
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(fp, "%s %d %d", label, &arrival_time, &burst_time) == 3) {
        strcpy(processes[num_processes].label, label);
        processes[num_processes].arrival_time = arrival_time;
        processes[num_processes].burst_time = burst_time;
        processes[num_processes].remaining_burst_time = burst_time;
        num_processes++;
    }
    fclose(fp);

printf("\nSRBF Scheduling:\n");
    srbf(processes, num_processes);

    printf("FCFS Scheduling:\n");
    fcfs(processes, num_processes);

    printf("\nRound Robin Scheduling (Quantum: 2):\n");
    round_robin(processes, num_processes, 3);

    return 0;
}