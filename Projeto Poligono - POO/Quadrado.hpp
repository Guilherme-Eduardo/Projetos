#include <iostream>
#include <string>
#include "Reta.hpp"

using namespace std;

class Quadrado{
public:
    Quadrado(Ponto&, Ponto&, Ponto&,Ponto&);
    ~Quadrado();
    string mostraPontos();
    float calcPerimetro();
private:
    Ponto *p1;
    Ponto *p2;
    Ponto *p3;
    Ponto *p4;
};

