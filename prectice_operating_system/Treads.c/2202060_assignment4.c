#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int max_need[MAX_PROCESSES][MAX_RESOURCES] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

bool finished[MAX_PROCESSES] = {false};

void deadlock_detection() {
    int available[MAX_RESOURCES] = {0};

    // Calculate available resources
    for (int j = 0; j < MAX_RESOURCES; j++) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            available[j] += allocation[i][j];
        }
    }

    for (int j = 0; j < MAX_RESOURCES; j++) {
        available[j] -= max_need[0][j];
    }

    bool deadlock_detected = false;

    while (true) {
        bool found = false;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!finished[i]) {
                bool can_allocate = true;
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    if (max_need[i][j] > available[j]) {
                        can_allocate = false;
                        break;
                    }
                }

                if (can_allocate) {
                    printf("Process %d is satisfied and released\n", i);
                    finished[i] = true;
                    found = true;
                    for (int j = 0; j < MAX_RESOURCES; j++) {
                        available[j] += allocation[i][j];
                    }
                    break;
                }
            }
        }

        if (!found) {
            // Check for deadlock
            for (int i = 0; i < MAX_PROCESSES; i++) {
                if (!finished[i]) {
                    bool deadlock = true;
                    for (int j = 0; j < MAX_RESOURCES; j++) {
                        if (max_need[i][j] > available[j]) {
                            deadlock = false;
                            break;
                        }
                    }
                    if (deadlock) {
                        printf("Process %d is deadlocked\n", i);
                        deadlock_detected = true;
                    }
                }
            }
            break;
        }
    }

    if (!deadlock_detected) {
        printf("No deadlock detected.\n");
    }
}

int main() {
    deadlock_detection();
    return 0;
}