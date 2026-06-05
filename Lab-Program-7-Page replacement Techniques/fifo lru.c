#include <stdio.h>

int main() {
    int n, frames, choice;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("\nChoose Page Replacement Algorithm:\n");
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("3. Optimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    int frame[frames];
    int pageFaults = 0;

    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    switch(choice) {

        case 1: {   // FIFO
            int index = 0;

            for(int i = 0; i < n; i++) {
                int found = 0;

                for(int j = 0; j < frames; j++) {
                    if(frame[j] == pages[i]) {
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    frame[index] = pages[i];
                    index = (index + 1) % frames;
                    pageFaults++;
                }
            }

            printf("\nFIFO Page Faults = %d\n", pageFaults);
            break;
        }

        case 2: {   // LRU
            int time[frames];

            for(int i = 0; i < frames; i++)
                time[i] = 0;

            for(int i = 0; i < n; i++) {
                int found = 0;

                for(int j = 0; j < frames; j++) {
                    if(frame[j] == pages[i]) {
                        found = 1;
                        time[j] = i;
                        break;
                    }
                }

                if(!found) {
                    int pos = -1;

                    for(int j = 0; j < frames; j++) {
                        if(frame[j] == -1) {
                            pos = j;
                            break;
                        }
                    }

                    if(pos == -1) {
                        pos = 0;
                        for(int j = 1; j < frames; j++) {
                            if(time[j] < time[pos])
                                pos = j;
                        }
                    }

                    frame[pos] = pages[i];
                    time[pos] = i;
                    pageFaults++;
                }
            }

            printf("\nLRU Page Faults = %d\n", pageFaults);
            break;
        }

        case 3: {   // Optimal
            for(int i = 0; i < n; i++) {
                int found = 0;

                for(int j = 0; j < frames; j++) {
                    if(frame[j] == pages[i]) {
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    int pos = -1;

                    for(int j = 0; j < frames; j++) {
                        if(frame[j] == -1) {
                            pos = j;
                            break;
                        }
                    }

                    if(pos == -1) {
                        int farthest = -1;

                        for(int j = 0; j < frames; j++) {
                            int k;
                            for(k = i + 1; k < n; k++) {
                                if(frame[j] == pages[k])
                                    break;
                            }

                            if(k == n) {
                                pos = j;
                                break;
                            }

                            if(k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                        }
                    }

                    frame[pos] = pages[i];
                    pageFaults++;
                }
            }

            printf("\nOptimal Page Faults = %d\n", pageFaults);
            break;
        }

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}


