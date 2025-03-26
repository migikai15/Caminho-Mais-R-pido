#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {int destino,tempo;} Aresta;//usamos a aresta para representar uma rua entre duas esquinas

typedef struct {Aresta arestas[MAX]; int tamanho;} ListaAdjacencia;//lista de ruas saindo de uma esquina,Aresta aresta é uma array de arestas saindo de uma esquina em especifico

ListaAdjacencia grafo[MAX];//array que cada posicao representa uma esquina e armazena suas arestas para os vizinhos e criando um grafo com uma lista das adjacencias
//usamos deste jeito pois permite que o algoritmo de Dijkstra acesse diretamente todas as ruas conectadas a cada esquina para calcular as distâncias.


int dist[MAX];//distancia minima de cada esquina ate a primeira esquina
int rota[MAX]; //armazena a ultima esquina que foi usada pra chegar na rota x
int visitado[MAX];//para ver se ja esta visitado ou nao

void inicializarGrafo(int n) {
    for (int i = 1; i <= n; i++) {
        grafo[i].tamanho = 0;//cada esquina começa com zero arestas
        dist[i] = INT_MAX;//a distacia inicial de cada esquina sera infinita menos a inicial 
        visitado[i] = 0;//maraca as esquinas como nao visitadas
        rota[i] = -1;//mostra que nenhuma rota doi determinada ainda
    }
}

void adicionarAresta(int origem, int destino, int tempo) {
    grafo[origem].arestas[grafo[origem].tamanho].destino = destino;//adiciona o destino para a esquina"origem"
    grafo[origem].arestas[grafo[origem].tamanho].tempo = tempo;//adiciona o tempo para a esquina"origem"
    grafo[origem].tamanho++;//incrementa o contador de arestas para a esquina "origem"
}

void rotaMaisRapida(int esquinaOrigem, int esquinaIncendio, int n) {
    dist[esquinaOrigem] = 0;//define o ponro de partida como 0

    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++) {//escolhe v como a esquina de menor dist que nao foi processada
            if (!visitado[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        if (dist[v] == INT_MAX) break;//checa se tem esquinas nao acessadas
        visitado[v] = 1;//marca como visitado

        for (int j = 0; j < grafo[v].tamanho; j++) {
            int u = grafo[v].arestas[j].destino;//esquina de destino
            int tempo = grafo[v].arestas[j].tempo;//tempo

            if (dist[v] + tempo < dist[u]) {//se a rota que passa por v reduz a distancia ate u 
                dist[u] = dist[v] + tempo;//atualiza dist e salva 
                rota[u] = v;//adiciona v para formar o caminho mais curto
            }
        }
    }

    if (dist[esquinaIncendio] == INT_MAX) {//se a esquina do incendio ainda estiver como int max nao existe uma rota
        printf("Nao ha caminho ate a esquina #%d.\n", esquinaIncendio);
        return;
    }

    printf("rota mais rapida ate a esquina %d: ", esquinaIncendio);
    int caminho[MAX];
    int tamanhoCaminho = 0;
    for (int v = esquinaIncendio; v != -1; v = rota[v]) {//vai da esquina do incendio ate chegar na primeira esquina
        caminho[tamanhoCaminho++] = v;
    }
    for (int i = tamanhoCaminho - 1; i >= 0; i--) {
        printf("%d ", caminho[i]);//printa o caminho reverso
    }
    printf("\ntempo total da rota = %d min.\n", dist[esquinaIncendio]);//mostra o tempo total ate a rota mais rapida
}

int main(int argc, char *argv[])
{
    int esquinaIncendio, n;
    if (argc < 2)
    {
        printf("!passe o nome do arquivo!\n");
        return 0;
        
    }
    FILE *file = fopen(argv[1], "r"); // abre o arquivo
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(file, "%d", &esquinaIncendio);//le a esquina do incendio
    fscanf(file, "%d", &n);//le o numero de esquinas	

    inicializarGrafo(n);//inicializa as estruturas

    int origem, destino, tempo;
    while (fscanf(file, "%d %d %d", &origem, &destino, &tempo) == 3) {//le e adiciona as ruas ate encontrar 0
        if (origem == 0 || destino == 0) break;
        adicionarAresta(origem, destino, tempo);
    }

    fclose(file);//fecha arquivo

    rotaMaisRapida(1, esquinaIncendio, n);//chama a função pra calcular a rota mais rapida

    return 0;
    
}
