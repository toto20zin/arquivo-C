#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "locacoes.h"

int main() {

    Cliente clientes[10];
    int totalClientes = 0;
    Locacao locacoes[50];                                       
    int totalLocacoes = 0;

    int opcao, idCliente;
    
    do {
        printf("\n======= SISTEMA DE LOCADORA =======\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Realizar locação\n");
        printf("4. Listar locações\n");
        printf("5. Buscar locações por ID do Cliente\n");
        printf("6. Buscar cliente por ID\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                cadastrarCliente(&clientes[totalClientes], &totalClientes);
                break;
            case 2:
                listarClientes(clientes, totalClientes);
                break;
            case 3:
                realizarLocacao(&locacoes[totalLocacoes], &totalLocacoes, clientes, totalClientes);
                break;
            case 4:
                listarLocacoes(locacoes, totalLocacoes);
                break;
            case 5:
                printf("Digite o ID do cliente: ");
                scanf("%d", &idCliente);
                buscarLocacoesPorCliente(locacoes, totalLocacoes, idCliente);
                break;
            case 6:
                printf("Digite o ID do cliente: ");
                scanf("%d", &idCliente);
                buscarClientePorID(clientes, totalClientes, idCliente);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}