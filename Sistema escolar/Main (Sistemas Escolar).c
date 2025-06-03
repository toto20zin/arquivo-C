#include <stdio.h>
#include <stdlib.h>

#include "Alunos.h"
#include "Notas.h"
#include "Media.h"

int main(){
    int opcao;
    Aluno alunos[10];
    Nota notas[50];
    int contAluno = 0, contNota = 0;
    
    do {
    
    printf("----Sistema Escolar----\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Cadastrar nota\n");
    printf("3 - Calcular media\n");
    printf("0 - Sair\n");
    printf("Selecione uma opção\n");
    scanf("%d", &opcao);
    
      switch(opcao) {
        case 1:
            cadastrarAluno(&alunos[contAluno], &contAluno);
            contAluno++;
            break;
        case 2:
            cadastrarNota(&notas[contNota], &contNota);
            break;
        case 3:
            calcularMedia(alunos, notas);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    } while(opcao != 0);
    return 0;
}











