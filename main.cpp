// #include "Circulo.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        double raio;
        double dobro;
        double perimetro;
        int num_vertices = 4;

        Grafo g(num_vertices);

        cout << g.num_vertices() << endl;

        Aresta a(0,1);
        Aresta b(0,2);

        g.insere_aresta(a);
        g.insere_aresta(b);

        g.imprimir();

        // cout << "Digite o raio do circulo: ";
        // cin >> raio;
    
        // Circulo circulo(raio);
        // circulo.imprime_area();

        // Circulo circulo2(9);
        // circulo2.imprime_area();

        // dobro = circulo2.calcula_area() * 2;
        // cout << "Dobro da area: " << dobro << "\n";

        // perimetro = circulo2.calcula_perimetro();
        // cout << "Perimetro: " << perimetro << "\n";

    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
