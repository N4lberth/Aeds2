#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    double media;
    int soma, quant=0, n;

 //estrutura de repetição
    do
    {
        puts("digite um numero inteiro");
        scanf("%d", &n);
        
     //somar os numeros digitados 
        soma=soma+n;
     
     //contar quantos numeros foram digitados ( excluindo o 0 )
        if( n !=0 )
        {
            quant++;
        }//end if

    } while ( n != 0 ); //end do while

 //tirando a media dos numeros
    media=soma*1.0/quant;

 //imprimir o resultado
    printf("resuldado da meida dos numeros digitados eh = %.2lf",media);

    return 0;
}