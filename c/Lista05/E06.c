#include <stdio.h>
#include <stdlib.h>

//função **multiplyMatrices multiplica duas matrizes e retorna o produto em uma terceira matriz alocada dinamicamente
int **multiplyMatrices(int **matrix1, int lin1, int cols1, int **matrix2, int lin2, int cols2) {
    if (cols1 != lin2) {
        // Verifica se o produto das matrizes é possível.
        return NULL;
    }//end if

    int **result = (int **)malloc(lin1 * sizeof(int *));
    for (int i = 0; i < lin1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }//end for

    for (int i = 0; i < lin1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }//end for
        }//end for
    }//end for

    return result;
}//end **multiplyMatrices

int main() {
    int lin1, cols1, lin2, cols2;

    printf("Digite o número de linhas e colunas da primeira matriz: ");
    scanf("%d %d", &lin1, &cols1);

    printf("Digite o número de linhas e colunas da segunda matriz: ");
    scanf("%d %d", &lin2, &cols2);

    if (cols1 != lin2) {
        printf("As matrizes não podem ser multiplicadas.\n");
        return 1;
    }//end if

    int **matrix1 = (int **)malloc(lin1 * sizeof(int *));
    for (int i = 0; i < lin1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }//end for

    int **matrix2 = (int **)malloc(lin2 * sizeof(int *));
    for (int i = 0; i < lin2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }//end for

    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < lin1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }//end for
    }//end for

    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < lin2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }//end for
    }//end for

    int **result = multiplyMatrices(matrix1, lin1, cols1, matrix2, lin2, cols2);

    if (result == NULL) {
        printf("Não é possível multiplicar as matrizes.\n");
    }//end if 
    else {
        printf("Resultado da multiplicação:\n");
        for (int i = 0; i < lin1; i++) {
            for (int j = 0; j < cols2; j++) {
                printf("%d ", result[i][j]);
            }//end for
            printf("\n");
        }//end for

     // Libera a memória alocada para o resultado.
        for (int i = 0; i < lin1; i++) {
            free(result[i]);
        }//end for
        free(result);
    }//end else

 // Libera a memória alocada para as matrizes de entrada.
    for (int i = 0; i < lin1; i++) {
        free(matrix1[i]);
    }//end for
    free(matrix1);

    for (int i = 0; i < lin2; i++) {
        free(matrix2[i]);
    }//end for
    free(matrix2);

    return 0;
}
