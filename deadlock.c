#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    int finish[n];

    for(i = 0; i < n; i++) {
        int flag = 0;
        for(j = 0; j < m; j++) {
            if(alloc[i][j] != 0) {
                flag = 1;
                break;
            }
        }
        finish[i] = (flag == 0) ? 1 : 0;
    }

    int work[m];
    for(i = 0; i < m; i++)
        work[i] = avail[i];

    while(1) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                for(j = 0; j < m; j++)
                    if(request[i][j] > work[j])
                        break;

                if(j == m) {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
            break;
    }

    int deadlock = 0;
    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("Process P%d is in deadlock\n", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("No deadlock detected\n");

    return 0;
}
