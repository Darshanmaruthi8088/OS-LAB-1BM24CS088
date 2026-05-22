#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

int main() {

    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };


    int request[P][R] = {
        {0, 0, 0},
        {2, 0, 2},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 2}
    };


    int available[R] = {0, 0, 0};

    bool finish[P] = {false};
    int work[R];
    for (int i = 0; i < R; i++) work[i] = available[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool possible = true;
                for (int j = 0; j < R; j++) {
                    if (request[p][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int k = 0; k < R; k++) {
                        work[k] += allocation[p][k];
                    }
                    finish[p] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) break;
    }

    bool deadlock = false;
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            deadlock = true;
            printf("Process P%d is in deadlock.\n", i);
        }
    }

    if (!deadlock) {
        printf("No deadlock detected. System is in a safe state.\n");
    }

    return 0;
}

