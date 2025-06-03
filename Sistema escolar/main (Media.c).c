#include <stdio.h>
#include <stdlib.h>

#include "Media.h"
#include "Notas.h"
#include "Alunos.h"

void calcularMedia(Aluno alunos[], Nota notas[]) {
    int matricula, qntNotas = 0;
    float media = 0;
    system("clear");
    printf("----Calcular Media----\n");
    printf("Informe uma matricula :");
    scanf("%d", &matricula);
    for(int i = 0; i < 10; i++) {
        if(alunos[i].matricula == matricula){
            printf("Nome: %s\n", alunos[i].nome);
            break;
        }
    }
    for(int i = 0; i < 50; i++) {
        if(notas[i].matricula == matricula) {
            media += notas[i].nota;
            qntNotas++;
        }
    }
    printf("Media : %.2f\n", (media / qntNotas));
}