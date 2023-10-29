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


//função diferençaHora mostra a diferença entre dois horarios em segundos
int diferençaHora(Horario x, Horario y){

    Horario temp;
    int total=0;

    if(x.segundo<y.segundo){
        x.segundo+=60;
        x.minuto--;
    }//end if

    if(x.minuto<y.minuto){
        x.minuto+=60;
        x.hora--;
    }//end if

    temp.segundo=x.segundo-y.segundo;
    temp.minuto=x.minuto-y.minuto;
    temp.hora=x.hora-y.hora;

    total=(temp.hora*60*60)+(temp.minuto*60)+temp.segundo;

    return total;
}//end diferençaHora


//test da função
int main(void){

    Horario H1 ,H2;

    H1 = horarioDeAgora();
    printf("%d:%d:%d\n",H1.hora, H1.minuto, H1.segundo);

    H2 = horarioDeAgora();
    printf("%d:%d:%d\n",H2.hora, H2.minuto, H2.segundo);

    printf("\ndiferenca de segundo = %d\n",diferençaHora(H1, H2));

    return 0;
}