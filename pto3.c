#include <stdio.h>
#define SIZE 5

int findLargestLine(int matrix[][SIZE]) {
    int conteos[2 * SIZE];
    int contador = 0;
    int temp = 0;

    for (int i = 0; i < SIZE; i++) {
        if (matrix[i][i] == 1) {
            temp++;
        } else {
            conteos[contador++] = temp;
            temp = 0;
        }
    }
    conteos[contador++] = temp;
    temp = 0;

    for (int i = 0; i < SIZE; i++) {
        int j = SIZE - 1 - i;
        if (matrix[i][j] == 1) {
            temp++;
        } else {
            conteos[contador++] = temp;
            temp = 0;
        }
    }
    conteos[contador++] = temp;

    int max = conteos[0];
    for (int i = 1; i < contador; i++) {
        if (conteos[i] > max) {
            max = conteos[i];
        }
    }

    return max;
}

int main() {
    int matrix[SIZE][SIZE] = {
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1}
    };

    int largestLine = findLargestLine(matrix);
    printf("El tamano de la secuencia de 1s mas grande es: %d\n", largestLine);

    return 0;
}
