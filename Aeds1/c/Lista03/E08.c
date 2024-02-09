#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    int n, fatorial=1;

 //definir o fatorial ( !n )
    puts("digite o numero do fatorial ( !n ):");
    scanf("%d", &n);

 //estrutura de repetição
    for( int i=n; i>0; i-- )
    {
        fatorial=fatorial*i;
    }//end for

 //imprimir o resultado
    printf("resuldado do fatorial de !%d = %d",n, fatorial);

    return 0;
}