#include <stdio.h>

int main (void){

 //inicialização da variavel 
    double salario, IPRF, INSS; 

 //pede um numero para ser digitado
    puts("digite o salario"); 
    scanf("%lf", &salario);

 //calculo IPRF
    if( salario <= 2112.00 )
    {
        puts("isento");
    }//end if
    else if( salario <= 2826.65)
    {
        IPRF = salario*0.075;
        printf("O IPRF eh = R$%lf\n", IPRF);
    }//enf else if
    else if( salario <= 3751.05)
    {
        IPRF = salario*0.15;
        printf("O IPRF eh = R$%lf\n", IPRF);
    }//enf else if
    else if( salario <= 4664.68)
    {
        IPRF = salario*0.225;
        printf("O IPRF eh = R$%lf\n", IPRF);
    }//enf else if
    else
    {
        IPRF = salario*0.275;
        printf("O IPRF eh = R$%lf\n", IPRF);
    }//end else
    
 //calculo do INSS
    if( salario <= 1320.00 )
    {
        INSS = salario*0.075;
        printf("O INSS eh = R$%lf\n", INSS);
    }//end if
    else if( salario <= 2571.29)
    {
        INSS = salario*0.09;
        printf("O INSS eh = R$%lf\n", INSS);
    }//enf else if
    else if( salario <= 3856.94)
    {
        INSS = salario*0.12;
        printf("O INSS eh = R$%lf\n", INSS);
    }//enf else if
    else if( salario <= 7507.49)
    {
        INSS = salario*0.14;
        printf("O INSS eh = R$%lf\n", INSS);
    }//enf else if
    else
    {
        INSS = 7507.49*0.14;
        printf("O INSS eh = R$%lf\n", INSS);
    }//end else

    return 0;
}