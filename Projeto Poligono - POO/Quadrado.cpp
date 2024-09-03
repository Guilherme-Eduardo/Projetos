#include <iostream>
#include <string>
#include "Quadrado.hpp"

using namespace std;

Quadrado::Quadrado(Ponto &um, Ponto &dois, Ponto &tres, Ponto &quatro){
    p1 = &um;
    p2 = &dois;
    p3 = &tres;
    p4 = &quatro;
}
Quadrado::~Quadrado(){
   /* delete p1;
    delete p2;
    delete p3;
    delete p4;*/

}
string Quadrado::mostraPontos(){
    return "Ponto 1" + p1->mostraPonto()+ "\nPonto 2" + p2->mostraPonto() +
            "\nPonto 3" + p3->mostraPonto() + "\nPonto 4" + p4->mostraPonto();

}
float Quadrado::calcPerimetro(){

    Reta r1(*p1,*p2);
    float lado1 = r1.calcDistancia();
    Reta r2(*p2,*p3);
    float lado2 = r2.calcDistancia();
    Reta r3(*p3,*p4);
    float lado3 = r3.calcDistancia();
    Reta r4(*p4,*p1);
    float lado4 = r4.calcDistancia();
    float somador= lado1 + lado2 + lado3 + lado4;

    /*float lado1 = sqrt(pow(p2->getVerticeX() - p1->getVerticeX(),2) +pow(p2->getVerticeY()- p1->getVerticeY(),2));
    float lado2 = sqrt(pow(p3->getVerticeX() - p2->getVerticeX(),2) +pow(p3->getVerticeY()- p2->getVerticeY(),2));
    float lado3 = sqrt(pow(p4->getVerticeX() - p3->getVerticeX(),2) +pow(p4->getVerticeY()- p3->getVerticeY(),2));
    float lado4 = sqrt(pow(p1->getVerticeX() - p4->getVerticeX(),2) +pow(p1->getVerticeY()- p4->getVerticeY(),2));
    float somador = lado1 + lado2 + lado3 + lado4;*/

    if(lado1==lado2 && lado2==lado3
        &&lado3==lado4&&lado4==lado1){
        cout << "É um quadrado congruente \nPerimetro:";
    }
    else{
        cout << "Nao é um quadrado congruente \nPerimetro:";
    }
    return somador;


}

