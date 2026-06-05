#include <stdio.h>

int main()
{
    int nb, np, i, j, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[20], originalBlock[20];

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);
        originalBlock[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[20];

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    printf("\nMemory Allocation Techniques\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int allocation[20];

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    switch(choice)
    {
        case 1: // First Fit
            for(i = 0; i < np; i++)
            {
                for(j = 0; j < nb; j++)
                {
                    if(block[j] >= process[i])
                    {
                        allocation[i] = j;
                        block[j] -= process[i];
                        break;
                    }
                }
            }
            break;

        case 2: // Best Fit
            for(i = 0; i < np; i++)
            {
                int best = -1;

                for(j = 0; j < nb; j++)
                {
                    if(block[j] >= process[i])
                    {
                        if(best == -1 || block[j] < block[best])
                            best = j;
                    }
                }

                if(best != -1)
                {
                    allocation[i] = best;
                    block[best] -= process[i];
                }
            }
            break;

        case 3: // Worst Fit
            for(i = 0; i < np; i++)
            {
                int worst = -1;

                for(j = 0; j < nb; j++)
                {
                    if(block[j] >= process[i])
                    {
                        if(worst == -1 || block[j] > block[worst])
                            worst = j;
                    }
                }

                if(worst != -1)
                {
                    allocation[i] = worst;
                    block[worst] -= process[i];
                }
            }
            break;

        default:
            printf("Invalid Choice!\n");
            return 0;
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < np; i++)
    {
        printf("P%d\t\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}