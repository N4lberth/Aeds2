#include <stdio.h>

int main() {
    int linA, linB, colA, colB;

 // Ler as dimensões da matriz A
    printf("Digite o numero de linhas e colunas da matriz A: ");
    scanf("%d %d", &linA, &colA);

 // Ler as dimensões da matriz B
    printf("Digite o numero de linhas e colunas da matriz B: ");
    scanf("%d %d", &linB, &colB);

    if (colA != linB) {
        printf("As matrizes nao podem ser multiplicadas. O numero de colunas de A deve ser igual ao numero de linhas de B.\n");
    }//end if
    else
    {

     // Ler os elementos da matriz A
        int A[linA][colA];
        printf("Digite os elementos da matriz A:\n");
        for (int i = 0; i < linA; i++) {
            for (int j = 0; j < colA; j++) {
                scanf("%d", &A[i][j]);
            }//end for
        }//end for

     // Ler os elementos da matriz B
        int B[linB][colB];
        printf("Digite os elementos da matriz B:\n");
        for (int k = 0; k < linB; k++) {
            for (int l = 0; l < colB; l++) {
                scanf("%d", &B[k][l]);
            }//end for
        }//end for

     // Realizar a multiplicação das matrizes
        int result[linA][colB];
        for (int i = 0; i < linA; i++) {
            for (int l = 0; l < colB; l++) {
                result[i][l] = 0;
                for (int j = 0; j < colA; j++) {
                    result[i][l] += A[i][j] * B[j][l];
                }//end for
            }//end for
        }//end for

     // Imprimir o resultado
        printf("Resultado da multiplicacao:\n");
        for (int i = 0; i < linA; i++) {
            for (int l = 0; l < colB; l++) {
                printf("%d ", result[i][l]);
            }//end for
            printf("\n");
        }//end for
    }//end else

    return 0;
}
