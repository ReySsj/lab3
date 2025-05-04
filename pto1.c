#include <stdio.h>

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    int matriz[n][n];

    printf("Ingrese los elementos de la matriz (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int suma_diagonales = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x == y || x + y == n - 1) {
                suma_diagonales += matriz[x][y];
            }
        }
    }

   
    if (n % 2 == 1) {
        suma_diagonales -= matriz[n / 2][n / 2];
    }

    printf("La suma de las diagonales es: %d\n", suma_diagonales);

    return 0;
}
