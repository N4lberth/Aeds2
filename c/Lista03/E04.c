#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    int n, num=0, num2=1;

 //definir o numero de termos da sequência
    puts("digite o numero de termos da sequencia:");
    scanf("%d", &n);
    printf("Sequencia de Fibonacci com %d numeros:\n", n);

 //estrutura de repetição
    for( int i=1; i<=n; i++ )
    {
    
     //imprimir o numero
        printf("%d ",num);

     //variavel temporaria
        int temp=num2;

     //manipulação das variaveis
        num2=num;
        num=temp; 

     //calculo do proximo numero da sequencia   
        num=num+num2;

    }//end for

    return 0;
}