#include <stdio.h>
#include <stdlib.h>

// Structure to represent a memory block
typedef struct {
    int size;
    int allocated; // 0 if free, 1 if allocated
} MemoryBlock;

// Function for First Fit allocation
void firstFit(MemoryBlock *blocks, int n, int *processes, int p) {
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < p; i++) {
        int allocated = 0;
        for (int j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i]) {
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                blocks[j].allocated = 1;
                blocks[j].size -= processes[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) printf("Process %d not allocated\n", i + 1);
    }
}

// Function for Best Fit allocation
void bestFit(MemoryBlock *blocks, int n, int *processes, int p) {
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < p; i++) {
        int bestIdx = -1;
        for (int j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i]) {
                if (bestIdx == -1 || blocks[j].size < blocks[bestIdx].size)
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            printf("Process %d allocated to Block %d\n", i + 1, bestIdx + 1);
            blocks[bestIdx].allocated = 1;
            blocks[bestIdx].size -= processes[i];
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

int main() {
    int n, p;
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    MemoryBlock *blocks = (MemoryBlock *)malloc(n * sizeof(MemoryBlock));

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &p);

    int *processes = (int *)malloc(p * sizeof(int));
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < p; i++) scanf("%d", &processes[i]);

    firstFit(blocks, n, processes, p);

    // Reset allocation status for Best Fit
    for (int i = 0; i < n; i++) blocks[i].allocated = 0;

    bestFit(blocks, n, processes, p);

    free(blocks);
    free(processes);
    return 0;
}