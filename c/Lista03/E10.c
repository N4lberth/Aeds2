#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    int n, primo=0;

 //definir o numero inteiro
    puts("digite um numero inteiro:");
    scanf("%d", &n);

 //estrutura de repetição
    for( int i=1; i<=n; i++ )
    {
     //testar se o numero é divisivel somente por 1 e ele mesmo
       if( n % i == 0 )
       {
            primo++;
       }//end if
    }//end for

 //imprimir se é primo ou não
    if ( primo == 2 )
    {
        printf("\n%d eh primo", n);
    }//end if
    else
    {
        printf("\n%d nao eh primo", n);
    }
    
    

    return 0;
}