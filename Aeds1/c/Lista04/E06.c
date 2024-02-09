#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para remover espaços em branco e transformar uma string em minúsculas
void processaString(char *str) {
    int tamanho = strlen(str);
    int j = 0;
    for (int i = 0; i < tamanho; i++) {
        if (!isspace(str[i])) {
            str[j++] = tolower(str[i]);
        }//end if
    }//end for
    str[j] = '\0';
}//end processaString

// Função para verificar se uma string é um palíndromo
int ehPalindromo(const char *str) {
    int tamanho = strlen(str);
    for (int i = 0; i < tamanho / 2; i++) {
        if (str[i] != str[tamanho - i - 1]) {
            return 0; // Não é um palíndromo
        }//end if
    }//end for
    return 1; // É um palíndromo
}//end ehPalindromo

//função para encontrar os palíndromos da frase
void encontraPalindromos(const char *frase) {
    int tamanho = strlen(frase);
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 3; j <= tamanho; j++) {
            char subfrase[1000]; // Tamanho máximo da subfrase 
            strncpy(subfrase, frase + i, j - i);
            subfrase[j - i] = '\0';

            if (ehPalindromo(subfrase)) {
                printf("Palíndromo encontrado: %s\n", subfrase);
            }//end if
        }//end for
    }//end for
}//end encontraPalindromos

int main() {
    char frase[1000]; // Tamanho máximo da frase 

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

 //chama a função para processar a string
    processaString(frase);

 //chama a função para verificar se é um palíndromo e printa na tela
    if (ehPalindromo(frase)) {
        printf("A frase eh um palindromo.\n");
    }//end if
    else {
        printf("A frase nao eh um palindromo.\n");
    }//end else

 //cham a função para encontrar os palíndromos no meio da frase e printa na tela
    printf("Palindromos na frase (mais que 3 caracteres):\n");
    encontraPalindromos(frase);

    return 0;
}