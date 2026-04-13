#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct produto{
    int code;
    char nome[51];
    char disp[21];
    double price;
    int corredor;
    char funcionalidade[101];
    char marca[101];
    int quant;
};
typedef struct produto Produto;

Produto DigitarProduto();
void Telacadastro();
void Telapesquisa();
void Telaexcluir();
void Telaalterar();
void Telasair();
int confirmar();
int cadastro();
void Telainicial();
int inicio();
void Telalista();
Produto buscar();
void imprimir();
int excluir();
int alterar();
void lembretes();
void mostrarlist();
Produto AlterarProduto();
#endif
