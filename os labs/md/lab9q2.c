#include <stdio.h>
#include <stdlib.h>

int findLRU(int *timestamps, int n) {
    int min = 0;
    for (int i = 1; i < n; i++)
        if (timestamps[i] < timestamps[min]) min = i;
    return min;
}

void lruPageReplacement(int *pages, int numPages, int numFrames) {
    int *frames = malloc(numFrames * sizeof(int));
    int *timestamps = malloc(numFrames * sizeof(int));
    int pageFaults = 0, time = 0;

    for (int i = 0; i < numFrames; i++) frames[i] = -1;

    for (int i = 0; i < numPages; i++) {
        int found = -1;
        for (int j = 0; j < numFrames; j++)
            if (frames[j] == pages[i]) { found = j; break; }

        int replaceIdx = (found == -1) ? findLRU(timestamps, numFrames) : found;
        if (found == -1) pageFaults++;

        frames[replaceIdx] = pages[i];
        timestamps[replaceIdx] = time++;

        printf("Step %d: ", i + 1);
        for (int j = 0; j < numFrames; j++)
            printf("%d ", frames[j] == -1 ? -1 : frames[j]);
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
    free(frames);
    free(timestamps);
}

int main() {
    int numPages, numFrames;
    printf("Enter number of pages and frames: ");
    scanf("%d %d", &numPages, &numFrames);

    int *pages = malloc(numPages * sizeof(int));
    printf("Enter page sequence: ");
    for (int i = 0; i < numPages; i++) scanf("%d", &pages[i]);

    lruPageReplacement(pages, numPages, numFrames);
    free(pages);
    return 0;
}
