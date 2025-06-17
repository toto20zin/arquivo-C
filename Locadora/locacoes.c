#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "locacoes.h"

void realizarLocacao(Locacao *locacoes, int *totalLocacoes, Cliente *clientes, int totalClientes) {
    int id;
    system("clear");
    printf("ID do cliente: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].ID == id) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
        return;
        system("clear");
    }

    Locacao *novaLocacao = &locacoes[*totalLocacoes];
    novaLocacao->IDCliente = id;

    printf("Nome do filme: ");
    scanf(" %[^\n]", novaLocacao->Filme);

    printf("Data da locação: ");
    scanf(" %[^\n]", novaLocacao->Data);

    (*totalLocacoes)++;
    printf("Locação registrada com sucesso!\n");
    system("clear");
}


void listarLocacoes(Locacao *locacoes, int totalLocacoes) {
    system("clear");
    printf("----Listar Locações----\n");
    for (int i = 0; i < totalLocacoes; i++) {
        printf("ID Cliente: %d\n", locacoes[i].IDCliente);
        printf("Filme: %s\n", locacoes[i].Filme);
        printf("Data: %s\n", locacoes[i].Data);
    }
}

void buscarLocacoesPorCliente(Locacao *locacoes, int totalLocacoes, int idCliente) {
    system("clear");
    printf("----Buscar Locações por Cliente----\n");
    for (int i = 0; i < totalLocacoes; i++) {
        if (locacoes[i].IDCliente == idCliente) {
            printf("Filme: %s\n", locacoes[i].Filme);
            printf("Data: %s\n", locacoes[i].Data);
            }
    }
}


