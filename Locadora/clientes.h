#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct{
    int ID, Telefone;
    char Nome[50];
} Cliente;

void cadastrarCliente(Cliente *clientes, int *totalClientes);
void listarClientes(Cliente *clientes, int totalClientes);
void buscarClientePorID(Cliente *clientes, int totalClientes, int id);

#endif
