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


//test da função
int main(void){

    Horario H1;

    H1 = horarioDeAgora();

    printf("%d:%d:%d",H1.hora, H1.minuto, H1.segundo);
    return 0;
}