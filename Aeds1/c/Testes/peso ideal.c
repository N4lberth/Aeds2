#include <stdio.h>
#include <stdlib.h>

int main()
{
    char genero;
    float peso, altura, IMC;

    printf("Escolha o genero (homem - h /mulher - m)\n");
    scanf("%s", &genero);

    if (genero == 'h') {

        printf("coloque sua altura em Metros: ");
        scanf("%f", &altura);
        printf("coloque seu peso em Kilos: ");
        scanf("%f", &peso);

        IMC=peso/(altura*altura);
        printf("seu IMC=%f", IMC);
        if (18< IMC && IMC <24) {
            printf("\nseu peso eh ideal");
        } else {
            printf("\nseu peso nao eh ideal");
        }
    }
    if (genero == 'm') {
        printf("coloque sua altura em Metros: ");
        scanf("%f", &altura);
        printf("coloque seu peso em Kilos: ");
        scanf("%f", &peso);

        IMC=peso/(altura*altura);
        printf("seu IMC=%f", IMC);
        if (IMC > 18.5 && IMC < 24.9) {
            printf("\nseu peso eh ideal");
        } else {
            printf("\nseu peso nao eh ideal");
        }
    }

    return 0;
}