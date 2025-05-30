#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char tipo[20];
    int capacidade;
    float preco;
    char hospede[30];
    char cpf[20];
} Quarto;

Quarto quartos[50];
int numQuartos = 0;

void cadastrarQuarto();
void listarQuartos();
void checkIn();
void servicoDeQuarto();
void fazerPedido();
void finalizarfuncao();

int main() {
    int opcao;

    do {
        printf("---- Hotel Fantini ----\n");
        printf("1 - Cadastrar Quarto\n");
        printf("2 - Listar Todos os Quartos\n");
        printf("3 - Check-in\n");
        printf("4 - Serviço de Quarto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarQuarto();
                break;
            case 2:
                listarQuartos();
                break;
            case 3:
                checkIn();
                break;
            case 4:
                servicoDeQuarto();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastrarQuarto() {
    system("clear");
    printf("---- Cadastrar Novo Quarto ----\n");

    printf("ID do Quarto: ");
    scanf("%d", &quartos[numQuartos].id);

    printf("Tipo (Simples, Duplo, Suite): ");
    scanf("%s", quartos[numQuartos].tipo);

    printf("Capacidade de pessoas: ");
    scanf("%d", &quartos[numQuartos].capacidade);

    printf("Preço por noite (R$): ");
    scanf("%f", &quartos[numQuartos].preco);

    numQuartos++;
    finalizarfuncao();
}

void listarQuartos() {
    system("clear");
    printf("---- Lista de Quartos ----\n");

    if (numQuartos == 0) {
        printf("Nenhum quarto cadastrado ainda.\n");
    }

    for (int i = 0; i < numQuartos; i++) {
        printf("ID: %d\n", quartos[i].id);
        printf("Tipo: %s\n", quartos[i].tipo);
        printf("Capacidade: %d pessoas\n", quartos[i].capacidade);
        printf("Preço: R$ %.2f\n", quartos[i].preco);
        if (quartos[i].hospede[0] != '\0') {
            printf("Hóspede: %s\n", quartos[i].hospede);
            printf("CPF: %s\n", quartos[i].cpf);
        } else {
            printf("Hóspede: (quarto vazio)\n");
        }
        printf("-------------------------\n");
    }

    finalizarfuncao();
}

void checkIn() {
    system("clear");
    int id;
    printf("---- Check-in ----\n");
    printf("Digite o ID do quarto: ");
    scanf("%d", &id);

    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].id == id) {
            printf("Digite o nome do hóspede: ");
            scanf("%s", quartos[i].hospede);
            printf("Digite o CPF do hóspede: ");
            scanf("%s", quartos[i].cpf);
            printf("Check-in realizado com sucesso.\n");
            finalizarfuncao();
            return;
        }
    }

    printf("Quarto com ID %d não encontrado.\n", id);
    finalizarfuncao();
}

void servicoDeQuarto() {
    system("clear");
    int id;
    printf("---- Serviço de Quarto ----\n");

    printf("Quartos com hóspede:\n");
    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].hospede[0] != '\0') {
            printf("ID: %d - Hóspede: %s\n", quartos[i].id, quartos[i].hospede);
        }
    }

    printf("Digite o ID do quarto para solicitar serviço: ");
    scanf("%d", &id);

    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].id == id && quartos[i].hospede[0] != '\0') {
            fazerPedido();
            finalizarfuncao();
            return;
        }
    }

    printf("Quarto não encontrado ou está vazio.\n");
    finalizarfuncao();
}

void fazerPedido() {
    int opcao;
    printf("\n--- Menu de Serviço de Quarto ---\n");
    printf("1 - Água (R$2,00)\n");
    printf("2 - Sanduíche (R$10,00)\n");
    printf("3 - Refrigerante (R$5,00)\n");
    printf("4 - Pizza (R$25,00)\n");
    printf("Escolha o pedido: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Pedido: Água enviado ao quarto.\n");
            break;
        case 2:
            printf("Pedido: Sanduíche enviado ao quarto.\n");
            break;
        case 3:
            printf("Pedido: Refrigerante enviado ao quarto.\n");
            break;
        case 4:
            printf("Pedido: Pizza enviada ao quarto.\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

void finalizarfuncao() {
    printf("\n------------------------------\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar();
    system("clear");
}
