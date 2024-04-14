#include "Grafo.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

vector<list<int>> vetores;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o num_vertices " +
            to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
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
    if (!tem_aresta(e) && e.vertice1 != e.vertice2){
        vetores[e.vertice1].push_back(e.vertice2);
        vetores[e.vertice2].push_back(e.vertice1);
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e){
    if (tem_aresta(e)) {
        vetores[e.vertice1].erase(std::find(vetores[e.vertice1].begin(), vetores[e.vertice1].end(), e.vertice2));
        vetores[e.vertice2].erase(std::find(vetores[e.vertice2].begin(), vetores[e.vertice2].end(), e.vertice1));
        num_arestas_--;
    }
}

bool Grafo::eh_clique(vector<int> conjunto){
    int counter = 0;
    for (auto i : conjunto){
        for (auto j : vetores[i]){
            if (count(conjunto.begin(), conjunto.end(), j) > 0){
                counter++;
            }
        }
    }
    return counter == conjunto.size() * (conjunto.size() - 1);
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

bool Grafo::existe_caminho_restrito(int v1, int v2, Aresta e, vector<int> marcado){

    if (v1 == v2){
        return true;
    }

    marcado[v1] = 1;

    for(auto j : vetores[v1]){
        if (marcado[j] == 0 && !((e.vertice1 == v1 && e.vertice2 == j) || (e.vertice2 == v1 && e.vertice1 == j))){
            if (existe_caminho_restrito(j, v2, e, marcado)){
                return true;
            }
        }
    }
    return false;
}

void Grafo::imprime_graus(){
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ": " << vetores[i].size();
        cout << endl;
    }
}