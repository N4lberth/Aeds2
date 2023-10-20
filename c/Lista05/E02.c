#include <stdio.h>

//função para imprimir sequencia de Fibonacci com n numeros
void fibonacci(int n)
{
 //variavel temp 1 e 2
    int temp1=0, temp2=1;

    for( int i=1; i<=n; i++ )
    {
    
     //imprimir o numero
        printf("%d ",temp1);

     //variavel temporaria 3
        int temp3=temp2;

     //manipulação das variaveis
        temp2=temp1;
        temp1=temp3; 

     //calculo do proximo numero da sequencia   
        temp1=temp1+temp2;

    }//end for
}//end fibonacci


int main(void)
{
 //teste função fibonacci
    fibonacci(8);

    return 0;
}