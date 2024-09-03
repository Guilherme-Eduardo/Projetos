#include "Poligono.hpp"
#include <iostream>
using namespace std;

Poligono::Poligono(vector<Ponto>pt){
    p=pt;
}
Poligono::~Poligono(){

}
void Poligono::adicionaPonto(Ponto novo_ponto){
    p.push_back(novo_ponto);
}

void Poligono::mostraPontos(){

    int tamanho = p.size();
    for(int i = 0; i < tamanho; ++i){
        cout << "Ponto " <<i<< p[i].mostraPonto() << endl;
    }
}

float Poligono::calcPerimetro(){
    float perimetro;
    int tamanho = p.size()-1;
    for(int i=0; i < tamanho; i++){
        Reta r(p[i],p[i+1]);
        perimetro += r.calcDistancia();
        if(i+1==tamanho){
            Reta r(p[i+1],p[0]);
            perimetro += r.calcDistancia();
        }
    }
    cout << "Perimetro: ";
    return perimetro;

}
