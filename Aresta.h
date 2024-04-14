#ifndef ARESTA_H
#define ARESTA_H

class Aresta {
public:
    Aresta(int vertice1, int vertice2);
    
    const int vertice1;
    const int vertice2;

private:
    int vertice1_;
    int vertice2_;
};

#endif /* ARESTA_H */