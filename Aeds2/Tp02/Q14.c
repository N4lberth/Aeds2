#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>  

int comparacoes = 0;
int movimentacoes = 0;

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

// construtor
void newPersonagem ( Personagem* personagem, char* id , char*  name, char* alternateNames, char* house,char* ancestry, char*  species, char* patronus,bool  hogwartsStaff,bool  hogwartsStudent, char* actorName, bool alive, char* alternateActors, char*  dateOfBirth, int yearOfBirth, char*eyeColour, char* gender , char* hairColour, bool wizard ){
    if(personagem != NULL){
    personagem->id = id;                             
    personagem->name = name;                         
    personagem->alternateNames = alternateNames;                 
    personagem->house = house;                           
    personagem->ancestry = ancestry;                     
    personagem->species = species;      
    if(strcmp(patronus,"null") == 0){
        personagem -> patronus = "";
    }else{
        personagem->patronus= patronus;     
    }                           
    personagem->hogwartsStaff= hogwartsStaff;                   
    personagem->hogwartsStudent= hogwartsStudent ;     
    if(strcmp(actorName,"null") == 0){ 
        personagem -> actorName = "";
    }else{
        personagem->actorName= actorName;  
    }                         
    personagem->alive= alive  ;                           
    personagem->alternateActors= alternateActors;               
    personagem->dateOfBirth  = dateOfBirth  ;                   
    personagem->yearOfBirth = yearOfBirth ;                   
    personagem->eyeColour = eyeColour;                       
    personagem->gender = gender ;                         
    personagem->hairColour  = hairColour ;                     
    personagem->wizard  = wizard ;                         
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
bool checardata(char data[]){
    bool edata = "false";
    char molde[] = {"00-0-0000"};
    int count = 0;
    for(int i = 0; i<strlen(molde);i++){
        if(data[i] == molde[i]){
            count++;
        }
    }
    if(count == 2){
        edata = "true";
    }
    return edata;
}

void padronizarData(char data[]) {
    int dia, mes, ano;
    for(int i = 0; i<strlen(data); i++){
        printf("%c", data[i]);
    }
    printf("\n");
}

//ler arquivo

Personagem ler(Personagem* personagem, char* filename, char* id_procurado) {
    //leitura do arquivo
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nERROR: File Not Found.\n");
    } else {
        char line[500];
        bool idFound = false;

        fgets(line, sizeof(line), file);
        int na = 0;
        while (fgets(line, sizeof(line), file) != NULL && !idFound) {
            char *atributos[18];
            char auxline[500] = {0};
            int col = 0;
            int t = 0;
            int k = 0;
            int index = 0;
            char *token = strtok(line, ";");
            int execvar = 0;
            na++;
            int debug= 0;
            while (token != NULL) {
                debug++;
                execvar++;
                atributos[index++] = strdup(token);
                token = strtok(NULL, ";");
            }
        //variavel auxiliar para trocar o [] por {}
        char aux[500] = {0};
        int j = 0;
        for (int i = 0; i < strlen(atributos[2]); i++) {
            if (atributos[2][i] == '[') {
                aux[j] = '{';
            } else if (atributos[2][i] == ']') {
                aux[j] = '}';
            } else if (atributos[2][i] == '\'') {
                continue; 
            } else {
                aux[j] = atributos[2][i];
            }
            j++; 
        }
        aux[j] = '\0'; 

        free(atributos[2]); 
        atributos[2] = strdup(aux);
            //comparação entre a primeira coluna e o id colocado pelo usuario
            if (strcmp(atributos[0], id_procurado) == 0) {
                if(execvar < 18){
                    if(execvar>16){
                    newPersonagem(personagem,atributos[0], atributos[1], atributos[2], atributos[3],atributos[4], atributos[5], "null" ,strlen(atributos[6]) > 7,strlen(atributos[7]) > 7,atributos[8], strlen(atributos[9]) > 7,atributos[10], atributos[11],atoi(atributos[12]), atributos[13], atributos[14],atributos[15], strlen(atributos[16]) > 7);
                    } else{
                    newPersonagem(personagem,atributos[0], atributos[1], atributos[2], atributos[3],atributos[4], atributos[5], "null" ,strlen(atributos[6]) > 7,strlen(atributos[7]) > 7,"null", strlen(atributos[8]) > 7,atributos[9], atributos[10],atoi(atributos[11]), atributos[12], atributos[13],atributos[14], strlen(atributos[15]) > 7);
                    }
                }else{
                    newPersonagem(personagem,atributos[0], atributos[1], atributos[2], atributos[3],atributos[4], atributos[5], atributos[6],strlen(atributos[7]) > 7,strlen(atributos[8]) > 7,atributos[9], strlen(atributos[10]) > 7,atributos[11], atributos[12],atoi(atributos[13]), atributos[14], atributos[15],atributos[16], strlen(atributos[17]) > 7);
                }
                idFound = true;
                return *personagem;
            }

            // liberar memoria
            for (int x = 0; x < index; x++) {
                free(atributos[x]);
            }
        }
        //fechar arquivo
        fclose(file);
    }
}

void swap(Personagem array[], int i, int j)
{
    Personagem temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int getMax(Personagem arr[], int n) {
    int max = strlen(arr[0].id);
    for (int i = 1; i < n; i++) {
        int len = strlen(arr[i].id);
        if (len > max) {
            max = len;
        }
    }
    return max;
}

void countSort(Personagem arr[], int n, int exp) {
    Personagem output[n]; 
    int count[256] = {0};

    for (int i = 0; i < n; i++) {
        int index = (strlen(arr[i].id) - exp >= 0) ? (arr[i].id[strlen(arr[i].id) - exp]) : 0;
        count[index]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (strlen(arr[i].id) - exp >= 0) ? (arr[i].id[strlen(arr[i].id) - exp]) : 0;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(Personagem arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; exp <= max; exp++) {
        countSort(arr, n, exp);
    }
}

void escreverLog(int comparacoes, int movimentacoes, long tempoExecucao) {
    char matricula[] = "811197";
    char nomeArquivo[] = "matrícula_radixsort.txt";

    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    fprintf(arquivo, "%s\t%d\t%d\t%ld\n", matricula, comparacoes, movimentacoes, tempoExecucao);
    fclose(arquivo);
}

int main(){
    //alocando local de memoria para o personagem
    setlocale(LC_CTYPE, "UTF-8"); 

    Personagem* personagem = (Personagem*) malloc ( 50 * sizeof(Personagem) );
    Personagem* tmp = (Personagem*) malloc (sizeof(Personagem));
    char* path = "/tmp/characters.csv"; 
    char id[81];

    //ler id novo
    scanf("%s",id ); 

    //limpar buffer
    getchar( );

    int n = 0;
    while( strcmp( id,"FIM" ) != 0 ){
        personagem[n] = ler( tmp, path, id );
        scanf( "%s", id ); 
        getchar( );
        n++;
    } 

    clock_t inicio, fim;
    double tempoExecucao;

    inicio = clock();
    
    radixSort(personagem, n);

    fim = clock();
    tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    int j = 0;
    while (j < n)
    {
        imprimir(&personagem[j]);
        j++;
    }
    
    //liberar memoria alocada
    free( personagem );
    free( tmp );
    personagem = NULL;

    escreverLog(comparacoes, movimentacoes, tempoExecucao);
    return 0;
}