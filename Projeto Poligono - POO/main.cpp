#include "Poligono.hpp"
#include "Quadrado.hpp"
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    char continua = 's';
    while(continua=='s'){
        int coordenada;
        int valor;
        cout << "SELECIONE AS SEGUINTES OPÇÕES\n1 - PONTO\n2 - RETA\n3 - QUADRADO\n4 - OUTRO POLIGONO\n";
        cin >> valor;

        if (valor == 1){
            Ponto p1;
            cout << "Informe a coordenada X:";
            cin >> coordenada;
            p1.setVerticeX(coordenada);
            cout << "Informe a Coordenada Y: ";
            cin >> coordenada;
            p1.setVerticeY(coordenada);
            cout << "Ponto criado: " << p1.mostraPonto()<< endl;
        }
        else if(valor == 2){

            vector<Ponto> pontos;
            for(int i=1; i <= 2; i++){
                int x,y;
                cout << "Informe a coordenada x do ponto " << i << " : ";
                cin >> x;
                cout << "Informe a coordenada y do ponto " << i << " : ";
                cin >> y;
                Ponto n(x,y);
                pontos.push_back(n);
            }
            system("clear");
            Reta r(pontos[0], pontos[1]);
            cout << r.mostraPontos() << endl;
            cout << "A distancia entre os pontos e de: " << r.calcDistancia() << endl;
        }
        else if (valor == 3){
            vector<Ponto>vetorPontos;
            for(int i=1; i <= 4; i++){
                int x,y;
                cout << "Informe a coordenada x do ponto " << i << " : ";
                cin >> x;
                cout << "Informe a coordenada y do ponto " << i << " : ";
                cin >> y;
                Ponto n1(x,y);
                vetorPontos.push_back(n1);
            }
            system("clear");
            Quadrado q(vetorPontos[0],vetorPontos[1],vetorPontos[2], vetorPontos[3]);
            cout << q.mostraPontos() << endl;
            cout << q.calcPerimetro() << endl;
        }


        else if(valor == 4){
            vector<Ponto>p;
            int x,y,lados=0;
            char acrescimo;
            while(lados<3){
                cout <<"Informar a quantidade de lados: ";
                cin >> lados;
            }

            for(int i=1; i <= lados; i++){

                cout << "Informe a coordenada x do ponto " << i << " : ";
                cin >> x;
                cout << "Informe a coordenada y do ponto " << i << " : ";
                cin >> y;
                Ponto n1(x,y);
                p.push_back(n1);
            }
            Poligono poligono (p);
            while(acrescimo!='n'|| acrescimo=='N'){
                poligono.mostraPontos();
                cout << poligono.calcPerimetro() << endl;
                cout << "Deseja acrescentar mais algum ponto? [s/n]: ";
                cin>>acrescimo;
                system("clear");
                if(acrescimo=='s'||acrescimo=='S'){
                    int x,y;
                    cout << "Informe a coordenada x do ponto: ";
                    cin >> x;
                    cout << "Informe a coordenada y do ponto: ";
                    cin >> y;
                    Ponto n1(x,y);
                    poligono.adicionaPonto(n1);
                }
            }
        }
        cout <<"Deseja retornar ao menu? [s/n]: " << endl;
        cin>> continua;
        system("clear");
}

    return 0;
}
