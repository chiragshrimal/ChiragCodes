#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    char label[5];
    int arrival_time;
    int burst_time;
} Process;

// First Come First Served Scheduling

void run_fcfs(Process processes[], int num_processes) {
    int current_time = 0;
    int turnaround_times[num_processes];
    int wait_times[num_processes];

    printf("-------------------------------------------------\n");
    printf("       First Come First Served Scheduling\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_processes; i++) {
        int wait_time = (current_time > processes[i].arrival_time) ? (current_time - processes[i].arrival_time) : 0;
        int turnaround_time = wait_time + processes[i].burst_time;

        printf("[%d-%d]   %s running\n", current_time, current_time + processes[i].burst_time, processes[i].label);

        turnaround_times[i] = turnaround_time;
        wait_times[i] = wait_time;

        current_time += processes[i].burst_time;
    }

    double avg_turnaround_time = 0.0;
    double avg_wait_time = 0.0;
    for (int i = 0; i < num_processes; i++) {
        avg_turnaround_time += turnaround_times[i];
        avg_wait_time += wait_times[i];
    }

    avg_turnaround_time /= num_processes;
    avg_wait_time /= num_processes;

    printf("Turnaround times: ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s[%d], ", processes[i].label, turnaround_times[i]);
    }
    printf("\n");

    printf("Wait times:       ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s[%d], ", processes[i].label, wait_times[i]);
    }
    printf("\n");

    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average wait time:       %.2f\n", avg_wait_time);

    printf("Hit any key to continue ... ");
    getchar(); // Consume the newline character
    getchar(); // Wait for user input
}

// Round Robin Scheduling

void run_rr(Process processes[], int num_processes, int quantum_time) {
    Process queue[num_processes];
    for (int i = 0; i < num_processes; i++) {
        queue[i] = processes[i];
    }

    int front = 0;
    int rear = num_processes - 1;
    int current_time = 0;
    int turnaround_times[num_processes];
    int wait_times[num_processes];

    printf("-------------------------------------------------\n");
    printf("             Round Robin Scheduling\n");
    printf("-------------------------------------------------\n");

    while (front <= rear) {
        Process current_process = queue[front];
        front = (front + 1) % num_processes;  // Increment index after accessing the current process
        int burst_time = (current_process.burst_time <= quantum_time) ? current_process.burst_time : quantum_time;

        int wait_time = (current_time > current_process.arrival_time) ? (current_time - current_process.arrival_time) : 0;
        int turnaround_time = wait_time + burst_time;

        printf("[%d-%d]   %s running\n", current_time, current_time + burst_time, current_process.label);

        turnaround_times[front - 1] = current_time + burst_time;  // Corrected the calculation
        wait_times[front - 1] = wait_time;

        current_time += burst_time;

        current_process.burst_time -= burst_time;
        if (current_process.burst_time > 0) {
            queue[rear] = current_process;
            rear = (rear + 1) % num_processes;  // Increment index after adding the current process to the queue
        }
    }

    double avg_turnaround_time = 0.0;
    double avg_wait_time = 0.0;
    for (int i = 0; i < num_processes; i++) {
        avg_turnaround_time += turnaround_times[i];
        avg_wait_time += wait_times[i];
    }

    avg_turnaround_time /= num_processes;
    avg_wait_time /= num_processes;

    printf("Turnaround times: ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s[%d] ", processes[i].label, turnaround_times[i]);
    }
    printf("\n");

    printf("Wait times:       ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s[%d] ", processes[i].label, wait_times[i]);
    }
    printf("\n");

    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average wait time:       %.2f\n", avg_wait_time);

    printf("Hit any key to continue ... ");
    getchar(); // Consume the newline character
    getchar(); // Wait for user input
}

// Shortest Remaining Burst First

int compare_srbf(const void *a, const void *b) {
    return ((Process *)a)->burst_time - ((Process *)b)->burst_time;
}

void run_srbf(Process processes[], int num_processes) {
    int current_time = 0;
    int turnaround_times[num_processes];
    int wait_times[num_processes];

    // Sort processes based on burst time
    qsort(processes, num_processes, sizeof(Process), compare_srbf);

    printf("-------------------------------------------------\n");
    printf("    Shortest Remaining Burst First (SRBF)\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_processes; i++) {
        int wait_time = (current_time > processes[i].arrival_time) ? (current_time - processes[i].arrival_time) : 0;
        int turnaround_time = wait_time + processes[i].burst_time;

        printf("[%d-%d]   %s running\n", current_time, current_time + processes[i].burst_time, processes[i].label);

        turnaround_times[i] = turnaround_time;
        wait_times[i] = wait_time;

        current_time += processes[i].burst_time;
    }

    double avg_turnaround_time = 0.0;
    double avg_wait_time = 0.0;
    for (int i = 0; i < num_processes; i++) {
        avg_turnaround_time += turnaround_times[i];
        avg_wait_time += wait_times[i];
    }

    avg_turnaround_time /= num_processes;
    avg_wait_time /= num_processes;

    printf("Turnaround times: ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s[%d] ", processes[i].label, turnaround_times[i]);
    }
    printf("\n");

    printf("Wait times:       ");
    for (int i = 0; i < num_processes; i++) {
        printf("%s[%d] ", processes[i].label, wait_times[i]);
    }
    printf("\n");

    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average wait time:       %.2f\n", avg_wait_time);

    printf("Hit any key to continue ... ");
    getchar(); // Consume the newline character
    getchar(); // Wait for user input
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int num_processes = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        num_processes++;
    }

    fseek(file, 0, SEEK_SET); // Reset the file pointer to the beginning of the file

    Process processes[num_processes];

    for (int i = 0; i < num_processes; i++) {
        fscanf(file, "%s%d%d", processes[i].label, &processes[i].arrival_time, &processes[i].burst_time);
    }

    fclose(file);

    while (1) {
        printf("-------------------------------------------------\n");
        printf("            CPU Scheduling Simulation\n");
        printf("-------------------------------------------------\n");
        printf("Select the scheduling algorithm [1, 2, 3 or 4]:\n");
        printf("1. First Come First Served (FCFS)\n");
        printf("2. Round Robin (RR)\n");
        printf("3. Shortest Remaining Burst First (SRBF)\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                run_fcfs(processes, num_processes);
                break;
            case 2: {
                int quantum_time;
                printf("Enter the time quantum: ");
                scanf("%d", &quantum_time);
                run_rr(processes, num_processes, quantum_time);
                break;
            }
            case 3:
                run_srbf(processes, num_processes);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}