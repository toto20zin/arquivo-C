#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    int quantidade;
    float preco;
};

struct Produto produtos; 
int cadastrado = 0;

void cadastrarProduto();
void listarProdutos();
void Comprar();

int main() {
    int opcao;

    do {
        printf("------ SuperMercado SuperMais ------\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - listarProdutos\n");
        printf("3 - Realizar compra\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();
        system("clear");

        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                Comprar();
                break;
            case 0:
                printf("Volte sempre!\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

        getchar();
        system("clear");
    } while(opcao != 0);

    return 0;
}

void cadastrarProduto() {
    printf("------ Cadastro ------\n");
    printf("Nome: ");
    scanf(" %[^\n]", produtos.nome);
    printf("Preço: ");
    scanf("%f", &produtos.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produtos.quantidade);
    cadastrado = 1;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    if (!cadastrado) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }
    printf("------ listar Produtos ------\n");
    printf("Nome: %s\n", produtos.nome);
    printf("Preço: %.2f\n", produtos.preco);
    printf("Quantidade em estoque: %d\n", produtos.quantidade);
}

void Comprar() {
    if (!cadastrado) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    printf("------ Compra ------\n");
    printf("Produto: %s\n", produtos.nome);
    printf("Preço: %.2f\n", produtos.preco);
    printf("Quantidade disponível: %d\n", produtos.quantidade);

    int quantidade;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidade);
    getchar();

    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }
    if (quantidade > produtos.quantidade) {
        printf("Estoque insuficiente! Disponível: %d\n", produtos.quantidade);
        return;
    }

    float total = quantidade * produtos.preco;
    printf("Quantidade: %d\n", quantidade);
    printf("Total: R$ %.2f\n", total);

    int opcao;
    printf("Deseja confirmar a compra? (1 - Sim / 2 - Não): ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao) {
        case 1:
            produtos.quantidade = quantidade;
            printf("Compra confirmada!\n");
            break;
        case 2:
            printf("Compra cancelada!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}
