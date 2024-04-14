#include "Aresta.h"
#include <iostream>

using namespace std;

Aresta::Aresta(int vertice1, int vertice2) : vertice1(vertice1), vertice2(vertice2) {
    if (vertice1 < 0 || vertice2 < 0) {
        throw(invalid_argument("Erro no construtor Aresta(int, int): os vertices " +
            to_string(vertice1) + " e " + to_string(vertice2) + " sao invalidos!"));
    }
}  