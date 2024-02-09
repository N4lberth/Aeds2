#include <stdio.h>

int main(void)
{

 // inicialização de variavel
    int meses;
    double imovel, entrada, parcela1, total, resto;

 //le o valor do imovel
    puts("digite o valor do imovel");
    scanf("%lf", &imovel);

 //verifica se o imovel tem o preço minimo necessario
    if( imovel >= 100000 )
    {
     //le o valor da entrada
        do
        {
            puts("\ndigite o valor da entrada");
            scanf("%lf", &entrada);

         //testa se o valor esta dentro do permitido
            if (entrada < 0.2*imovel || entrada > 0.75*imovel)
            {
                puts("\nvalor indisponivel para a entrada\n");
            }//end if
            
        }while(entrada < 0.2*imovel || entrada > 0.75*imovel);//end do while

     //le a quantidade de meses 
        do
        {
            puts("\ndigete a quantidade de meses a serem pagos");
            scanf("%d", &meses);
            
         //testa se os meses estao dentro do permitido
            if( meses < 60 || meses > 360 )
            {
                puts("\nqauntidade de meses indisponivel\n");
            }//end if

        } while ( meses < 60 || meses > 360 );//end while
        
     //total a pagar com o desconto das parcelas
        resto = imovel - entrada;
     
     //primeira parcela
        parcela1 = resto/meses;

     //imprime o valor da primeira parcela
        printf("\no valor da primeira parcela eh %.2lf\n", parcela1);
     //calculo das parcelas
        for(int i=1; i<=meses; i++)
        {
            total=total+parcela1;

         //calculo do juros anual
            if( i % 12==0 )
            {
                parcela1 = parcela1 + parcela1 * 0.1;
            }//end if
        }//end for
     
     //imprime o valor total das parcelas
        printf("\no valor total das parcelas eh %.2lf\n", total);
    
     //imprime o valor total que sera pago
        printf("\no valor total que sera pago %.2lf\n", total+entrada);

    }//end if
    else
    {
        puts("\no imovel nao tem o valor minimo necessario\n");
    }//end else
    
    return 0;
}