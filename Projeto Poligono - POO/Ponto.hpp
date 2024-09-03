#include<string>
#include <iostream>
#pragma once
using namespace std;

class Ponto{
    public:
        Ponto(int, int);
        Ponto();
        ~Ponto();

        string mostraPonto();

        void setVerticeY(int);
        int getVerticeY();

        void setVerticeX(int);
        int getVerticeX();

    private:
        int verticeY;
        int verticeX;
};

