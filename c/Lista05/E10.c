#include <stdio.h>

//função para calcular os numeros do triangulo de pascal
int calcularCoeficienteBinomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }//end if
    else {
        return calcularCoeficienteBinomial(n - 1, k - 1) + calcularCoeficienteBinomial(n - 1, k);
    }//end else
}//end calcularCoeficienteBinomial


//função para imprimir o triangulo de pascal
void imprimirTrianguloPascal(int n) {
    for (int linha = 0; linha < n; linha++) {
        for (int espaco = 0; espaco < n - linha; espaco++) {
            printf("  "); // Espaços para alinhar os números
        }//end for
        for (int coluna = 0; coluna <= linha; coluna++) {
            printf("%4d  ", calcularCoeficienteBinomial(linha, coluna));
        }//end for
        printf("\n");
    }//end for
}//end imprimirTrianguloPascal


int main() {
 //teste imprimirTrianguloPascal
    imprimirTrianguloPascal(5);
    return 0;
}
