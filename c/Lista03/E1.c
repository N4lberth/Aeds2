#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    int a;

 //estrutura de repetição
    for( int i=0; i<=1000; i++ )
    {
        a=a+i;
    }//end for

 //imprimir o resultado
    printf("resuldado do somatorio = %d",a);

    return 0;
}