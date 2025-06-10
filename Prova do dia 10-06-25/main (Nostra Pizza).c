#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
} Pizza;

typedef struct {
    char nome[50];
    char cpf[20];
    int idade;
    char endereco[100];
} Cliente;

Pizza pizzas[50];
int totalPizzas = 0;

Cliente clientes[100];
int totalClientes = 0;

void finalizarfuncao(){
    system("clear"); 
}

void cadastrarPizza();
void cadastrarCliente();
void listarPizzas();
void listarClientes();
void comprarPizza();

int main() {
    int opcao;

    do {
         finalizarfuncao();
        printf("---- Nostra Pizza ----\n");
        printf("1 - Cadastrar Pizza\n");
        printf("2 - Cadastrar Cliente\n");
        printf("3 - Listar Pizzas\n");
        printf("4 - Listar Clientes\n");
        printf("5 - Comprar Pizza\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

         finalizarfuncao();
        switch(opcao) {
            case 1: 
            cadastrarPizza(); 
            break;
            case 2: 
            cadastrarCliente(); 
            break;
            case 3: 
            listarPizzas(); 
            break;
            case 4: 
            listarClientes(); 
            break;
            case 5: 
            comprarPizza(); 
            break;
            case 0: 
            printf("Obrigado pela preferência!\n");
            break;
            default:
            printf("Opção inválida.\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...\n");
            getchar();
        }

    } while(opcao != 0);

    return 0;
}

void cadastrarPizza() {
   finalizarfuncao();
    if (totalPizzas >= 50) {
        printf("Limite de pizzas atingido!\n");
        return;
    }

    printf("Cadastro de Pizza\n");
    printf("Nome da pizza: ");
    scanf(" %[^\n]", pizzas[totalPizzas].nome);
    printf("Preço da pizza: R$ ");
    scanf("%f", &pizzas[totalPizzas].preco);
    totalPizzas++;

    printf("Pizza cadastrada com sucesso!\n");
}

void cadastrarCliente() {
     finalizarfuncao();
    if (totalClientes >= 100) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("Cadastro de Cliente\n");
    printf("Nome: ");
    scanf(" %[^\n]", clientes[totalClientes].nome);
    printf("CPF: ");
    scanf(" %s", clientes[totalClientes].cpf);
    printf("Idade: ");
    scanf("%d", &clientes[totalClientes].idade);
    printf("Endereço: ");
    scanf(" %[^\n]", clientes[totalClientes].endereco);
    totalClientes++;

    printf("Cliente cadastrado com sucesso!\n");
}

void listarPizzas() {
   finalizarfuncao();
    if (totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    printf("Pizzas Disponíveis:\n");
    for (int i = 0; i < totalPizzas; i++) {
        printf("%d - %s | R$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].preco);
    }
}

void listarClientes() {
    finalizarfuncao();
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Clientes Cadastrados:\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("%d - %s (CPF: %s)\n", i + 1, clientes[i].nome, clientes[i].cpf);
        printf("Idade: %d | Endereço: %s\n", clientes[i].idade, clientes[i].endereco);
    }
}

int cpfIgual(char cpf1[], char cpf2[]) {
    int i = 0;
    while (cpf1[i] != '\0' || cpf2[i] != '\0') {
        if (cpf1[i] != cpf2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

void comprarPizza() {
    finalizarfuncao();
    char cpf[20];
    printf("Digite seu CPF: ");
    scanf(" %s", cpf);

    int clienteEncontrado = -1;
    for (int i = 0; i < totalClientes; i++) {
        if (cpfIgual(cpf, clientes[i].cpf)) {
            clienteEncontrado = i;
            break;
        }
    }

    if (clienteEncontrado == -1) {
        printf("CPF não encontrado. Cadastre-se primeiro.\n");
        return;
    }

    int quantidade, escolha;
    float total = 0;

    printf("Quantas pizzas deseja comprar? ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        listarPizzas();
        printf("Escolha o número da pizza %d: ", i + 1);
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= totalPizzas) {
            total += pizzas[escolha - 1].preco;
            printf("Adicionado: %s | R$ %.2f\n", pizzas[escolha - 1].nome, pizzas[escolha - 1].preco);
        } else {
            printf("Opção inválida.\n");
        }
    }

    printf("\n--- Pedido Finalizado ---\n");
    printf("Cliente: %s\nEndereço: %s\nTotal: R$ %.2f\n",
           clientes[clienteEncontrado].nome,
           clientes[clienteEncontrado].endereco,
           total);
}