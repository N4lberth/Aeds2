#include <stdio.h>

int main() {
    int n;

 // Ler o número de linhas do Triângulo de Pascal
    printf("Digite o numero de linhas do Triangulo de Pascal: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um numero natural positivo.\n");
        return 1;
    }//end if

 // Inicializar o Triângulo de Pascal como uma matriz bidimensional
    int pascal[n][n];

 // Preencher o Triângulo de Pascal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            }//end if
            else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }//end else
        }//end for
    }//end for

 // Imprimir o Triângulo de Pascal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("  "); // Espaços para alinhar os números
        }//end for
        for (int j = 0; j <= i; j++) {
            printf("%4d ", pascal[i][j]); // Ajuste a largura para alinhar os números
        }//end for
        printf("\n");
    }//end for

    return 0;
}
