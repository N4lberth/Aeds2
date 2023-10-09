#include <stdio.h>

int main(void)
{
    int v[10];

    for(int i=0; i<10; i++){
        printf("digite o %d numero ", i);
        scanf("%d", &v[i]);
    }
    
    for(int i=0; i<10; i++){
        printf("%d, ", v[i]);
    }

    return 0;
}   