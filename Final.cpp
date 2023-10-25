#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
struct grafo {
    int matriz[MAX][MAX]; 
    int vertices; 
};
struct grafo* criarGrafo(int n) {
	    struct grafo* Grafo = (struct grafo*) malloc(sizeof(struct grafo));
    Grafo->vertices = n; 
	    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Grafo->matriz[i][j] = 0;
        }
    }
    return Grafo;
}
void criarAresta(struct grafo *g, int a, int b) {
        if (a >= 0 && a < g->vertices && b >= 0 && b < g->vertices) { 
	        g->matriz[a][b] = 1;
        g->matriz[b][a] = 1;
    } else {
        printf("Vertices fora do alcance.\n");
    }
}
void removerAresta(struct grafo *g, int a, int b) {
        if (a >= 0 && a < g->vertices && b >= 0 && b < g->vertices) {
                   g->matriz[a][b] = 0;
        g->matriz[b][a] = 0;
    } else {
        printf("Vertices fora do alcance.\n");
    }
}
void exibirArestas(struct grafo *g) {
    printf("Arestas do Grafo:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = i + 1; j < g->vertices; j++) {
            if (g->matriz[i][j] == 1) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}
int main() {
    struct grafo *G = criarGrafo(8); 
    int opcao;
    int a, b;
    do {
        printf("\nMenu:\n");
        printf("1. Criar aresta\n");
        printf("2. Inserir aresta\n");
        printf("3. Remover aresta\n");
        printf("4. Exibir arestas\n");
        printf("5. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Informe os vértices da aresta (a e b): ");
                scanf("%d %d", &a, &b);
                criarAresta(G, a, b);
                break;
            case 2:
                printf("Informe os vértices da aresta (a e b): ");
                scanf("%d %d", &a, &b);
                criarAresta(G, a, b);
                break;
            case 3:
                printf("Informe os vértices da aresta a ser removida (a e b): ");
                scanf("%d %d", &a, &b);
                removerAresta(G, a, b);
                break;
            case 4:
                exibirArestas(G);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
    free(G);
    return 0;
}

