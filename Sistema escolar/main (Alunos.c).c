#include <stdio.h>
#include <stdlib.h>

#include "Alunos.h"

void cadastrarAluno(Aluno *aluno, int *conta) {
    system("clear");
    printf("----Cadastrar Aluno----\n");
    printf("Informe a matricula :");
    scanf("%d", &aluno->matricula);
    printf("Informe o nome :");
    scanf(" %[^\n]", aluno->nome);
    system("clear");
    *conta = *conta + 1;
}