#include <stdio.h>

int main()
{
    int pages[50], frame[20], time[20];
    int n, frames, i, j, pos, fault = 0;
    int counter = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            pos = 0;
            for(j = 1; j < frames; j++)
            {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            fault++;
        }
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}
