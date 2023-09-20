#include <stdio.h>

int main (void){

 //inicialização da variavel 
    float peso, altura, IMC; 

 //pede o peso e a altura
    printf("coloque sua altura em Metros: ");
    scanf("%f", &altura);
    printf("coloque seu peso em Kilos: ");
    scanf("%f", &peso);

 //verifica o IMC
    IMC=peso/(altura*altura);
    printf("seu IMC=%.2f\n", IMC);

 //testa as possibilidades de IMC
    if( IMC < 16 )
        puts("Hecticidade morbida");
    //end if
    else if( IMC <= 17)
        puts("Hecticidade grave");
    //end else if
    else if( IMC <= 18.5)
        puts("Abaixo do peso");
    //end else if
    else if( IMC <= 25)
        puts("Peso normal");
    //end else if
    else if( IMC <= 30)
        puts("Sobrepeso");
    //end else if
    else if( IMC <= 35)
        puts("Obesidade");
    //end else if
    else if( IMC <= 40)
        puts("Obesidade grave");
    //end else if
    else
        puts("Obesidade morbida");
    //end else

    return 0;
}