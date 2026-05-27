#include<stdio.h>

#define MAX 20

void firstFit(int blocks[], int m, int processes[], int n) {
int allocation[MAX];
for (int i = 0; i < n; i++)
allocation[i] = -1;

for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (blocks[j] >= processes[i]) {
allocation[i] = j;
blocks[j] -= processes[i];
break;
}
}
}

printf("\nFirst Fit Allocation:\n");
for (int i = 0; i < n; i++) {
if (allocation[i] != -1)
printf("Process %d -&gt; Block %d\n", i + 1, allocation[i] + 1);
else
printf("Process %d -&gt; Not Allocated\n", i + 1);
}

}

void bestFit(int blocks[], int m, int processes[], int n) {
int allocation[MAX];
for (int i = 0; i < n; i++)
allocation[i] = -1;

for (int i = 0; i < n; i++) {
int bestIdx = -1;
for (int j = 0; j < m; j++) {
if (blocks[j] >= processes[i]) {
if (bestIdx == -1 || blocks[j] < blocks[bestIdx])
bestIdx = j;
}
}
if (bestIdx != -1) {
allocation[i] = bestIdx;
blocks[bestIdx] -= processes[i];
}
}

printf("\nBest Fit Allocation:\n");
for (int i = 0; i < n; i++) {
if (allocation[i] != -1)
printf("Process %d -&gt; Block %d\n", i + 1, allocation[i] + 1);
else
printf("Process %d -&gt; Not Allocated\n", i + 1);
}
}

void worstFit(int blocks[], int m, int processes[], int n) {
int allocation[MAX];
for (int i = 0; i < n; i++)
allocation[i] = -1;

for (int i = 0; i < n; i++) {
int worstIdx = -1;
for (int j = 0; j < m; j++) {
if (blocks[j] >= processes[i]) {
if (worstIdx == -1 || blocks[j] > blocks[worstIdx])
worstIdx = j;
}
}
if (worstIdx != -1) {
allocation[i] = worstIdx;
blocks[worstIdx] -= processes[i];
}
}

printf("\nWorst Fit Allocation:\n");
for (int i = 0; i < n; i++) {
if (allocation[i] != -1)
printf("Process %d -&gt; Block %d\n", i + 1, allocation[i] + 1);
else
printf("Process %d -&gt; Not Allocated\n", i + 1);
}
}

int main() {
int blocks[MAX], processes[MAX];

int m, n;

printf("Enter number of memory blocks:");
scanf("%d", &m);

printf("Enter sizes of blocks:\n");
for (int i = 0; i < m; i++)
scanf("%d", &blocks[i]);

printf("Enter number of processes:");
scanf("%d", &n);

printf("Enter sizes of processes:\n");
for (int i = 0; i < n; i++)
scanf("%d", &processes[i]);


int blocks1[MAX], blocks2[MAX], blocks3[MAX];
for (int i = 0; i < m; i++) {
blocks1[i] = blocks[i];
blocks2[i] = blocks[i];
blocks3[i] = blocks[i];
}

firstFit(blocks1, m, processes, n);
bestFit(blocks2, m, processes, n);
worstFit(blocks3, m, processes, n);

return 0;
}
