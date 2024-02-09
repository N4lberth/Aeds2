#include <stdio.h>

int main (void){

 //inicialização da variavel 
    int idade; 

 //pede a idade
    puts("digite sua idade");
    scanf("%d", &idade);

 //testa os casos dos eleitores
    if( idade >= 64 || idade == 16 || idade == 17  )
        puts("eleitor facultativo (nao obrigatorio)");
    //end if
    else if( idade >= 18 && idade < 64 )
        puts("eleitor obrigatorio");
    //end else if
    else
        puts("nao eleitor");
    //end else

    return 0;
}