#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

void fastTranspose(SparseMatrix sparseMatrix[], int size) {
    SparseMatrix transposeMatrix[size];
    int rowCounts[100] = {0};
    int startingPositions[100];

    for (int i = 0; i < size; i++) {
        rowCounts[sparseMatrix[i].col]++;
    }


    startingPositions[0] = 0;
    for (int i = 1; i < 100; i++) {
        startingPositions[i] = startingPositions[i - 1] + rowCounts[i - 1];
    }


    for (int i = 0; i < size; i++) {
        int rowIndex = sparseMatrix[i].col;
        int dest = startingPositions[rowIndex]++;
        transposeMatrix[dest].row = sparseMatrix[i].col;
        transposeMatrix[dest].col = sparseMatrix[i].row;
        transposeMatrix[dest].value = sparseMatrix[i].value;
    }


    for (int i = 0; i < size; i++) {
        printf("(%d, %d) %d\n", transposeMatrix[i].row, transposeMatrix[i].col, transposeMatrix[i].value);
    }
}

int main() {
    SparseMatrix sparseMatrix[] = {
        {0, 2, 3},
        {1, 1, 5},
        {1, 2, 7},

    };
    int size = sizeof(sparseMatrix) / sizeof(sparseMatrix[0]);
    fastTranspose(sparseMatrix, size);
    return 0;
}

