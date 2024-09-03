#include "Reta.hpp"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

Reta::Reta(Ponto &um, Ponto &dois){
    pontoUm = &um;
    pontoDois = &dois;
    //cout << "\nCriando a reta...\n";
}


Reta::~Reta(){
    //cout << "\nReta nao existe mais!!!" << endl;
}

string Reta::getPontoUm(){
    return pontoUm->mostraPonto();
}

string Reta::getPontoDois(){
    return pontoDois->mostraPonto();
}


string Reta::mostraPontos(){
    return "Ponto 1:" + pontoUm->mostraPonto() + "\nPonto 2:" + pontoDois->mostraPonto();
}
float Reta::calcDistancia(){

    return sqrt(pow(pontoDois->getVerticeX() - pontoUm->getVerticeX(),2) +pow(pontoDois->getVerticeY()- pontoUm->getVerticeY(),2));
}



