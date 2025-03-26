# Caminho Mais Rápido para o Incêndio 

Este projeto implementa um algoritmo para encontrar a **rota mais rápida** até uma esquina onde ocorre um incêndio. Utiliza um **grafo representado por listas de adjacência** e aplica o **algoritmo de Dijkstra** para calcular a menor distância em tempo de deslocamento.

---

## Como funciona?
1. O programa recebe um **arquivo de entrada** contendo as esquinas e as ruas que as conectam.
2. Constrói um **grafo** onde cada esquina é um **nó** e cada rua é uma **aresta** com um tempo de percurso.
3. Utiliza o **algoritmo de Dijkstra** para encontrar o **caminho mais curto** até a esquina onde ocorre o incêndio.
4. Exibe a **rota mais rápida** e o **tempo total** até o destino.

---

###  Exemplo de arquivo de entrada
```
3
5
1 2 4
1 3 2
2 4 3
3 4 1
4 5 5
0 0
```

---

##  Estruturas e Algoritmo
- **Lista de Adjacência:** Representa as esquinas e ruas do grafo.
- **Dijkstra:** Algoritmo utilizado para encontrar o menor caminho em termos de tempo de deslocamento.
- **Complexidade:** \(O(n^2)\)

---

##  Saída esperada
Se houver um caminho, o programa imprime a rota mais rápida e o tempo total:
```
rota mais rapida ate a esquina 3: 1 3
tempo total da rota = 2 min.
```
Caso não haja caminho, imprime:
```
Nao ha caminho ate a esquina #X.
```

---

