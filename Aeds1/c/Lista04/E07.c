#include <stdio.h>

// Função para verificar se um número é primo
int ehPrimo(int numero) {
    if (numero <= 1) {
        return 0;  // 0 e 1 não são primos
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;  // Não é primo
        }
    }
    return 1;  // É primo
}//end ehPrimo

int main() {
    int n;
    printf("Digite um numero natural n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um numero natural positivo.\n");
    }//end if
    else {
        int contador = 0;
        int numero = 2;  // Inicialmente, o primeiro número primo é 2

        printf("Os %d primeiros numeros primos sao:\n", n);

        while (contador < n) {
            if (ehPrimo(numero)) {
                printf("%d ", numero);
                contador++;
            }//end if
            numero++;
        }//end while
        printf("\n");
    }//end else

    return 0;
}