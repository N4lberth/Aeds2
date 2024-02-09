#include <stdio.h>
#include <stdlib.h>

int main()
{
    float B, H, Area;

    printf("Valor da base: ");
    scanf("%f", &B);

    printf("Valor da altura: ");
    scanf("%f", &H);

    Area=(B*H)/2;

    printf("AREA= %f", Area);

    return 0;
}