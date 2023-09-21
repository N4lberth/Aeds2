#include <stdio.h>

//função para calcular o máximo divisor comum (MDC) usando o algoritmo de Euclides
int calcularMDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }//end while
    return a;
}//end calcularMDC

//função para calcular o mínimo múltiplo comum (MMC)
int calcularMMC(int a, int b) {
    int mdc = calcularMDC(a, b);
 //MMC = (a * b) / MDC
    return (a * b) / mdc;
}//end calcularMMC

int main(void)
{

 // inicialização de variavel
    int num1, num2, mdc;

 //ler dois números inteiros
    puts("digite 2 numeros inteiros:");
    scanf("%d %d", &num1, &num2);

 //chamar função mmc
    mdc = calcularMDC(num1, num2);
    
 //imprimir o resultado
    printf("O maximo divisor comum de %d e %d eh: %d\n", num1, num2, mdc);

    return 0;
}