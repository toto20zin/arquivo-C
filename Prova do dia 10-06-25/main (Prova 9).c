#include <stdio.h>
#include <stdlib.h>

struct Aluno{
  char nome[50];
  int idade;
  float nota;
};

struct Aluno alunos[3];

void listarAlunos () {
    for(int i = 0; i < 3; i++){
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
        printf("---------------\n");
    }
}

int main(){
    
    for(int i=0; i<3; i++){
        printf("Digite os dados do aluno:\n");
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        getchar();
        system("clear");
    }
    
    listarAlunos ();
    
    return 0;
}