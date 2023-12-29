#include <iostream>
#include <limits>
#include <algorithm>
#include "biblaureano.h"

using namespace std;
//Funções e variavéis
int tentativas = 0;
char letra;
void menuInicial();
int telaDeDificuldades();
void ingame();

int main(){

    limparTela();
    setlocale(LC_ALL,"Portuguese");
    desligaCursor(true);
    mudaTamanhoTerminal(79,24);
    char novamente = 's';

    while(novamente == 's'){ //Condição para repetir o código
        menuInicial();
        telaDeDificuldades();
        ingame();
        espera(1000);
        gotoXY(5,18);
        novamente = readChar ("DESEJA JOGAR NOVAMENTE[s/n]: ");
        limparTela();
    }

return 0;
}

//Função tela menu principal.
void menuInicial(){
    string sTelaInicial = retornaConteudoArquivo( "telainicial.txt" );
    Imagem telaInicial( sTelaInicial,1,1 );

    while( letra != '1' && letra != '2' ){

        telaInicial.imprime();
        gotoXY(5,8);
        cout << "1. NOVO JOGO" << endl;
        gotoXY(5,9);
        cout  << "2. SAIR" << endl;

        if(verificaKB(letra)){

            if(letra == '1'){
                gotoXY (18,8);
                cout << "*" << endl;
                espera(1000);
                limparTela();
            }

            else if(letra == '2'){
                gotoXY(1,1);
                cout << "GAME OVER!!!" << endl;
                espera(2000);
                limparTela();
                exit(0);
            }
        }
    }
}

//Função sobre as opções de dificuldade / N° de tentativas.
int telaDeDificuldades(){
    string sTelaInicial = retornaConteudoArquivo( "telainicial.txt" );
    Imagem telaInicial( sTelaInicial,1,1 );
    while(true){
        telaInicial.imprime();
        gotoXY( 5,8 );
        cout << "DIFICULDADES: " << endl;
        gotoXY( 5,9 );
        cout << "1. NORMAL" << endl;
        gotoXY( 5,10 );
        cout << "2. TORMENTO" << endl;
        gotoXY( 5,11 );
        cout << "3. INFERNO" << endl;
        gotoXY( 5,12 );
        cout << "4. NIGHTMARE" << endl;

            if( verificaKB(letra)){
                if(letra == '1'){

                    gotoXY (17,9);
                    cout << "*" << endl;
                    tentativas = 6;
                    espera(1500);
                    limparTela();
                    break;
                }
                else if(letra == '2'){

                    gotoXY (17,10);
                    cout << "*" << endl;
                    tentativas = 4;
                    espera(1500);
                    limparTela();
                    break;
                }
                else if(letra == '3'){

                    gotoXY (17,11);
                    cout << "*" << endl;
                    tentativas = 2;
                    espera(1500);
                    limparTela();
                    break;
                }
                else if(letra == '4'){
                    gotoXY (17,12);
                    cout << "*" << endl;
                    tentativas = 1;
                    espera(1500);
                    limparTela();
                    break;
                }

            }
        }
    return tentativas; // retorna o número de tentativas.
}

void ingame(){
    //imagens utilizadas na tela.
    string sRepetida = retornaConteudoArquivo("repetida.txt");
    string sCabeca = retornaConteudoArquivo ("cabeca.txt");
    string sCabecaCorpo = retornaConteudoArquivo ("cabeca_corpo.txt");
    string sCabecaCorpoMembro = retornaConteudoArquivo ("cabeca_corpo_membro.txt");
    string sGameOver = retornaConteudoArquivo ("gameOver.txt");
    string sIngame = retornaConteudoArquivo ( "Ingame.txt" );
    Imagem ingame( sIngame, 1,5 );
    Imagem repetida (sRepetida,1,5);
    Imagem cabeca( sCabeca, 1,5);
    Imagem cabecaCorpo ( sCabecaCorpo, 1,5) ;
    Imagem cabecaCorpoMembro ( sCabecaCorpoMembro, 1,5);
    Imagem gameOver ( sGameOver, 1,5);
    string palavras = retornaConteudoArquivo("forca.txt"); // Arquivo com diversas palavras
    string secreta = palavraAleatoria(palavras);
    string acerto(secreta.size(), '_');
    string digitado = "";
    int erros = 0;

    //Condição para que o jogo permaneça executando.
    while (erros != tentativas && acerto != secreta){
        gotoXY(12,12);
             for(int posicao = 0; posicao < static_cast<int>(acerto.size()); posicao++) {
                cout << acerto[posicao] << " ";
            }
        gotoXY(5,8);
        cout << "TENTATIVAS: " << erros << " / " << tentativas<< endl;
        ingame.imprime();

        //Verifica a tecla digitada.
       if(verificaKB(letra)){

            //Condição para que incrementar as teclas ainda não digitadas e que não foram repetidas
            if(digitado.find(letra) == string::npos){
                digitado += letra; //incremento
                gotoXY(53,6);
                cout << "LETRAS JA USADAS: " << endl;
                gotoXY(52,8);
                for(int i = 0; i < static_cast<int>(digitado.size()); i++){
                    cout << digitado[i] << "-"; //Mostra na tela os caracteres selecionados até então.
                }
                //Condição para incrementar os erros.
                if (secreta.find(letra) == string::npos){
                    ++erros;

                    if (erros == 1){ //Imprime cabeça
                        cabeca.imprime();
                    }
                    else if ( erros == 2){ //Imprime tronco
                        cabecaCorpo.imprime();

                    }
                    else if ( erros == 4){ // Imprime cabeça e tronco
                        cabecaCorpoMembro.imprime();
                    }
                }

                //substitui o '_' pela letra digitada corretamente.
                for( int i = 0; i < static_cast<int>(acerto.size()); i++){
                    if(letra == secreta[i]){
                        acerto[i] = letra;
                    }
                }
            }
                //Detecta se o caracter já foi digitado
                else{
                    string repetida = "ATENCAO! ESTA LETRA JA FOI DIGITADA ";
                    gotoXY(5,18);
                    cout << repetida << endl; //Imprime a frase de atenção
                    espera(2000);
                    for(int i = 0; i < static_cast<int>(repetida.size()); i++){ // substitui por caracteres vazios
                        repetida[i] = ' ';
                    }
                    gotoXY(5,18);
                    cout << repetida << endl; //Imprime a frase apagada
                }
                gotoXY(12,12);
             for(int posicao = 0; posicao < static_cast<int>(acerto.size()); posicao++) {
                    cout << acerto[posicao] << " "; // imprime a palavra secreta na tela
                }
                gotoXY(5,8);
                cout << "TENTATIVAS: " << erros << " / " << tentativas<< endl; //Informa o número de tentativas
            }

        }
        //Condição de vitória
        if( acerto == secreta){
            gotoXY(5,17);
            cout << "PARABENS!!!!" << endl;
            espera(1000);
            cout << endl;
        }
        //condição de derrota.
        else if (erros == tentativas){
            gotoXY(5,17);
            cout << "GAME OVER !!!" << endl;
            gotoXY(5,18);
            cout << "A PALAVRA ERA: " << secreta << endl;
            gameOver.imprime();
            espera(2500);
            cout << endl;

        }
}
