#include <string>
#include <iostream>
#include <vector>
#include "Reta.hpp"

using namespace std;

class Poligono{
public:
    Poligono(vector<Ponto>);
    ~Poligono();
    void adicionaPonto(Ponto);
    void mostraPontos();
    float calcPerimetro();
private:
    vector<Ponto>p;
};
