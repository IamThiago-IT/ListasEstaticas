#include <stdio.h>
#include <stdlib.h> // Para a função system()

#define m 10

// Declaração
struct Lista {
    char elem[m];
    int n;
};
struct Lista L;

// Inicializa
void iniciarLista(struct Lista *L) {
    L->n = 0;
}

// Acessa Lista
char acessar(struct Lista *L, int k) {
    char dado;
    if (k < 0 || k >= L->n) {
        printf("Erro - elemento fora dos limites\n");
        return '\0'; // Retornar um valor padrão ou um código de erro apropriado
    } else {
        dado = L->elem[k];
        return dado;
    }
}

// Altera
void alterar(struct Lista *L, int k, char dado) {
    if (k < 0 || k >= L->n) {
        printf("Erro - elemento fora dos limites\n");
    } else {
        L->elem[k] = dado;
    }
}

// Inserir Antes
void inserir(struct Lista *L, int k, char dado) {
    int i;
    if (k < 0 || k > L->n || L->n >= m) {
        printf("Erro - elemento fora dos limites\n");
    } else {
        for (i = L->n; i > k; i--) {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[k] = dado;
        L->n++;
    }
}

// Inserir Final
void InsereFinalLista(struct Lista *L, char dado) {
    if (L->n >= m) {
        printf("Erro - elemento fora dos limites\n");
    } else {
        L->elem[L->n] = dado;
        L->n++;
    }
}

// Remover
void remover(struct Lista *L, int k) {
    int i;
    if (k < 0 || k >= L->n) {
        printf("Erro - elemento fora dos limites\n");
    } else {
        for (i = k; i < L->n - 1; i++) {
            L->elem[i] = L->elem[i + 1];
        }
        L->n--;
    }
}


void exibirMenu() {
    system("clear");
    printf("=== Menu ===\n");
    printf("1. Inserir elemento no início\n");
    printf("2. Inserir elemento no final\n");
    printf("3. Inserir elemento em uma posição\n");
    printf("4. Acessar elemento em uma posição\n");
    printf("5. Alterar elemento em uma posição\n");
    printf("6. Remover elemento em uma posição\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main(void) {
    iniciarLista(&L);

    int opcao;
    char dado;
    int posicao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento para inserir no início: ");
                scanf(" %c", &dado);
                inserir(&L, 0, dado);
                break;
            case 2:
                printf("Digite o elemento para inserir no final: ");
                scanf(" %c", &dado);
                InsereFinalLista(&L, dado);
                break;
            case 3:
                printf("Digite a posição e o elemento para inserir: ");
                scanf("%d %c", &posicao, &dado);
                inserir(&L, posicao, dado);
                break;
            case 4:
                printf("Digite a posição para acessar: ");
                scanf("%d", &posicao);
                printf("Elemento na posição %d: %c\n", posicao, acessar(&L, posicao));
                break;
            case 5:
                printf("Digite a posição e o novo elemento: ");
                scanf("%d %c", &posicao, &dado);
                alterar(&L, posicao, dado);
                break;
            case 6:
                printf("Digite a posição para remover: ");
                scanf("%d", &posicao);
                remover(&L, posicao);
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("Pressione Enter para continuar...");
        getchar(); // Aguarda o usuário pressionar Enter antes de continuar
        getchar(); // Lê o Enter pressionado
    } while (opcao != 0);

    return 0;
}

