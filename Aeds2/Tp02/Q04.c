#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>  

typedef struct s_Personagem
{
char*   id              ; 
char*   name            ; 
char*   alternateNames  ;
char*   house           ; 
char*   ancestry        ; 
char*   species         ; 
char*   patronus        ; 
bool    hogwartsStaff   ;  
bool    hogwartsStudent ;  
char*   actorName       ; 
bool    alive           ;
char*   alternateActors ; 
char*    dateOfBirth    ; 
int     yearOfBirth     ; 
char*   eyeColour       ; 
char*   gender          ; 
char*   hairColour      ; 
bool    wizard          ; 
} Personagem;

// Construtor
void newPersonagem(Personagem *personagem, const char *id, const char *name, const char *alternateNames,
                   const char *house, const char *ancestry, const char *species, const char *patronus,
                   bool hogwartsStaff, bool hogwartsStudent, const char *actorName, bool alive,
                   const char *alternateActors, const char *dateOfBirth, int yearOfBirth,
                   const char *eyeColour, const char *gender, const char *hairColour, bool wizard) {
    if (personagem != NULL) {
        personagem->id = strdup(id);
        personagem->name = strdup(name);
        personagem->alternateNames = strdup(alternateNames);
        personagem->house = strdup(house);
        personagem->ancestry = strdup(ancestry);
        personagem->species = strdup(species);
        
        // Alocar e copiar a string do patronus
        if (strcmp(patronus, "null") == 0) {
            personagem->patronus = strdup("");
        } else {
            personagem->patronus = strdup(patronus);
        }
        
        personagem->hogwartsStaff = hogwartsStaff;
        personagem->hogwartsStudent = hogwartsStudent;
        
        // Alocar e copiar a string do nome do ator
        if (strcmp(actorName, "null") == 0) {
            personagem->actorName = strdup("");
        } else {
            personagem->actorName = strdup(actorName);
        }
        
        personagem->alive = alive;
        personagem->alternateActors = strdup(alternateActors);
        personagem->dateOfBirth = strdup(dateOfBirth);
        personagem->yearOfBirth = yearOfBirth;
        personagem->eyeColour = strdup(eyeColour);
        personagem->gender = strdup(gender);
        personagem->hairColour = strdup(hairColour);
        personagem->wizard = wizard;
    }
}

//set

void setPersonagemId(Personagem *p, const char *id) {
    if (p->id != NULL) free(p->id);
    p->id = strdup(id);
}

void setPersonagemName(Personagem *p, const char *name) {
    if (p->name != NULL) free(p->name);
    p->name = strdup(name);
}

void setPersonagemAlternateNames(Personagem *p, const char *alternateNames) {
    if (p->alternateNames != NULL) free(p->alternateNames);
    p->alternateNames = strdup(alternateNames);
}

void setPersonagemHouse(Personagem *p, const char *house) {
    if (p->house != NULL) free(p->house);
    p->house = strdup(house);
}

void setPersonagemAncestry(Personagem *p, const char *ancestry) {
    if (p->ancestry != NULL) free(p->ancestry);
    p->ancestry = strdup(ancestry);
}

void setPersonagemSpecies(Personagem *p, const char *species) {
    if (p->species != NULL) free(p->species);
    p->species = strdup(species);
}

void setPersonagemPatronus(Personagem *p, const char *patronus) {
    if (p->patronus != NULL) free(p->patronus);
    p->patronus = strdup(patronus);
}

void setPersonagemHogwartsStaff(Personagem *p, bool hogwartsStaff) {
    p->hogwartsStaff = hogwartsStaff;
}

void setPersonagemHogwartsStudent(Personagem *p, bool hogwartsStudent) {
    p->hogwartsStudent = hogwartsStudent;
}

void setPersonagemActorName(Personagem *p, const char *actorName) {
    if (p->actorName != NULL) free(p->actorName);
    p->actorName = strdup(actorName);
}

void setPersonagemAlive(Personagem *p, bool alive) {
    p->alive = alive;
}

void setPersonagemAlternateActors(Personagem *p, const char *alternateActors) {
    if (p->alternateActors != NULL) free(p->alternateActors);
    p->alternateActors = strdup(alternateActors);
}

void setPersonagemDateOfBirth(Personagem *p, const char *dateOfBirth) {
    if (p->dateOfBirth != NULL) free(p->dateOfBirth);
    p->dateOfBirth = strdup(dateOfBirth);
}

void setPersonagemYearOfBirth(Personagem *p, int yearOfBirth) {
    p->yearOfBirth = yearOfBirth;
}

void setPersonagemEyeColour(Personagem *p, const char *eyeColour) {
    if (p->eyeColour != NULL) free(p->eyeColour);
    p->eyeColour = strdup(eyeColour);
}

void setPersonagemGender(Personagem *p, const char *gender) {
    if (p->gender != NULL) free(p->gender);
    p->gender = strdup(gender);
}

void setPersonagemHairColour(Personagem *p, const char *hairColour) {
    if (p->hairColour != NULL) free(p->hairColour);
    p->hairColour = strdup(hairColour);
}

void setPersonagemWizard(Personagem *p, bool wizard) {
    p->wizard = wizard;
}

// get

const char* getPersonagemId(const Personagem *p) {
    return p->id;
}

const char* getPersonagemName(const Personagem *p) {
    return p->name;
}

const char* getPersonagemAlternateNames(const Personagem *p) {
    return p->alternateNames;
}

const char* getPersonagemHouse(const Personagem *p) {
    return p->house;
}

const char* getPersonagemAncestry(const Personagem *p) {
    return p->ancestry;
}

const char* getPersonagemSpecies(const Personagem *p) {
    return p->species;
}

const char* getPersonagemPatronus(const Personagem *p) {
    return p->patronus;
}

bool getPersonagemHogwartsStaff(const Personagem *p) {
    return p->hogwartsStaff;
}

bool getPersonagemHogwartsStudent(const Personagem *p) {
    return p->hogwartsStudent;
}

const char* getPersonagemActorName(const Personagem *p) {
    return p->actorName;
}

bool getPersonagemAlive(const Personagem *p) {
    return p->alive;
}

const char* getPersonagemAlternateActors(const Personagem *p) {
    return p->alternateActors;
}

const char* getPersonagemDateOfBirth(const Personagem *p) {
    return p->dateOfBirth;
}

int getPersonagemYearOfBirth(const Personagem *p) {
    return p->yearOfBirth;
}

const char* getPersonagemEyeColour(const Personagem *p) {
    return p->eyeColour;
}

const char* getPersonagemGender(const Personagem *p) {
    return p->gender;
}

const char* getPersonagemHairColour(const Personagem *p) {
    return p->hairColour;
}

bool getPersonagemWizard(const Personagem *p) {
    return p->wizard;
}

//imprimir personagem

void imprimir ( Personagem* personagem ){
    if (personagem->dateOfBirth && strlen(personagem->dateOfBirth) < 10) {
        char *aux = calloc(11, sizeof(char));  
        int dia, mes, ano;
        
        if (sscanf(personagem->dateOfBirth, "%d-%d-%d", &dia, &mes, &ano) == 3) {
            sprintf(aux, "%02d-%02d-%d", dia, mes, ano);  
            free(personagem->dateOfBirth);  // libera a memória antiga
            personagem->dateOfBirth = aux;  
        } else {
            free(aux);  // libera aux se não for usada
        }
    }
    printf( "[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",personagem->id,personagem->name,personagem->alternateNames,personagem->house,personagem->ancestry,personagem->species,personagem->patronus,personagem->hogwartsStaff ? "true" : "false",personagem->hogwartsStudent ? "true" : "false",personagem->actorName,personagem->alive ? "true" : "false",personagem->dateOfBirth,personagem->yearOfBirth,personagem->eyeColour,personagem->gender,personagem->hairColour,personagem->wizard ? "true" : "false" ); 
}

// Função para verificar e padronizar a data para o formato "DD-MM-AAAA"
bool checarData(char *data) {
    // Verificar se a data tem o formato "DD/MM/AAAA"
    if (strlen(data) != 10) {
        return false;
    }
    
    // Verificar se os separadores são válidos
    if (data[2] != '-' || data[5] != '-') {
        return false;
    }
    
    // Verificar se os caracteres restantes são dígitos
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) {
            return false;
        }
    }
    
    // Se a data estiver no formato correto, não há necessidade de padronização
    if (data[2] == '-' && data[5] == '-') {
        return true;
    }
    
    // Padronizar a data para o formato "DD-MM-AAAA"
    char padronizada[11];
    strncpy(padronizada, &data[6], 4);  // Copiar o ano
    padronizada[4] = '-';
    strncpy(&padronizada[5], &data[3], 2);  // Copiar o mês
    padronizada[7] = '-';
    strncpy(&padronizada[8], data, 2);  // Copiar o dia
    padronizada[10] = '\0';
    
    // Atualizar a string de data original
    strcpy(data, padronizada);
    
    return true;
}

// Função para ler um Personagem do arquivo
Personagem* lerPersonagem(const char *filename, const char *id_procurado) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    char line[500];
    fgets(line, sizeof(line), file); // Ignorar a linha de cabeçalho

    while (fgets(line, sizeof(line), file) != NULL) {
        char *atributos[18];
        int index = 0;

        char *token = strtok(line, ";");
        while (token != NULL) {
            atributos[index++] = strdup(token);
            token = strtok(NULL, ";");
        }

        // Verificar se o ID corresponde ao procurado
        if (strcmp(atributos[0], id_procurado) == 0) {
            Personagem *personagem = (Personagem*)malloc(sizeof(Personagem));
            personagem->id = strdup(atributos[0]);
            personagem->name = strdup(atributos[1]);
            personagem->alternateNames = strdup(atributos[2]);
            personagem->house = strdup(atributos[3]);
            personagem->ancestry = strdup(atributos[4]);
            personagem->species = strdup(atributos[5]);
            personagem->patronus = strdup(strcmp(atributos[6], "null") == 0 ? "" : atributos[6]);
            personagem->hogwartsStaff = strcmp(atributos[7], "true") == 0;
            personagem->hogwartsStudent = strcmp(atributos[8], "true") == 0;
            personagem->actorName = strdup(atributos[9]);
            personagem->alive = strcmp(atributos[10], "true") == 0;
            personagem->alternateActors = strdup(atributos[11]);
            personagem->dateOfBirth = strdup(atributos[12]);
            personagem->yearOfBirth = atoi(atributos[13]);
            personagem->eyeColour = strdup(atributos[14]);
            personagem->gender = strdup(atributos[15]);
            personagem->hairColour = strdup(atributos[16]);
            personagem->wizard = strcmp(atributos[17], "true") == 0;

            // Liberar memória alocada para atributos temporários
            for (int i = 0; i < index; i++) {
                free(atributos[i]);
            }

            fclose(file);
            return personagem;
        }

        // Liberar memória alocada para atributos temporários
        for (int i = 0; i < index; i++) {
            free(atributos[i]);
        }
    }

    fclose(file);
    printf("Personagem com o ID '%s' não encontrado.\n", id_procurado);
    return NULL;
}

// Função para ordenação por seleção
void ordenacaoSelecao(Personagem *personagem, int tamanho) {
    int n = tamanho;
    for (int i = 0; i < (n - 1); i++) {
        int menor = i;
        for (int j = (i + 1); j < n; j++) {
            if (strcmp(personagem[menor].name, personagem[j].name) > 0) {
                menor = j;
            }
        }
        Personagem temp = personagem[i];
        personagem[i] = personagem[menor];
        personagem[menor] = temp;
    }
}

// Função para liberar a memória alocada para um Personagem
void liberarMemoriaPersonagem(Personagem *p) {
    if (p != NULL) {
        free(p->id);
        free(p->name);
        free(p->alternateNames);
        free(p->house);
        free(p->ancestry);
        free(p->species);
        free(p->patronus);
        free(p->actorName);
        free(p->alternateActors);
        free(p->dateOfBirth);
        free(p->eyeColour);
        free(p->gender);
        free(p->hairColour);
        free(p);
    }
}

int main(){
    //alocando local de memoria para o personagem
    setlocale(LC_CTYPE, "UTF-8"); 

    Personagem* personagem = (Personagem*) malloc (50 * sizeof(Personagem));
    char* path = "/tmp/characters.csv"; 
    char id[81];

    //ler id novo
    scanf("%s",id ); 

    //limpar buffer
    getchar( );

    int n = 0;

    //variavel temporaria para guardar o valor de perssonagem
    Personagem* tmp = (Personagem*) malloc (sizeof(Personagem));

    while( strcmp( id,"FIM" ) != 0 ){
        // Ler o personagem e aumentar o contador
        tmp = lerPersonagem("/tmp/characters.csv", id);
        personagem[n] = *tmp;
        n++;

        //Ler o próximo id e limpar o buffer
        scanf( "%s", id ); 
        getchar( );
    } 

    //liberar memoria tmp
    free(tmp);

    //ordena o vetor personagem[n]
    ordenacaoSelecao(personagem, n);

    //variavel para guardar o nome
    char nome[100];

    //ler o nome e limpar o buffer
    fgets(nome, sizeof(nome), stdin);
    getchar( );
     while (strcmp(nome, "FIM\n") != 0) { // Corrigido para verificar "FIM\n"
        // Pesquisa binária
        int inicio = 0, fim = n - 1;
        bool encontrado = false; // Flag para indicar se o nome foi encontrado

        while (inicio <= fim) {
            int meio = (inicio + fim) / 2;
            int found = strcmp(nome, personagem[meio].name);

            if (found == 0) {
                encontrado = true;
                printf("\nSIM");
                break;
            } else if (found < 0) {
                fim = meio - 1;
            } else {
                inicio = meio + 1; // Corrigido para +1
            }
        }

        if (!encontrado) { // Se o nome não foi encontrado
            printf("\nNAO");
        }

        // Ler o próximo nome e limpar o buffer
        fgets(nome, sizeof(nome), stdin);
        getchar();
    }

    // Liberar memória alocada para cada personagem
    for (int i = 0; i < n; i++) {
        liberarMemoriaPersonagem(&personagem[i]);
    }

    free(personagem);
    personagem = NULL;

    return 0;
}