#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"


void cadastrarCliente(Cliente *clientes, int *totalClientes) {
    system("clear");
    printf("----Cadastrar Cliente----\n");
    printf("Insira seu nome: \n");
    scanf("%s", clientes[*totalClientes].Nome); 
    printf("Insira seu ID: \n");
    scanf("%d", &clientes[*totalClientes].ID); 
    printf("Insira seu telefone: \n");
    scanf("%d", &clientes[*totalClientes].Telefone); 
    (*totalClientes)++;
    printf("Você está cadastrado!\n");
    system("clear");
}
void listarClientes(Cliente *clientes, int totalClientes) {
    system("clear");
    printf("----Listar Clientes----\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("Nome: %s\n", clientes[i].Nome);
        printf("ID: %d\n", clientes[i].ID);
        printf("Telefone: %d\n", clientes[i].Telefone);
    }
}
void buscarClientePorID(Cliente *clientes, int totalClientes, int idCliente) {
    int encontrado = 0;
    system("clear");
    printf("----Buscar Cliente por ID----\n");
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].ID == idCliente) {
            printf("Nome: %s\n", clientes[i].Nome);
            printf("ID: %d\n", clientes[i].ID);
            printf("Telefone: %d\n", clientes[i].Telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", idCliente);
        system("clear");
    }
}


