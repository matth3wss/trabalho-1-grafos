// #include "Circulo.h"
#include "Grafo.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitString(const string& input) {
    istringstream iss(input);
    vector<string> tokens;
    string token;
    while (getline(iss, token, ' ')) { // ' ' is the delimiter
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string input;
    string line;
    getline(cin, input);

    vector<string> tokens = splitString(input);

    int num_vertices = stoi(tokens[0]);
    int num_operacoes = stoi(tokens[1]);

    Grafo g(num_vertices);

    for (int i = 0; i < num_operacoes; i++) {
        getline(cin, line);
        vector<string> operacao = splitString(line);
        string opcao = operacao[0];

        if (opcao == "I") {
            Aresta a(stoi(operacao[1]), stoi(operacao[2]));
            g.insere_aresta(a);
            continue;

        } else if (opcao == "R") {
            Aresta a(stoi(operacao[1]), stoi(operacao[2]));
            g.remove_aresta(a);
            continue;

        } else if (opcao == "E") {
            cout << g.num_arestas() << endl;
            continue;

        } else if (opcao == "Q") {
            vector<int> vetor;
            for(int i = 2; i < operacao.size(); i++){
                vetor.push_back(stoi(operacao[i]));
            }
            if (g.eh_clique(vetor)) {
                cout << "SIM" << endl;
            } else {
                cout << "NAO" << endl;
            }
            continue;

        } else if (opcao == "C") {
            if (g.existe_caminho_restrito(stoi(operacao[1]), stoi(operacao[2]), Aresta(stoi(operacao[3]), stoi(operacao[4])), vector<int>(g.num_vertices()))) {
                cout << "SIM" << endl;
            } else {
                cout << "NAO" << endl;
            }

        }else if (opcao == "G") {
            g.imprime_graus();
            continue;
        }
    }

    return 0;
}
