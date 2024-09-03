#include "Ponto.hpp"
#pragma once
#include <math.h>

using namespace std;

class Reta{
    public:
        Reta(Ponto& , Ponto& );
        ~Reta();
        void setPontoUm(Ponto);
        string getPontoUm();
        void setPontoDois(Ponto);
        string getPontoDois();
        string mostraPontos();
        float calcDistancia();

    private:
        Ponto *pontoUm;
        Ponto *pontoDois;

};

