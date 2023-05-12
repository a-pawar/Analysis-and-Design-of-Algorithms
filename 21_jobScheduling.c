#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100

struct job {
    int id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    return ((struct job *) b)->profit - ((struct job *) a)->profit;
}

void schedule_jobs(struct job jobs[], int num_jobs) {
    qsort(jobs, num_jobs, sizeof(struct job), compare);

    int max_deadline = 0;
    for (int i = 0; i < num_jobs; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }

    int schedule[max_deadline];
    for (int i = 0; i < max_deadline; i++) {
        schedule[i] = -1;
    }

    for (int i = 0; i < num_jobs; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                break;
            }
        }
    }

    printf("Scheduled jobs: ");
    for (int i = 0; i < max_deadline; i++) {
        if (schedule[i] != -1) {
            printf("%d ", schedule[i]);
        }
    }
    printf("\n");
}

int main() {
    struct job jobs[MAX_JOBS] = {
        {1, 4, 70},
        {2, 2, 60},
        {3, 4, 50},
        {4, 3, 40},
        {5, 1, 30},
        {6, 4, 20},
        {7, 6, 10},
    };

    int num_jobs = 7;

    schedule_jobs(jobs, num_jobs);

    return 0;
}
