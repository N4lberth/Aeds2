#include <stdio.h>

int main (void){

 //inicialização da variavel 
    float num1, num2, num3; 

 //pede tres numeros para serem digitados
    puts("digite tres numeros reais"); 
    scanf("%f %f %f", &num1 ,&num2, &num3);

 //verifica se é possivel formar um triangulo
    if( num1 + num2 > num3 && num1 + num2 > num3 && num2 + num3 > num1)
    {
        puts("eh possivel formar um triangulo");
        if( num1 == num2 && num1 == num3)
        {
            puts("\ntriangulo equilatero\n");
            puts("3 angulos agudos");
        }//end if
        else if( num1 == num2 || num1 == num3 || num2 == num3 )
        {
            puts("\ntriangulo isosceles\n");
            puts("pode ter 1 obtuso e 2 angulos agudos, 1 angulo reto e 2 angulos agudos ou 3 angulos agudos");
        }//end else if
        else
        {
            puts("\ntriangulo escaleno\n");
            puts("3 angulos diferentes podendo ser reto, agudo e obtuso");
        }//end else
    }//end if

    else 
        puts("nao eh possivel formar um triangulo");
    //end else

    return 0;
}