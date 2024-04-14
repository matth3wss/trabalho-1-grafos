#include "Grafo.h"
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> matriz_adj_;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o num_vertices " +
            to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);

    for (int i = 0; i < num_vertices; i++) { // ou i < matriz_adj_.size()
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e){
    return matriz_adj_[e.vertice1][e.vertice2] == 1;
}

void Grafo::insere_aresta(Aresta e){
    if (!tem_aresta(e)) {
        matriz_adj_[e.vertice1][e.vertice2] = 1;
        matriz_adj_[e.vertice2][e.vertice1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e){
        if (!tem_aresta(e)) {
        matriz_adj_[e.vertice1][e.vertice2] = 0;
        matriz_adj_[e.vertice2][e.vertice1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprimir(){
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ": ";
        for (int j = 0; j < num_vertices_; j++) {
            // if (matriz_adj_[i][j] != 0) {
            //     cout << " " << j;
            // }
            cout << " " << matriz_adj_[i][j];
        }
        cout << endl;
    }
}