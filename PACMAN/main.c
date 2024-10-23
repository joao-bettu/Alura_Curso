#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas, colunas;
    char** mapa; //Matriz
    FILE *f;

    f = fopen("/home/ixcsoft/Documentos/Códigos/Alura/PACMAN/mapa.txt", "r");
    if(f==NULL){
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    printf("Linhas: %d\nColunas: %d\n", linhas, colunas);

    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < colunas; i++){
        mapa[i] = malloc(sizeof(char) * colunas);
    }
    

    fclose(f);
    return 0;
}