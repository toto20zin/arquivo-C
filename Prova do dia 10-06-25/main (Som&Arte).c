#include <stdio.h>
#include <stdlib.h>

struct CD{
    
    char banda[50];
    int estoque, ano, genero, id;
    float preco;
    
};

int num=0;
struct CD cd[100];
void Cadastrar();
void  Listarcd();
void Vender();
void Consultar();

int main(){
    
    int opcao;
    
    do{
    printf("------ Som & Arte ------\n");
    printf("1 - Cadastrar CD\n");
    printf("2 - Pesquisar\n");
    printf("3 - Consultar\n");
    printf("4 - Vender\n");
    printf("0 - Sair\n");
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);
    getchar();
    system("clear");
    switch(opcao){
        case 1:
           Cadastrar();
           break;
        
        case 2:
          Listarcd();
           break;
           
        case 3:
           Consultar();
           break;
           
        case 4:
           Vender();
           break;
           
        case 0:
           printf("Saindo...\n");
           break;
        
        default:
           printf("Opção invalida");
           break;
    }
    
    
    getchar();
    system("clear");
    
    }while(opcao != 0);
    
    return 0;
}

void Cadastrar(){
    printf("------ Cadastro ------\n");
    printf("Banda: ");
    scanf(" %[^\n]", cd[num].banda);
    printf("Escolha o genêro:\n");
    printf("1 - Pop\n");
    printf("2 - Rock\n");
    printf("3 - Funk\n");
    printf("4 - Sertanejo\n");
    printf("5 - Pagode\n");
    printf("6 - Rap\n");
    printf("7 - Trap\n");
    printf("Genêro (Número do genêro): ");
    scanf(" %d", &cd[num].genero);
    printf("Ano: ");
    scanf("%d", &cd[num].ano);
    printf("Preço: ");
    scanf("%f", &cd[num].preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &cd[num].estoque);
    cd[num].id= num;
    printf("ID: %d\n", cd[num].id);
    num++;
}

void Listarcd() {
    int genero, encontrar = 0;

    if (num > 0) {
        printf("------ Pesquisar ------\n");
        printf("Genêro:\n");
        printf("1 - Pop\n");
        printf("2 - Rock\n");
        printf("3 - Funk\n");
        printf("4 - Sertanejo\n");
        printf("5 - Pagode\n");
        printf("6 - Rap\n");
        printf("7 - Trap\n");
        printf("Selecione uma opção: ");
        scanf("%d", &genero);

        for (int i = 0; i < num; i++) {
            if (cd[i].genero == genero) {
                printf("Banda: %s\n", cd[i].banda);
                printf("Genêro: %d\n", cd[i].genero);
                printf("Ano: %d\n", cd[i].ano);
                printf("Preço: %.2f\n", cd[i].preco);
                printf("ID: %d\n", cd[i].id);
                printf("Quantidade em estoque: %d\n", cd[i].estoque);
                printf("------------------------------\n");
                encontrar = 1;
            }
        }

        if (!encontrar) {
            printf("Nenhum CD encontrado com esse genêro.\n");
        }

    } else {
        printf("Nenhum CD cadastrado.\n");
    }
}

void Consultar(){
    
    int  id, encontrar=0;
    
    
    if(num==1){
    printf("------ Consultar ------\n");
    printf("Preenha as informações do produto que deseja:\n");
    printf("ID: ");
    scanf("%d", &id);
    getchar();
    system("clear");
    for(int i=0; i<num; i++){
        if(id==cd[i].id){
            printf("------ Consultar ------\n");
            printf("Banda: %s\n", cd[i].banda);
            printf("Genêro: %d\n", cd[i].genero);
            printf("Ano: %d\n", cd[i].ano);
            printf("Preço: %.2f\n", cd[i].preco);
            printf("ID: %d\n", cd[num].id);
            if(cd[i].estoque>0){
                printf("Quantidade em estoque: %d\n", cd[i].estoque);
            }
            else{
                printf("Quantidade em estoque: %d\n", cd[i].estoque);
            }
        
            encontrar=1;
        }
        else if(encontrar==0){
            printf("CD não encontrado!!\n");
        }
    }
}
}

void Vender(){
    
    int quantidade, opcao, id, i, encontrar=0;
    
    if(num==1){
    printf("------ Venda ------\n");
    printf("Preenha as informações do produto que deseja:\n");
    printf("ID: ");
    scanf("%d", &id);
    getchar();
    system("clear");
    
    for(i=0; i<num; i++){
        if(id==cd[i].id){
            
            printf("------ Venda ------\n");
            
            printf("Banda: %s\n", cd[i].banda);
            printf("Genêro: %d\n", cd[i].genero);
            printf("Ano: %d\n", cd[i].ano);
            printf("Preço: %.2f\n", cd[i].preco);
            printf("Quantidade em estoque: %d\n", cd[i].estoque);
            printf("ID: %d\n", cd[num].id);
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &quantidade);
            getchar();
            system ("clear");
            printf("Quantidade: %d\n", quantidade);
            printf("Total: R$%.2f\n", quantidade*cd[i].preco);
            if(cd[i].estoque>0 && cd[i].estoque>=quantidade){
            printf("\nDeseja confirmar a compra? (1 - Sim / 2 - Não\n");
            scanf("%d", &opcao);
            getchar();
            system ("clear");
            switch(opcao){
                case 1:
                   printf("Compra confirmada\n");
                   cd[i].estoque = cd[i].estoque - quantidade;
                   break;
        
                case 2:
                   printf("Compra cancelada\n");
                   break;
         
                default:
                   printf("Opção invalida\n");
            
            encontrar=1;
        }
            }
            else{
                printf("Quantidade insulficiente\n");
            }
        
        }
        else if(encontrar==0){
            printf("Nennhum cd encontrado\n");
        }
    }
    
    }

    else{
        printf("Nenhum produto cadastrado\n");
    }
}