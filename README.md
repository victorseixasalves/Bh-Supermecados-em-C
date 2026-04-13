# 🛒 BH Supermercados
<img width="510" height="169" alt="Bh Supermercados" src="https://github.com/user-attachments/assets/be5caa09-634d-470b-b871-ba7daec73605" />


## ✅ Funcionalidades

| Opção     | Descrição                                         |
|-----------|---------------------------------------------------|
| Registro  | Cadastra um novo produto no sistema               |
| Pesquisar | Busca um produto pelo código                      |
| Alterar   | Edita os dados de um produto já cadastrado        |
| Excluir   | Remove um produto do sistema (soft delete)        |
| Listar    | Exibe todos os produtos registrados, página a página |
| Sair      | Encerra o programa com confirmação                |

---

## 🗂️ Estrutura do Projeto

```
BH-Supermercados/
├── main.c             # Ponto de entrada — loop principal e switch de opções
├── Produto.c          # Lógica de negócio: CRUD completo de produtos
├── Produto.h          # Definição da struct Produto e protótipos
├── Interface.c        # Funções de UI: menu, caixas, entrada de dados, cores
├── Interface.h        # Constantes de teclas, cores e protótipos da interface
├── Art.c              # ASCII Arts de cada tela (cabeçalhos)
├── Art.h              # Protótipos das funções de arte
└── Arquivo.txt        # Arquivo binário de dados (gerado em tempo de execução)
```

---

## 🧱 Estrutura do Produto

```c
struct produto {
    int    code;                // Código único do produto
    char   nome[51];            // Nome
    char   disp[21];            // Disponibilidade (data de chegada: dd/mm/aa)
    double price;               // Preço
    int    corredor;            // Número do corredor
    char   funcionalidade[101]; // Categoria (ex: Comida, Limpeza...)
    char   marca[101];          // Marca
    int    quant;               // Quantidade em estoque
};
```

---

## 🛠️ Como Compilar

> ⚠️ Este projeto usa a API do Windows (`windows.h`, `conio.h`) e **só compila/executa no Windows**.

### Usando CodeBlocks
1. Abra o arquivo `TRABALHO FINAL.cbp`
2. Pressione **F9** para compilar e executar

### Usando GCC (MinGW no Windows)
```bash
gcc main.c Produto.c Art.c Interface.c -o BHSupermercados.exe
```

### Executar
```bash
./BHSupermercados.exe
```

---

## 💾 Persistência de Dados

Os dados são salvos em formato binário no arquivo `Arquivo.txt`, criado automaticamente na primeira execução. A exclusão usa **soft delete**: o campo `code` é marcado como `-1`, preservando o registro sem exibi-lo nas listagens.

---

## 🖥️ Tecnologias

- **Linguagem:** C (padrão C99)
- **IDE:** Code::Blocks
- **Compilador:** GCC (MinGW)
- **API:** Windows Console API (`windows.h`, `conio.h`)
- **Plataforma:** Windows

---

## 👨‍💻 Autor

Victor Seixas Alves, resultado do trabalho final da disciplina de **Algoritmo e Estrutura de Dados** do curso de *Sistemas de Informação (1° Período) - Unimontes*
