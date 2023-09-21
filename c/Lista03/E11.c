#include <stdio.h>
#include <math.h>

int main(void)
{

 // inicialização de variavel
    double x=0.0, total=0.0;
    int n=0;

 //definir o numero de repetições
    puts("digite o numero de repeticoes:");
    scanf("%d", &n);

 //definir o numero para x
    puts("\ndigite o numero para ln(x):");
    scanf("%lf", &x);

 //estrutura de repetição
    for( int i=1; i<=n; i++ )
    {
        total += (pow((-1), i) * pow((-1+x), i))/i;
    }//end for

 //inverter o sinal
    total=total * (-1);

 //imprimir o resultado
    printf("\nresultado do ln(%.0lf)= %lf",x, total);

    return 0;
}