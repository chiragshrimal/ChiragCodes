
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

bool can_finish(int alloc[MAX_PROCESSES][MAX_RESOURCES], int req[MAX_PROCESSES][MAX_RESOURCES], bool finish[], int available[], int n, int m) {
    int work[m];
    for (int i = 0; i < m; i++)
        work[i] = available[i];

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            bool safe = true;
            for (int j = 0; j < m; j++) {
                if (req[i][j] > work[j]) { // request > available
                    safe = false;
                    break;
                }
            }
            if (safe) {
                found = true;
                finish[i] = true;
                for (int j = 0; j < m; j++)
                    work[j] += alloc[i][j]; // available += allocated
                break;
            }
        }
    }
    return found;
}

void detect_deadlock(int alloc[MAX_PROCESSES][MAX_RESOURCES], int req[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int n, int m) {
    bool finish[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        finish[i] = false;

    // Find a process that can finish
    bool deadlock = false; // Initialize deadlock to false
    for (int i = 0; i < n; i++) {
        if (!can_finish(alloc, req, finish, available, n, m)) {
            deadlock = true; // Set deadlock to true if no process can finish
            break;
        }
    }

    if (!deadlock) {
        printf("No deadlock\n");
        return;
    }

    // Find the smallest set of processes whose termination ends the deadlock
    printf("Deadlock detected, processes to terminate: ");
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            printf("%d ", i);
            break;
        }
    }
    printf("\n");
}

// int main() {
//     // int total_resources = 3;
//     // int instances[] = {3, 5, 2};
//     // int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES] = {
//     //     {0, 1, 0},
//     //     {1, 0, 2},
//     //     {1, 3, 1},
//     //     {0, 0, 1},
//     //     {4, 2, 3}
//     // };
//     // int request_matrix[MAX_PROCESSES][MAX_RESOURCES] = {
//     //     {1, 1, 0},
//     //     {1, 2, 3},
//     //     {3, 1, 1},
//     //     {0, 0, 1},
//     //     {3, 2, 2}
//     // };

//     int total_resources = 3;
//     int instances[] = {2, 2, 2};
//     int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES] = {
//         {0, 1, 1},
//         {1, 0, 1},
//         {1, 1, 0},
//         {0, 0, 0},
//         {0, 0, 0}
//     };
//     int request_matrix[MAX_PROCESSES][MAX_RESOURCES] = {
//         {1, 1, 0},
//         {0, 1, 1},
//         {1, 0, 1},
//         {0, 0, 0},
//         {0, 0, 0}
//     };

//     // int total_resources = 3;
//     // int instances[] = {3, 3, 3};
//     // int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES] = {
//     //     {0, 1, 0},
//     //     {2, 0, 0},
//     //     {0, 0, 1},
//     //     {0, 0, 0},
//     //     {0, 0, 0}
//     // };
//     // int request_matrix[MAX_PROCESSES][MAX_RESOURCES] = {
//     //     {0, 0, 0},
//     //     {0, 0, 0},
//     //     {0, 0, 0},
//     //     {0, 0, 0},
//     //     {0, 0, 0}
//     // };
    
//     // Available resources
//     int available[MAX_RESOURCES];
//     for (int i = 0; i < total_resources; i++) {
//         available[i] = instances[i];
//         for (int j = 0; j < MAX_PROCESSES; j++) {
//             available[i] -= allocation_matrix[j][i];
//         }
//     }

//     // Detect deadlock
//     detect_deadlock(allocation_matrix, request_matrix, available, MAX_PROCESSES, total_resources);

//     return 0;
// }


int main() {
    int total_resources;
    printf("Enter the total number of resources: ");
    scanf("%d", &total_resources);

    int instances[MAX_RESOURCES];
    printf("Enter the available instances of each resource:\n");
    for (int i = 0; i < total_resources; i++) {
        scanf("%d", &instances[i]);
    }

    int n; // Number of processes
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES];
    printf("Enter the allocation matrix (%d rows, %d columns):\n", n, total_resources);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < total_resources; j++) {
            scanf("%d", &allocation_matrix[i][j]);
        }
    }

    int request_matrix[MAX_PROCESSES][MAX_RESOURCES];
    printf("Enter the request matrix (%d rows, %d columns):\n", n, total_resources);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < total_resources; j++) {
            scanf("%d", &request_matrix[i][j]);
        }
    }
    
    // Available resources
    int available[MAX_RESOURCES];
    for (int i = 0; i < total_resources; i++) {
        available[i] = instances[i];
        for (int j = 0; j < n; j++) {
            available[i] -= allocation_matrix[j][i];
        }
    }

    // Detect deadlock
    detect_deadlock(allocation_matrix, request_matrix, available, n, total_resources);

    return 0;
}
	
