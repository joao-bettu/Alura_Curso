#include <stdio.h>
#include <stdlib.h>

int main(){
    char mapa[5][10+1]; //Matriz de 5x10
    FILE *f;

    f = fopen("/home/ixcsoft/Documentos/Códigos/Alura/PACMAN/mapa.txt", "r");
    if(f==NULL){
        printf("Não foi possível abrir o arquivo!\n");
        exit(1);
    }

    for(int i = 0; i <= 4; i++){
        fscanf(f, "%s", mapa[i]);
    }
    for(int j = 0; j <= 4; j++){
        printf("%s\n", mapa[j]);
    }

    fclose(f);
    return 0;
}