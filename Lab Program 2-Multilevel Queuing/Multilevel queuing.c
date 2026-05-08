/*#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};


void fcfs(struct Process p[], int n) {
    int i;


    p[0].waiting_time = 0;


    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }


    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}


void display(struct Process p[], int n, char queue_name[]) {
    int i;
    float total_wt = 0, total_tat = 0;

    printf("\n%s Queue:\n", queue_name);
    printf("PID\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].burst_time,
               p[i].waiting_time,
               p[i].turnaround_time);

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("Average Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    int i, n_sys, n_user;


    printf("Enter number of System Processes: ");
    scanf("%d", &n_sys);

    struct Process sys[n_sys];

    for (i = 0; i < n_sys; i++) {
        printf("Enter Burst Time for System Process %d: ", i + 1);
        sys[i].pid = i + 1;
        scanf("%d", &sys[i].burst_time);
    }


    printf("\nEnter number of User Processes: ");
    scanf("%d", &n_user);

    struct Process user[n_user];

    for (i = 0; i < n_user; i++) {
        printf("Enter Burst Time for User Process %d: ", i + 1);
        user[i].pid = i + 1;
        scanf("%d", &user[i].burst_time);
    }


    fcfs(sys, n_sys);
    fcfs(user, n_user);


    display(sys, n_sys, "System (High Priority)");
    display(user, n_user, "User (Low Priority)");

    return 0;
}
*/
