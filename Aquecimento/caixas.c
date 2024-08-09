#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001
#define MAX_P 1001

typedef struct {
    int id;
    int posicao;
} Caixa;

Caixa piles[MAX_P][MAX_N];
int n, p;

int main() {
    while (scanf("%d %d", &n, &p) == 2 && n!= 0 && p!= 0) {
        int removed = 0;
        for (int i = 0; i < p; i++) {
            int q;
            scanf("%d", &q);
            for (int j = 0; j < q; j++) {
                scanf("%d", &piles[i][j].id);
                piles[i][j].posicao = j;
            }
        }
        for (int i = 0; i < p; i++) {
            int found = 0;
            for (int j = piles[i][0].posicao; j >= 0; j--) {
                if (piles[i][j].id == 1) {
                    found = 1;
                    removed += j;
                    break;
                }
            }
            if (!found) removed++;
        }
        printf("%d\n", removed - 1); // subtract 1 because we don't need to remove box 1
    }
    return 0;
}