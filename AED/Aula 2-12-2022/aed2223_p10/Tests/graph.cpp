// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
int Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    int count = 0;
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            count++;
            dfs(w);
    }
    return count;
}


// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if(v > n || v < 1) return -1;
    return nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    if(v > n || v < 1) return -1;
    int sum = 0;
    for (auto e: nodes[v].adj) sum += e.weight;
    return sum;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int count = 0;
    for(int i = 1; i < n+1; i++){
        if(!nodes[i].visited){
            count++;
            dfs(i);
        }
    }
    return count;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int count = 0;
    int aux = 0;
    for(int i = 1; i < n+1; i++){
        if(!nodes[i].visited){
            aux = dfs(i);
            if(aux > count) count = aux;
        }
    }
    return count;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    return false;
}
