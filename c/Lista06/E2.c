#include <stdio.h>

//struct data guarda uma data(ano, mes, dia)
typedef struct data
{
    int ano, mes, dia;
}data;//end data

//função diaDeHoje recebe a data de um dia
data diaDeHoje(data x)
{
    printf("digite o ano: ");
    scanf("%d", &x.ano);

 //validando o ano
    if(x.ano <=0 ){
        printf("ano invalido\n");
        x.ano=0;
    }//end if


    printf("digite o mes: ");
    scanf("%d", &x.mes);    

 //validando o mes
    if(x.mes < 1 || x.mes > 12){
        printf("mes invalido\n");
        x.mes=0;
    }//end if


    printf("digite o dia: ");
    scanf("%d", &x.dia);    

 //validando o dia
    if(x.mes==1 || x.mes==3 || x.mes==5 || x.mes==7 || x.mes==8 || x.mes==10 || x.mes==12){
        if(x.dia < 1 || x.dia > 31){
            printf("dia invalido\n");
            x.dia=0;
        }//end if
    }//end if

    else if(x.mes==4 || x.mes==6 || x.mes==9 || x.mes==11){
        if(x.dia < 1 || x.dia > 30){
            printf("dia invalido\n");
            x.dia=0;
        }//end if
    }//end else if

    else{
        if(x.ano%400==0 || (x.ano%4==0 && x.ano%100!=0)){
            if(x.dia < 1 || x.dia > 29){
                printf("dia invalido\n");
                x.dia=0;
            }//end if
        }//end if
        else if(x.dia < 1 || x.dia > 28){
            printf("dia invalido\n");
            x.dia=0;
        }//end else if
    }//end else

    return x;
}//end diaDeHoje


//test da função
int main(void){

    data D1;

    D1 = diaDeHoje(D1);

    printf("%d/%d/%d",D1.dia, D1.mes, D1.ano);
    return 0;
}