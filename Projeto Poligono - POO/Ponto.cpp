#include "Ponto.hpp"
#include <iostream>
#include <string>

using namespace std;

Ponto::Ponto(int vertX, int vertY){
    setVerticeX(vertX);
    setVerticeY(vertY);
    //cout << "\nCriando o ponto...\n";
}
Ponto::Ponto(){
    setVerticeX(0);
    setVerticeY(0);
}

Ponto::~Ponto(){
    //cout << "\nPonto nao existe mais!!!" << endl;
}

int Ponto::getVerticeX(){
    return verticeX;
}

void Ponto::setVerticeX(int vertX){
    verticeX = vertX;
}

int Ponto::getVerticeY(){
    return verticeY;
}

void Ponto::setVerticeY(int vertY){
    verticeY = vertY;
}

string Ponto::mostraPonto(){
    return " X: " + to_string(getVerticeX()) + ", Y: " + to_string(getVerticeY());
}

