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
    bool eh_clique(std::vector<int> conjunto);
    void imprimir();
    bool existe_caminho_restrito(int v1, int v2, Aresta e, std::vector<int> marcado);
    void imprime_graus();
private:
    int num_vertices_;
    int num_arestas_;

    std::vector<std::list<int>> vetores;
    
};

#endif /* GRAFO_H */
