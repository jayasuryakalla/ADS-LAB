#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id[10];
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

void jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);
    int result[n];
    int slot[n];
    int i, j;
    for (i = 0; i < n; i++) {
        slot[i] = -1;
    }
    int totalProfit = 0;
    int jobCount = 0;
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                result[j] = i;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    printf("Scheduled Jobs: \n");
    for (i = 0; i < jobCount; i++) {
        printf(" Job ID: %s,\nDeadline: %d, Profit: %d\n", jobs[result[i]].id, jobs[result[i]].deadline, jobs[result[i]].profit);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int i, n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter job details (ID, Deadline, Profit):\n");
    printf("JobID Deadline Profit\n");

    for (i = 0; i < n; i++) {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);
    return 0;
}
