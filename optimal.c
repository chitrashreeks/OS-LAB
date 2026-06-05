#include <stdio.h>

int main()
{
    int pages[50], frame[20];
    int n, frames, i, j, k;
    int fault = 0, found, pos = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int farthest = -1;

            for(j = 0; j < frames; j++)
            {
                int nextUse = 9999;

                for(k = i + 1; k < n; k++)
                {
                    if(frame[j] == pages[k])
                    {
                        nextUse = k;
                        break;
                    }
                }

                if(nextUse > farthest)
                {
                    farthest = nextUse;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}
