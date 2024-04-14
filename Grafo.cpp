#include "Grafo.h"
#include <iostream>
#include <string>

using namespace std;

vector<list<int>> matriz_adj_;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o num_vertices " +
            to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices = num_vertices;
    num_arestas_ = 0;

    vetores.resize(num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        for(auto j: vetores[i]){
            cout << j << " ";
        } 
    }
}
    
int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e){
    for (auto j : vetores[e.vertice1]){
        if (j == e.vertice2){
            return true;
        }
    }
    return false;
}

void Grafo::insere_aresta(Aresta e){
    if (!tem_aresta(e)) {
        vetores[e.vertice1].push_back(e.vertice2);
        vetores[e.vertice2].push_back(e.vertice1);
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e){
        if (!tem_aresta(e)) {
        vetores[e.vertice1].remove(e.vertice2);
        vetores[e.vertice2].remove(e.vertice1);
        num_arestas_--;
    }
}

void Grafo::imprimir(){
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ": ";
        for (auto j : vetores[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}