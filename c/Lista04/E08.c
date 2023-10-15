#include <stdio.h>
#define MAX_SIZE 10


int main() {
    int n;

 // Ler a dimensão da matriz
    printf("Digite a dimensão da matriz quadrada (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("A dimensão da matriz deve estar entre 1 e %d.\n", MAX_SIZE);
        return 1;
    }//end if

    int matrix[MAX_SIZE][MAX_SIZE];

 // Ler os elementos da matriz e imprimir a diagonal principal
    printf("Digite os elementos da matriz %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

         // Imprimir a diagonal principal
            if (i == j) {
                printf("Diagonal Principal: %d\n", matrix[i][j]);
            }//end if
        }//end for
    }//end for

 // Calcular o determinante usando o método da expansão por cofatores
    int det = 0;
    int sign = 1;
    int cofactor[MAX_SIZE][MAX_SIZE];

    for (int k = 0; k < n; k++) {
     // Construir o cofator
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == k) {
                    continue;
                }//end if
                cofactor[subi][subj] = matrix[i][j];
                subj++;
            }//end for
            subi++;
        }//end for

     // Adicionar o termo atual ao determinante
        det += sign * matrix[0][k] * determinant(cofactor, n - 1);

     // Alternar o sinal para o próximo termo
        sign = -sign;
    }//end for

 // Imprimir o determinante
    printf("Determinante da matriz: %d\n", det);

    return 0;
}
