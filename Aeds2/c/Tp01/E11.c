#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindromeRec(char *str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindromeRec(str, start + 1, end - 1);
}

bool isPalindrome(char *str) {
    int length = strlen(str);
    return isPalindromeRec(str, 0, length - 1);
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


