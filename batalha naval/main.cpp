//revisitando batalha naval
//preenchendo matrizes
//programa_015.cpp
#include "biblaureano.h"

const int LINHAS=15,
          COLUNAS=25;

string VAZIO=".",
       HIDRO="H",
       SUB="S",
       CRUZ="C",
       ENC="E",
       ESCONDE = "_",
       TIRO = "*",
       AGUA = "x",
       PORTA="P";

const int QTD_HIDRO=5,
          QTD_SUB=4,
          QTD_CRUZ=3,
          QTD_ENC=2,
          QTD_PORTA=1;

void preencheMatriz( string tabuleiro[LINHAS][COLUNAS]);
void imprimeMatrizJogador( string tabuleiro[LINHAS][COLUNAS], int xInicial);
void imprimeMatrizComputador( string tabuleiro[LINHAS][COLUNAS], int xInicial);
void preencheHidro(string tabuleiro[LINHAS][COLUNAS]);
void preencheSub(string tabuleiro[LINHAS][COLUNAS]);
void preencheCruz(string tabuleiro[LINHAS][COLUNAS]);
void preenchePorta(string tabuleiro[LINHAS][COLUNAS]);
void preencheEnc(string tabuleiro[LINHAS][COLUNAS]);
int darTiro(string tabuleiro[LINHAS][COLUNAS],int xInicial);
int tiroComputador(string tabuleiro[LINHAS][COLUNAS],int xInicial);
void instrucoes();


int main(){
    limparTela();
    mudaTamanhoTerminal(130,29);
    desligaCursor(true);
     int MeuHIDRO=0,
          meuSUB=0,
          meuCRUZ=0,
          meuENC=0,
          meuPORTA=0;


          int inimigoHIDRO=0,
          inimigoSUB=0,
          inimigoCRUZ=0,
          inimigoENC=0,
          inimigoPORTA=0;

          int meusBarcos = 0;
          int barcosInimigos = 0;

   string tabuleiroJogador[LINHAS][COLUNAS],
          tabuleiroComputador[LINHAS][COLUNAS];

   //zera a matriz
   preencheMatriz(tabuleiroJogador);
   preencheMatriz(tabuleiroComputador);

   //submarinos
   preencheSub(tabuleiroJogador);
   preencheSub(tabuleiroComputador);

   //cruzadores
   preencheCruz(tabuleiroJogador);
   preencheCruz(tabuleiroComputador);

   //encouraçados
   preencheEnc(tabuleiroJogador);
   preencheEnc(tabuleiroComputador);

   //porta-aviões
   preenchePorta(tabuleiroJogador);
   preenchePorta(tabuleiroComputador);

   //hidro-aviões
   preencheHidro(tabuleiroJogador);
   preencheHidro(tabuleiroComputador);

   imprimeMatrizJogador(tabuleiroJogador, 10);
   imprimeMatrizComputador(tabuleiroComputador, 40);
   instrucoes();

    while (true){
        imprimeMatrizJogador(tabuleiroJogador, 10);
        imprimeMatrizComputador(tabuleiroComputador, 40);

        meusBarcos += darTiro(tabuleiroComputador,10);
        barcosInimigos += tiroComputador(tabuleiroJogador,40);

        if (meusBarcos == 38){
            gotoXY(8,70);
            cout << "VOCE GANHOU" << endl;
            break;
        }
        if (barcosInimigos == 38){
            gotoXY(8,70);
            cout << "O COMPUTADOR VENCEU" << endl;
            break;
        }
    }

   cout << endl << "Game Over!!!" << endl;
   return 0;
}

void preencheMatriz( string tabuleiro[LINHAS][COLUNAS]){
   for( int i=0; i<LINHAS; ++i){
      for( int j=0; j<COLUNAS; ++j){
         tabuleiro[i][j]=VAZIO;
      }
   }
}

void imprimeMatrizComputador( string tabuleiro[LINHAS][COLUNAS], int xInicial){

   for( int i=0; i<LINHAS; ++i){
    int xc=xInicial;
    gotoXY(xInicial+1,0);
    mudaCor(RED);

    for(int i='A';i<='Y'; ++i){
          cout << (char)(i) << "  ";
       }


       // cout << alfabeto << endl;

      for( int j=0; j<COLUNAS; ++j){
            mudaCor(BLUE);

        gotoXY(xc,i+1); //lembrar que na tela é X=j, Y=i
        cout << " ";
        if (xInicial == 40){
            if( tabuleiro[i][j] == VAZIO){
                mudaCor(BLUE);
            }
            if ( tabuleiro[i][j] == TIRO){
                mudaCor(RED);
                cout << TIRO << endl;
            }
            else if(tabuleiro[i][j]=="x"){
                    mudaCor(BLUE);
                cout << "x" << endl;
            }
            else{
                cout << ESCONDE; //esco
            }
         }
         else{
            cout << tabuleiro[i][j];
         }
         xc+=3;
      }
      gotoXY(20,17),
      mudaCor(YELLOW);
      cout << "MEU CAMPO";
   }
   for(int y=1;y<16;y++){
    gotoXY(xInicial-2,y);
    cout << y -1 ;
   }
   limpaEfeito();
}

void imprimeMatrizJogador( string tabuleiro[LINHAS][COLUNAS], int xInicial){
   for( int i=0; i<LINHAS; ++i){
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    gotoXY(xInicial+1,0);
    mudaCor(YELLOW);
    cout << alfabeto << endl;
      for( int j=0; j<COLUNAS; ++j){
           mudaCor(BLUE);
         if( tabuleiro[i][j] == VAZIO){
            mudaCor(BLUE);
         }
         else if( tabuleiro[i][j] == SUB){
            mudaCor(YELLOW);
         }
         else if( tabuleiro[i][j] == HIDRO){
            mudaCor(GREEN);
         }
         else if( tabuleiro[i][j] == CRUZ){
            mudaCor(RED);
         }
         else if( tabuleiro[i][j] == ENC){
            mudaCor(CYAN);
         }
         else if( tabuleiro[i][j] == PORTA){
            mudaCor(PURPLE);
         }
         gotoXY(xInicial+j+1,i+1); //lembrar que na tela é X=j, Y=i
         cout << tabuleiro[i][j];
      }
   }
    gotoXY(45,17),
    mudaCor(RED);
    cout << "CAMPO ADVERSARIO";
   limpaEfeito();
}

//preencher de submarinos
void preencheSub(string tabuleiro[LINHAS][COLUNAS]){
   for( int qtd=0; qtd<QTD_SUB;++qtd){
      int i,j;
      do{
         i=randomico(0,LINHAS);
         j=randomico(0,COLUNAS);
      } while( tabuleiro[i][j] != VAZIO);
      tabuleiro[i][j] = SUB;
   }
}

//preencher porta-aviões
void preenchePorta(string tabuleiro[LINHAS][COLUNAS]){
   for( int qtd=0; qtd<QTD_PORTA;++qtd){
      int i,j;
      int sentido=randomico(0,2); //0 vertical, 1 horizontal;
      while(true){
         if( sentido == 0 ){
            i=randomico(0,LINHAS-5); //evitar de sortear última linha para não ultrapassar o limite
            j=randomico(0,COLUNAS);
            if( tabuleiro[i][j] == VAZIO &&
                tabuleiro[i+1][j] == VAZIO &&
                tabuleiro[i+2][j] == VAZIO &&
                tabuleiro[i+3][j] == VAZIO &&
                tabuleiro[i+4][j] == VAZIO){
               tabuleiro[i][j]=PORTA;
               tabuleiro[i+1][j]=PORTA;
               tabuleiro[i+2][j]=PORTA;
               tabuleiro[i+3][j]=PORTA;
               tabuleiro[i+4][j]=PORTA;
               break;
            }
         }
         else {
            i=randomico(0,LINHAS);
            j=randomico(0,COLUNAS-5); //evitar de sortear última coluna para não ultrapassar o limite

            if( tabuleiro[i][j] == VAZIO &&
                  tabuleiro[i][j+1] == VAZIO &&
                  tabuleiro[i][j+2] == VAZIO &&
                  tabuleiro[i][j+3] == VAZIO &&
                  tabuleiro[i][j+4] == VAZIO){
               tabuleiro[i][j]=PORTA;
               tabuleiro[i][j+1]=PORTA;
               tabuleiro[i][j+2]=PORTA;
               tabuleiro[i][j+3]=PORTA;
               tabuleiro[i][j+4]=PORTA;
               break;
            }
         }
      }
   }
}

//preencher encouraçado
void preencheEnc(string tabuleiro[LINHAS][COLUNAS]){
   for( int qtd=0; qtd<QTD_ENC;++qtd){
      int i,j;
      int sentido=randomico(0,2); //0 vertical, 1 horizontal;
      while(true){
         if( sentido == 0 ){
            i=randomico(0,LINHAS-4); //evitar de sortear última linha para não ultrapassar o limite
            j=randomico(0,COLUNAS);
            if( tabuleiro[i][j] == VAZIO &&
                tabuleiro[i+1][j] == VAZIO &&
                tabuleiro[i+2][j] == VAZIO &&
                tabuleiro[i+3][j] == VAZIO ){
               tabuleiro[i][j]=ENC;
               tabuleiro[i+1][j]=ENC;
               tabuleiro[i+2][j]=ENC;
               tabuleiro[i+3][j] = ENC;
               break;
            }
         }
         else {
            i=randomico(0,LINHAS);
            j=randomico(0,COLUNAS-4); //evitar de sortear última coluna para não ultrapassar o limite

            if( tabuleiro[i][j] == VAZIO &&
                  tabuleiro[i][j+1] == VAZIO &&
                  tabuleiro[i][j+2] == VAZIO &&
                  tabuleiro[i][j+3] == VAZIO ){
               tabuleiro[i][j] = ENC;
               tabuleiro[i][j+1] = ENC;
               tabuleiro[i][j+2] = ENC;
               tabuleiro[i][j+3] = ENC;
               break;
            }
         }
      }
   }
}

//preencher cruzadores
void preencheCruz(string tabuleiro[LINHAS][COLUNAS]){
   for( int qtd = 0; qtd<QTD_CRUZ;++qtd){
      int i,j;
      int sentido=randomico(0,2); //0 vertical, 1 horizontal;
      while(true){
         if( sentido == 0 ){
            i=randomico(0,LINHAS-1); //evitar de sortear última linha para não ultrapassar o limite
            j=randomico(0,COLUNAS);
            if( tabuleiro[i][j] == VAZIO &&
                tabuleiro[i+1][j] == VAZIO ){
               tabuleiro[i][j] = CRUZ;
               tabuleiro[i+1][j] = CRUZ;
               break;
            }
         }
         else {
            i=randomico(0,LINHAS);
            j=randomico(0,COLUNAS-1); //evitar de sortear última coluna para não ultrapassar o limite

            if( tabuleiro[i][j] == VAZIO &&
                  tabuleiro[i][j+1] == VAZIO){
               tabuleiro[i][j]=CRUZ;
               tabuleiro[i][j+1] = CRUZ;
               break;
            }
         }
      }
   }
}

//preencher de hidro-aviões
void preencheHidro(string tabuleiro[LINHAS][COLUNAS]) {
    for( int qtd=0; qtd<QTD_HIDRO; ++qtd) {
        int i,j;
        int sentido=randomico(0,4); //0 para cima, 1 para baixo, 2 esquerda, 3 direita

        while(true) {

            i=randomico(0,LINHAS-1); //evitar de sortear última linha para não ultrapassar o limite
            j=randomico(0,COLUNAS-1); //evitar de sortear última coluna e ultrapassar o limite
            if( sentido == 0) {
                if( j!=0 && //não existe -1
                        tabuleiro[i][j]     == VAZIO &&
                        tabuleiro[i+1][j-1] == VAZIO &&
                        tabuleiro[i+1][j+1] == VAZIO) {
                    tabuleiro[i][j]     = HIDRO;
                    tabuleiro[i+1][j-1] = HIDRO;
                    tabuleiro[i+1][j+1] = HIDRO;
                    break;
                }
            }
            else if( sentido == 1) {
                if( i!=0 && //não existe -1
                        tabuleiro[i][j]     == VAZIO &&
                        tabuleiro[i-1][j-1] == VAZIO &&
                        tabuleiro[i-1][j+1] == VAZIO) {
                    tabuleiro[i][j]     = HIDRO;
                    tabuleiro[i-1][j-1] = HIDRO;
                    tabuleiro[i-1][j+1] = HIDRO;
                    break;
                }
            }
            else if( sentido == 2) {
                if( j!=0 && i!=0 &&//não existe -1
                        tabuleiro[i][j]     == VAZIO &&
                        tabuleiro[i-1][j+1] == VAZIO &&
                        tabuleiro[i+1][j+1] == VAZIO) {
                    tabuleiro[i][j]     = HIDRO;
                    tabuleiro[i-1][j+1] = HIDRO;
                    tabuleiro[i+1][j+1] = HIDRO;
                    break;
                }
            }
            else {
                if( j!=0 && i!=0 &&//não existe -1
                        tabuleiro[i][j]     == VAZIO &&
                        tabuleiro[i-1][j-1] == VAZIO &&
                        tabuleiro[i+1][j-1] == VAZIO) {
                    tabuleiro[i][j]     = HIDRO;
                    tabuleiro[i-1][j-1] = HIDRO;
                    tabuleiro[i+1][j-1] = HIDRO;
                    break;
                }
            }
        }
    }
}
int darTiro(string tabuleiro[LINHAS][COLUNAS],int xInicial){


    int coordenadaX, coordenadaY;
    while (true){
        gotoXY(8,20);
        coordenadaX = readInt("INFORME UM VALOR PARA A LINHA: ");
        gotoXY(8,22);
        coordenadaY = readInt("INFORME UM VALOR PARA A COLUNA: ");

        if(tabuleiro[coordenadaX][coordenadaY]!= AGUA && tabuleiro[coordenadaX][coordenadaY]!= TIRO){
           break;
        }
        else{
            gotoXY(8,24);
            cout << " VALOR INVALIDO";
            espera(1000);
            limpaArea(8,20,50,30);
        }

    }
        gotoXY(70,2);
        if(tabuleiro[coordenadaX][coordenadaY] == SUB){
            cout << "ACERTOU UM SUBMARINO" << endl;
            espera(1500);
        }
        if (tabuleiro[coordenadaX][coordenadaY] == HIDRO){
            cout << "ACERTOU UM HIDRO" << endl;
            espera(1500);
        }
        if (tabuleiro[coordenadaX][coordenadaY] == PORTA){
            cout << "ACERTOU UM PORTA AVIOES" << endl;
            espera(1500);
        }
        if (tabuleiro[coordenadaX][coordenadaY] == CRUZ){
            cout << "ACERTOU UM CRUZ" << endl;
            espera(1500);
        }
        if (tabuleiro[coordenadaX][coordenadaY] == ENC){
            cout << "ACERTOU UM ENC";
            espera(1500);
        }

    limpaArea(8,20,50,30);
    limpaArea(70,2,100,5);
    if (tabuleiro[coordenadaX][coordenadaY]!= VAZIO){
           tabuleiro[coordenadaX][coordenadaY] = TIRO;
           return 1;

    }
    else if (tabuleiro[coordenadaX][coordenadaY] == VAZIO){
            tabuleiro[coordenadaX][coordenadaY] = AGUA;
            return 0;
    }

}

int tiroComputador(string tabuleiro[LINHAS][COLUNAS],int xInicial){
    int coordenadaX, coordenadaY;
    while (true){
        coordenadaX = randomico(0,LINHAS);
        coordenadaY = randomico(0,COLUNAS);

        if(tabuleiro[coordenadaX][coordenadaY]!= AGUA && tabuleiro[coordenadaX][coordenadaY]!= TIRO){
           break;
        }
    }

    if (tabuleiro[coordenadaX][coordenadaY] == VAZIO){
           tabuleiro[coordenadaX][coordenadaY] = AGUA;
           return 0;
    }
    else if (tabuleiro[coordenadaX][coordenadaY] != VAZIO ){
            tabuleiro[coordenadaX][coordenadaY] = TIRO;
            return 1;
    }
}
void instrucoes(){
    gotoXY(0,0);
    mudaCor(RED);
    cout << "COLUNAS:" << endl;
    cout << "A = 0" << endl;
    cout << "B = 1" << endl;
    cout << "C = 2" << endl;
    cout << "D = 3" << endl;
    cout << "E = 4" << endl;
    cout << "F = 5" << endl;
    cout << "G = 6" << endl;
    cout << "H = 7" << endl;
    cout << "I = 8" << endl;
    cout << "J = 9" << endl;
    cout << "K = 10" << endl;
    cout << "L = 11" << endl;
    cout << "M = 12" << endl;
    cout << "N = 13" << endl;
    cout << "O = 14" << endl;
    cout << "P = 15" << endl;
    cout << "Q = 16" << endl;
    cout << "R = 17" << endl;
    cout << "S = 18" << endl;
    cout << "T = 19" << endl;
    cout << "U = 20" << endl;
    cout << "V = 21" << endl;
    cout << "W = 22" << endl;
    cout << "X = 23" << endl;
    cout << "Y = 24" << endl;
}

