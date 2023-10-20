#include <stdio.h>

//função para calcular a sequencia de fibonacci
int fibonacci(int n)
{
    if (n <= 1) {
        return n;
    }//end if 
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }//end else
}//end fibonacci


//função para imprimir a sequencia de fibonacci
void imprimirFibonacci(int n)
{
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }//end if
        printf("%d", fibonacci(i));
    }//end for
    printf("\n");
}//end imprimirFibonacci

int main()
{
 //teste função imprimirFibonacci
    imprimirFibonacci(8);
    return 0;
}
