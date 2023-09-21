#include <stdio.h>
#include <math.h>

int main(void)
{

 // inicialização de variavel
    double b;
    int n;

 //definir o numero de repetições
    puts("digite o numero de repeticoes:");
    scanf("%d", &n);

 //estrutura de repetição
    for( int i=0; i<=n; i++ )
    {
        b = b + ( 1.0 / pow( 2, i ));
    }//end for

 //imprimir o resultado
    printf("resuldado do somatorio = %lf",b);

    return 0;
}