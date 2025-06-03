#include <stdio.h>
#include <stdlib.h>

#include "Notas.h"

void cadastrarNota(Nota *nota, int *contNota){
    system("clear");
    printf("----Cadastrar nota----\n");
    printf("Informe a matricula do aluno :");
    scanf("%d", &nota->matricula);
    printf("Informe nota :");
    scanf("%f", &nota->nota);
    system("clear");
    *contNota = *contNota + 1;
}