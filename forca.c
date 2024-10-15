#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void abertura();
int get_chute(char *max_chutes, int tentativas);
bool achou_letra(char letra, int tentativas, char *max_chutes);
void forca(char *palavra, int tentativas, char *max_chutes);
bool enforcou(int tentativas, char *max_chutes, char *palavra);
bool acertou(char *palavra, int tentativas, char *max_chutes);

int main(){
    char palavra[20], max_chutes[26];
    int tentativas = 0;

    sprintf(palavra, "CONTRATO");

    abertura();

    do{
        forca(palavra, tentativas, max_chutes);
        printf("\n");
        tentativas = get_chute(max_chutes, tentativas);
    }while(!acertou(palavra, tentativas, max_chutes) && !enforcou(tentativas, max_chutes, palavra));

    if(enforcou(tentativas, max_chutes, palavra)){
        printf("Você perdeu! Tente novamente!\n");
    }
    if(acertou(palavra, tentativas, max_chutes)){
        printf("Você ganhou, parabéns!\n");
        printf("A palavra era: %s\n", palavra);
    }

    return 0;
}

void abertura(){
    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n");
}
int get_chute(char *max_chutes, int tentativas){
    char chute;
    
    printf("De o seu chute: ");
    scanf("%c", &chute);
    getchar();
    max_chutes[tentativas] = chute;
    tentativas++;
    return tentativas;
}
bool achou_letra(char letra, int tentativas, char *max_chutes){
    bool achou = false;
    for(int j = 0; j < tentativas; j++){
        if(max_chutes[j] == letra){
            achou = true;
            break;
        }
    }
    return achou;
}
void forca(char *palavra, int tentativas, char *max_chutes){
    printf("\nTentativa %d!\n", tentativas);
    for(int i = 0; i < strlen(palavra); i++){
        if(achou_letra(palavra[i], tentativas, max_chutes)){
            printf("%c ", palavra[i]);
        }else{
            printf("_ ");
        }
    }
}
bool enforcou(int tentativas, char *max_chutes, char *palavra){
    int erros = 0;
    char errados[5] = {NULL,NULL,NULL,NULL,NULL};

    for(int i = 0; i<tentativas; i++){
        bool existe = false;
        for(int j = 0; j < strlen(palavra); j++){
            if(max_chutes[i]==palavra[j]){
                existe = true;
                break;
            }
        }
        if(!existe){
            errados[erros] = max_chutes[i];
            erros++;
        }
    }
    if(errados[0]!=NULL){
        printf("Errados: ");
        for(int i = 0; i < strlen(errados); i++){
            printf("%c ", errados[i]);
        }
    printf("\n");
    }
    return erros >= 5;
}
bool acertou(char *palavra, int tentativas, char *max_chutes){
    for(int i = 0; i < strlen(palavra); i++){
        if(!achou_letra(palavra[i], tentativas, max_chutes)){
            return false;
        }
    }
    return true;
}