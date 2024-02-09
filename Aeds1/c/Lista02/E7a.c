#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main() {
    double num1, num2, num3, ang1, ang2, ang3;

 //Solicitar ao usuário que insira os valores de num1, num2 e num3
    printf("Digite o valor de num1: ");
    scanf("%lf", &num1);

    printf("Digite o valor de num2: ");
    scanf("%lf", &num2);

    printf("Digite o valor de num3: ");
    scanf("%lf", &num3);

 //Verificar se os valores formam um triângulo
    if (num1 + num2 > num3 && num1 + num3 > num2 && num2 + num3 > num1) {
     //Calcular os ângulos internos em radianos usando a Lei dos Cossenos
        ang1 = acos((num2*num2 + num3*num3 - num1*num1) / (2 * num2 * num3));
        ang2 = acos((num1*num1 + num3*num3 - num2*num2) / (2 * num1 * num3));
        ang3 = acos((num1*num1 + num2*num2 - num3*num3) / (2 * num1 * num2));

     //Converter os ângulos internos de radianos para graus
        ang1 = ang1 * 180.0 / PI;
        ang2 = ang2 * 180.0 / PI;
        ang3 = ang3 * 180.0 / PI;

     //Determinar o tipo de triângulo
        if (ang1 == 90.0 || ang2 == 90.0 || ang3 == 90.0) 
        {
            printf("Este é um triângulo retângulo.\n");
        }//end if
         else if (ang1 > 90.0 || ang2 > 90.0 || ang3 > 90.0) 
         {
            printf("Este é um triângulo obtuso.\n");
        }//end else if 
        else 
        {
            printf("Este é um triângulo agudo.\n");
        }//end else

        if (num1 == num2 && num2 == num3) 
        {
            printf("Este é um triângulo equilátero.\n");
        }//end if 
        else if (num1 == num2 || num2 == num3 || num1 == num3) 
        {
            printf("Este é um triângulo isósceles.\n");
        }//end else if
        else {
            printf("Este é um triângulo escaleno.\n");
        }//end else

        // Imprimir os ângulos internos
        printf("Ângulo ang1: %.2lf graus\n", ang1);
        printf("Ângulo ang2: %.2lf graus\n", ang2);
        printf("Ângulo ang3: %.2lf graus\n", ang3);
    }//end if 
    else 
    {
        printf("Estes valores não formam um triângulo.\n");
    }//end else

    return 0;
}
