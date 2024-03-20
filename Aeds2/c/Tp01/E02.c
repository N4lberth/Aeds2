#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char *str) {
    int length = strlen(str);
    int i = 0, j = length - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }

        i++;
        j--;
    }
    return true;
}

int main() {
    char str[1000];

    while (1) {
        fgets(str, sizeof(str), stdin);

        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "FIM") == 0) {
            break;
        }

        if (isPalindrome(str)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
