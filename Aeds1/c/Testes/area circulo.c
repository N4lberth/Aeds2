#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
    double R, Area;

    printf("Valor do raio da circuferencia: ");
    scanf("%lf", &R);


    Area=pow(R, 2)*PI;

    printf("AREA= %lf", Area);
    return 0;
}