#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    double a=0, b=0, c=0, d=0;
    int n, total;

 //estrutura de repetição
    do
    {
     //pede um numero entre o intervalo de 1 a 100
        puts("digite um numero de 1 a 100");
        scanf("%d", &n);

     //verifica se o numero esta entre o intervalo pedido
        if ( n<=100 && n>=0 )
        {
            //verifica a que grupo pertence o numero digitado
            if ( n>=1 && n<=25 )
            {
                a++;
            }//end if
            if ( n>=26 && n<=50 )
            {
                b++;
            }//end if
            if ( n>=51 && n<=75 )
            {
                c++;
            }//end if
            if ( n>=76 && n<=100 )
            {
                d++;
            }//end if
        }//end if
        else
        {
            puts("\nnumero invalido\n");
        }//end else
        
    } while ( n!=0 );//end do while
    
 //calcula o total de numeros digitados 
    total=a+b+c+d;
 
 //verifica se algum numero valido foi digitado
    if ( a==0 && b==0 && c==0 && d==0 )
    {
        puts("porcentagem de valores lidos entre os intervalos a, b, c, d= 0.00, 0.00, 0.00, 0.00");
    }//end if
    else
    {
     //calcula a porcentagem de numero de cada grupo
        a=a/total*100;
        b=b/total*100;
        c=c/total*100;
        d=d/total*100;

      //imprimir o resultado da porcentagem de valores lidos entre os intervalos [1..25], [26..50], [51..75] e [76..100]
        printf("porcentagem de valores lidos entre os intervalos a, b, c, d= %.2lf, %.2lf, %.2lf, %.2lf",a, b, c, d);
    }//end else
    
    return 0;
}