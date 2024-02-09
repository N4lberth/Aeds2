#include <stdio.h>
#include <math.h>

int main(void)
{
    float B, H, volume, area, L;

    printf("Digite o valor da area da base: ");
    scanf("%f", &B);

    printf("Digite o valor da altura: ");
    scanf("%f", &H);
    
 //calculo do lado do quadrado
    L=sqrt(B);
 //calculo da area superficial = (area da base + area lateral) 
 //area lateral = (altura do triangulo * 2*lado)
 //altura do triangulo = (raiz de ( (lado/2)² + (altura)² ) )
    area = B + (2*L * sqrt(pow(H, 2)+pow(L/2, 2)));
 //calculo do volume
    volume=(B*H)/3;

    printf("\nArea superficial da piramide: %f", area);
    printf("\nVolume da piramide: %f", volume);
    return 0;
}