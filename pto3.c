#include <stdio.h>
#include <stdlib.h> // Para rand y srand
#include <time.h>   // Para usar time como semilla aleatoria

int findLargestLine(int n, int matrix[n][n]) {
    int conteos[2 * n];
    int contador = 0;
    int temp = 0;

    // diagonal principal
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 1) {
            temp++;
        } else {
            conteos[contador++] = temp;
            temp = 0;
        }
    }
    conteos[contador++] = temp;
    temp = 0;

    // diagonal secundaria
    for (int i = 0; i < n; i++) {
        int j = n - 1 - i;
        if (matrix[i][j] == 1) {
            temp++;
        } else {
            conteos[contador++] = temp;
            temp = 0;
        }
    }
    conteos[contador++] = temp;

    // buscar el máximo
    int max = conteos[0];
    for (int i = 1; i < contador; i++) {
        if (conteos[i] > max) {
            max = conteos[i];
        }
    }

    return max;
}

int main() {
    int n = 6;
    int matrix[n][n];

    // Semilla para obtener distintas matrices en cada ejecución
    srand(time(NULL));

    // Llenar matriz con 0s y 1s aleatorios
    printf("La matriz utilizada corresponde a:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2; // Solo 0 o 1
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int largestLine = findLargestLine(n, matrix);
    printf("El tamano de la secuencia en diagonal de 1s mas grande es: %d.\n", largestLine);

    return 0;
}
