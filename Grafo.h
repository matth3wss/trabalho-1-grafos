#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>

class Grafo {
public:
    Grafo(int numero_vertices);
    
    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprimir();
private:
    int num_vertices_;
    int num_arestas_;

    std::vector<std::vector<int>> matriz_adj_;
    
};

#endif /* GRAFO_H */
