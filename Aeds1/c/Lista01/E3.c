#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(void)
{
    float cateto1, cateto2, area, perimetro, hipotenusa, angulo1r, angulo2, angulo1;

    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &cateto1);
    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &cateto2);

 //calculo hipotenuza
    hipotenusa=sqrt(pow(cateto1, 2)+pow(cateto2, 2));
 //calculo area
    area=cateto1*cateto2/2;
 //calculo perimetro
    perimetro=cateto1+cateto2+hipotenusa;
 //calculo angulo1 (em radianos)
    angulo1r=asin(cateto1/hipotenusa);
 //calculo angulo1 (em graus)
    angulo1=angulo1r*(180/PI);
 //calculo angulo2
    angulo2=180-angulo1-90;

    printf("\nValor da area: %f", area);
    printf("\nValor da hipotenuza: %f", hipotenusa);
    printf("\nValor do primetro: %f", perimetro);
    printf("\nValor do primeiro angulo: %f", angulo1);
    printf("\nValor do segundo angulo: %f", angulo2);
    return 0;
}
