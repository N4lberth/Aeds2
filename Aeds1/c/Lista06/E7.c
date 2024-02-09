#include <stdio.h>

typedef struct Horario
{
    int hora, minuto, segundo;
}Horario;//end Horario

//função horarioDeAgora vailida e recebe um horario
Horario horarioDeAgora(void){
    
    Horario x;

    printf("Digite a hora: ");
    scanf("%d", &x.hora);

    if (x.hora<0)
    {
        printf("hora invalida");
        x.hora=0;
    }//end if

    printf("Digite o minuto: ");
    scanf("%d", &x.minuto);

    if ( x.minuto<0 || x.minuto>60 )
    {
        printf("minuto invalida");
        x.minuto=0;
    }//end if

    printf("Digite a segundo: ");
    scanf("%d", &x.segundo);

    if (x.segundo<0 || x.segundo>60)
    {
        printf("segundo invalida");
        x.segundo=0;
    }//end if
    
    return x;
}//end horarioDeAgora


//função somaHorario
Horario somaHorario(Horario x, Horario y){

    Horario total;

    total.segundo = x.segundo + y.segundo;
    total.minuto = x.minuto + y.minuto;
    total.hora = x.hora + y.hora;

    if(total.segundo>60){
        total.segundo-=60;
        total.minuto++;
    }//end if

    if(total.minuto>60){
        total.minuto-=60;
        total.hora++;
    }//end if

    return total;
}//end somaHorario



//test da função
int main(void){

    Horario H1 ,H2, H3;

    H1 = horarioDeAgora();
    printf("%d:%d:%d\n",H1.hora, H1.minuto, H1.segundo);

    H2 = horarioDeAgora();
    printf("%d:%d:%d\n",H2.hora, H2.minuto, H2.segundo);

    H3 = somaHorario(H1, H2);
    printf("\ntotal = %d:%d:%d\n",H3.hora, H3.minuto, H3.segundo);

    return 0;
}