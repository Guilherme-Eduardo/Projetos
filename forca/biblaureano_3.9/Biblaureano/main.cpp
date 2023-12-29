/**
    \section LICENÇA
    Biblaureano: biblioteca para o auxílio no desenvolvimento de jogos.

    Copyright (C) 2011-2013 Marcos Laureano, Gabriel Candido e Thiago Romano

    Este arquivo é parte do programa Biblaureano.

    Biblaureano é um software livre; você pode redistribui-lo e/ou
    modifica-lo dentro dos termos da Licença Pública Geral GNU como
    publicada pela Fundação do Software Livre (FSF); na versão 2 da
    Licença, ou (na sua opnião) qualquer versão.

    Este programa é distribuido na esperança que possa ser  util,
    mas SEM NENHUMA GARANTIA; sem uma garantia implicita de ADEQUAÇÂO a qualquer
    MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
    Licença Pública Geral GNU para maiores detalhes.

    Você deve ter recebido uma cópia da Licença Pública Geral GNU
    junto com este programa, se não, escreva para a Fundação do Software
    Livre(FSF) Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
* @file main.cpp
* @author Marcos Laureano <marcos.laureano@ifpr.edu.br>
* @author Gabriel Candido <gabiru.vinicius@gmail.com>
* @author Thiago Romano
* \brief Biblioteca para auxiliar os alunos no decorrer dos cursos tecnicos em Informatica e em Programacao de Jogos Digitais do IFPR - Campus Salgado Filho.
*/

#include "biblaureano.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <iostream>

#elif defined (unix)
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits> //para limpar o buffer
#include <fstream>
#include <ctime>
#include <string.h>
#include <stdlib.h>

#endif

using namespace std;

//Classe Ponto
//Construtores
/** \brief Construtor da classe Ponto usando argumentos de coordenadas e caracter
* Inicializa uma nova instância da classe Ponto.
* \param[in] _x Coordenada horizontal do ponto.
* \param[in] _y Coordenada vertical do ponto.
* \param[in] _caracter Caractere do ponto.
* @see Ponto::Ponto(int _x, int _y, string _caracter, COR _corFrente)
* @see Ponto::Ponto(int _x, int _y, string _caracter, COR _corFrente, COR _corFundo)
*/
Ponto::Ponto(int _x, int _y, string _caracter)
{
   corFrente = corFundo = QTY_COR;
   x = _x;
   y = _y;
   caractere = _caracter;
}
/** \brief Construtor da classe Ponto usando argumentos de coordenadas, caracter e cor
* Inicializa uma nova instância da classe Ponto.
* \param[in] _x Coordenada horizontal do ponto.
* \param[in] _y Coordenada vertical do ponto.
* \param[in] _caracter Caractere que será impresso naquele ponto.
* \param[in] _corFrente Cor do texto daquele ponto. Pode ser omitido.
* @see Ponto::Ponto(int _x, int _y, string _caracter)
* @see Ponto::Ponto(int _x, int _y, string _caracter, COR _corFrente, COR _corFundo)
*/
Ponto::Ponto(int _x, int _y, string _caracter, COR _corFrente)
{
   corFundo = QTY_COR;
   corFrente = _corFrente;
   x = _x;
   y = _y;
   caractere = _caracter;
}
/** \brief Construtor da classe Ponto usando argumentos de coordenadas, caracter e cor
* Inicializa uma nova instância da classe Ponto.
* \param[in] _x Coordenada horizontal do ponto.
* \param[in] _y Coordenada vertical do ponto.
* \param[in] _caracter Caractere que será impresso naquele ponto.
* \param[in] _corFrente Cor do texto daquele ponto. Pode ser omitido.
* \param[in] _corFundo Cor do fundo do ponto. Pode ser omitido.
* @see Ponto::Ponto(int _x, int _y, string _caracter)
* @see Ponto::Ponto(int _x, int _y, string _caracter, COR _corFrente)
*/
Ponto::Ponto(int _x, int _y, string _caracter, COR _corFrente, COR _corFundo)
{
   corFundo = _corFundo;
   corFrente = _corFrente;
   x = _x;
   y = _y;
   caractere = _caracter;
}

//Gets e Sets
/** \brief Retorna o valor da coordenada X do ponto.
* @return Um inteiro com a coordenada X do ponto.
*/
int Ponto::getX(){return x;}
/** \brief Retorna o valor da coordenada Y do ponto.
* @return Um inteiro com a coordenada Y do ponto.
*/
int Ponto::getY(){return y;}
/** \brief Retorna a cor do texto do ponto.
* @return Um valor do tipo COR com a cor do texto.
*/
COR Ponto::getCor(){return corFrente;}
/** \brief Retorna a cor do fundo do ponto.
* @return Um valor do tipo COR com a cor do fundo do ponto.
*/
COR Ponto::getCorFundo(){return corFundo;}
/** \brief Retorna o caractere daquele ponto.
* @return Um a string contendo o caractere do ponto.
*/
string Ponto::getChar(){return caractere;}
/** \brief Altera a cor do texto daquele ponto.
* \param[in] _corFrente Variável do tipo COR contendo a nova cor do ponto.
* @see Ponto::setCor(COR _corFrente, COR _corFundo)
* @see Ponto::colore()
*/
void Ponto::setCor(COR _corFrente){corFrente = _corFrente;}
/** \brief Altera a cor do texto e do fundo daquele ponto.
* \param[in] _corFrente Variável do tipo COR contendo a nova cor do ponto.
* \param[in] _corFundo Variável do tipo COR contendo a nova cor de fundo do ponto.
* @see Ponto::setCor(COR _corFrente)
* @see Ponto::colore()
*/
void Ponto::setCor(COR _corFrente, COR _corFundo)
{
   corFrente = _corFrente;
   corFundo = _corFundo;
}

/** \brief Atualiza a cor do ponto.
* Só atualiza se a cor foi alterada anteriormente pelos métodos setCor(COR _corFrente) ou setCor(COR _corFrente, COR _corFundo)
* @see Ponto::setCor(COR _corFrente)
* @see Ponto::setCor(COR _corFrente, COR _corFundo)
*/
void Ponto::colore()
{
   if(corFrente != QTY_COR && corFundo != QTY_COR)
      mudaCor(corFrente, corFundo);
   else if(corFrente != QTY_COR)
      mudaCor(corFrente);
}
/** \brief Limpa a área em que o ponto foi impressa.
* \param[in] _x Coordenada X de início do sprite. Caso seja omitido o valor padrão é 0.
* \param[in] _y Coordenada Y de início do sprite. Caso seja omitido o valor padrão é 0.
* @remarks Os parâmetros são usados no caso de haver vários pontos, dessa forma, informando _x e _y, a função calcula o deslocamento que deve fazer para apagar o local correto.
*/
void Ponto::limpa(int _x, int _y)
{
    gotoXY(_x + x, _y + y);
    cout << " ";
    cout.flush();
}

/** \brief Imprime o ponto na tela.
* \param[in] _x Coordenada X de inicio do sprite. Caso seja omitido o valor padrão é 0.
* \param[in] _y Coordenada Y de início do sprite. Caso seja omitido o valor padrão é 0.
* @remarks Os parâmetros são usados no caso de haver vários pontos, dessa forma, informando _x e _y, a função calcula o deslocamento que o ponto deve sofrer para ser impresso no local correto.
*/
void Ponto::imprime(int _x, int _y)
{
    colore();
    gotoXY(_x + x, _y + y);
    cout << caractere;
    cout.flush();
    limpaEfeito();
    return;
}

//Classe Imagem
//Construtores
/** \brief Construtor da classe Imagem sem argumentos
*/
Imagem::Imagem()
{
    x = 0;
    y = 0;
    altura = 0;
    largura = 0;
    xMin = 0;
    yMin = 0;
    xMax = 0;
    yMax = 0;
}
/** \brief Construtor da classe Imagem usando como argumento uma string com o sprite.
* Inicializa uma nova instância da classe Imagem.
* \param[in] _sprite Sprite que forma a imagem.
* @see Imagem::Imagem(string _sprite, int _x, int _y)
*/
Imagem::Imagem(string _sprite)
{
   int posicao = -1;
   int inicial = 0;
   int lY = 0;
   int maiorX = 0;
   if(_sprite.find("\n") == string::npos) _sprite += "\n";
   while((posicao = _sprite.find("\n", posicao + 1)) != string::npos){
      string linha = _sprite.substr(inicial, posicao - inicial);
      int lX = 0;
      for(int i = 0; i < linha.size(); ++i){
         if(linha[i] != ' ' && linha[i] != '\n')
         {
            string c(1, linha[i]);
            Ponto p(lX, lY, c);
            pontos.push_back(p);
         }
         ++lX;
      }
      if(lX > maiorX)
         maiorX = lX;

      inicial = posicao + 1;
      ++lY;
   }
   altura = lY;
   largura = maiorX;

}

/** \brief Construtor da classe Imagem usando como argumentos uma string com o sprite e as coordenadas da imagem.
* Inicializa uma nova instância da classe Imagem.
* \param[in] _sprite Sprite que forma a imagem.
* \param[in] _x Coordenada X de início da imagem.
* \param[in] _y Coordenada Y de início da imagem.
* @see Imagem::Imagem(string _sprite)
*/
Imagem::Imagem(string _sprite, int _x, int _y)
{
   x = _x;
   y = _y;
   int posicao = -1;
   int inicial = 0;
   int lY = 0;
   int maiorX = 0;
   if(_sprite.find("\n") == string::npos) _sprite += "\n";
   while((posicao = _sprite.find("\n", posicao + 1)) != string::npos){
      string linha = _sprite.substr(inicial, posicao - inicial);
      int lX = 0;
      for(int i = 0; i < linha.size(); ++i){
         if(linha[i] != ' ' && linha[i] != '\n')
         {
            string c(1, linha[i]);
            Ponto p(lX, lY, c);
            pontos.push_back(p);
         }
         ++lX;
      }
      if(lX > maiorX)
         maiorX = lX;

      inicial = posicao + 1;
      ++lY;
   }
   altura = lY;
   largura = maiorX;
}

//Gets e Sets
/** \brief Retorna a coordenada horizontal da imagem.
* @return Um inteiro com a coordenada X da imagem.
*/
int Imagem::getX(){return x;}
/** \brief Retorna a coordenada vertical da imagem.
* @return Um inteiro com a coordenada Y da imagem.
*/
int Imagem::getY(){return y;}
/** \brief Altera a coordenada horizontal da imagem.
* \param[in] _x Um inteiro com a nova coordenada X da imagem.
*/
void Imagem::setX(int _x){x = _x;}
/** \brief Retorna a coordenada vertical da imagem.
* \param[in] _y Um inteiro com a coordenada Y da imagem.
*/
void Imagem::setY(int _y){y = _y;}
/** \brief Retorna os pontos da imagem.
* @return Um vetor de Pontos que formam o sprite.
*/
vector<Ponto> Imagem::getPontos(){return pontos;}
/** \brief Altera a imagem
* \param[in] _pontos Vetor com os novos pontos da imagem.
*/
void Imagem::setPontos(vector<Ponto> _pontos){pontos = _pontos;}

/** \brief Aumenta a coordena horizontal da imagem em um.*/
int Imagem::incrementaX(){
   if((x + 1) <= xMax) ++x;
   return x;
}
/** \brief Aumenta a coordena vertical da imagem em um.*/
int Imagem::incrementaY(){
   if((y + 1) <= yMax) ++y;
   return y;
}
/** \brief Diminui a coordena horizontal da imagem em um.*/
int Imagem::decrementaX(){
   if((x - 1) >= xMin) --x;
   return x;
}
/** \brief Diminui a coordena vertical da imagem em um.*/
int Imagem::decrementaY(){
   if((y - 1) >= yMin) --y;
   return y;
}

/** \brief Seta as coordenadas limites que a imagem pode ter.
* \param[in] _xMin Coordenada mínima no eixo X da imagem. Determina o quão à esquerda a imagem pode ficar.
* \param[in] _yMin Coordenada mínima no eixo Y da imagem. Determina o quão para cima a imagem pode ficar.
* \param[in] _xMax Coordenada máxima no eixo X da imagem. Determina o quão à direita a imagem pode ficar.
* \param[in] _yMax Coordenada máxima no eixo Y da imagem. Determina o quão para baixo a imagem pode ficar.
*/
void Imagem::setLimites(int _xMin, int _yMin, int _xMax, int _yMax)
{
   xMin = _xMin;
   yMin = _yMin;
   xMax = _xMax,
   yMax = _yMax;
   return;
}

/** \brief Verifica em qual coluna houve colisão.
* \param[in] _i Imagem com a qual será feito o teste de colisão
* @return -1 se não houve colisão, caso contrário retorna a posição no eixo X em que houve a mesma.
*/
int Imagem::getColisaoX(Imagem _i)
{
    vector<Ponto> imagemPontos = _i.getPontos();
    int _ix = _i.getX();
    int _iy = _i.getY();
    for(int i = 0; i < pontos.size(); ++i)
    {
       for(int j = 0; j < imagemPontos.size(); ++j)
       {
          if((getX() + pontos[i].getX()) == (_ix + imagemPontos[j].getX()) &&
             (getY() + pontos[i].getY()) == (_iy + imagemPontos[j].getY()))
          {
             return getX() + pontos[i].getX();
          }
       }
    }
    return -1;
}

/** \brief Verifica em qual linha houve colisão.
* \param[in] _i Imagem com a qual será feito o teste de colisão
* @return -1 se não houve colisão, caso contrário retorna a posição no eixo Y em que houve a mesma.
*/
int Imagem::getColisaoY(Imagem _i)
{
    vector<Ponto> imagemPontos = _i.getPontos();
    int _ix = _i.getX();
    int _iy = _i.getY();
    for(int i = 0; i < pontos.size(); ++i)
    {
       for(int j = 0; j < imagemPontos.size(); ++j)
       {
          if((getX() + pontos[i].getX()) == (_ix+imagemPontos[j].getX()) &&
             (getY() + pontos[i].getY()) == (_iy+imagemPontos[j].getY()))
          {
             return getY() + pontos[i].getY();
          }
       }
    }
    return -1;
}

/** \brief Altera as coordenadas da imagem e a imprime no novo posicionamento.
* \param[in] _x Nova coordenada horizontal da imagem.
* \param[in] _y Nova coordenada vertical da imagem.
* @see Imagem::imprime()
*/
void Imagem::imprime(int _x, int _y)
{
   x = _x;
   y = _y;
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].imprime(_x, _y);
   }
   gotoXY(1, 1);
   return;
}
/** \brief Imprime a imagem na sua posicao atual.
* @see Imagem::imprime(int _x, int _y)
*/
void Imagem::imprime()
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].imprime(x, y);
   }
   gotoXY(1, 1);
   return;
}

/** \brief Muda a cor da imagem.
* \param[in] _corFrente Nova cor do texto da imagem.
* @see Imagem::mudaCor(COR _corFrente, COR _corFundo)
*/
void Imagem::mudaCor(COR _corFrente)
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].setCor(_corFrente);
   }
   return;
}
/** \brief Muda a cor da imagem.
* \param[in] _corFrente Nova cor do texto da imagem.
* \param[in] _corFundo Nova cor do fundo da imagem.
* @see Imagem::mudaCor(COR _corFrente)
*/
void Imagem::mudaCor(COR _corFrente, COR _corFundo)
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].setCor(_corFrente, _corFundo);
   }
   return;
}

/** \brief Muda a cor da imagem.
* \param[in] _codigoLetra Nova cor do texto da imagem.
* @see Imagem::mudaCor(COR _corFrente)
*/
void Imagem::mudaCor255(int _codigoLetra)
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].setCor((COR)_codigoLetra);
   }
}

/** \brief Muda a cor da imagem.
* \param[in] _codigoLetra Nova cor do texto da imagem.
* \param[in] _codigoFundo Nova cor do fundo da imagem.
* @see Imagem::mudaCor(COR _corFrente, COR _corFundo)
* @remarks No Windows o argumento _codigoFundo é ignorado
*/
void Imagem::mudaCor255(int _codigoLetra, int _codigoFundo)
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      #if defined (_WIN32)
      pontos[i].setCor((COR)_codigoLetra);
      #elif defined (unix)
      pontos[i].setCor((COR)_codigoLetra, (COR)_codigoFundo);
      #endif
   }
}

/** \brief Apaga a imagem da tela.
* @see Imagem::limpa(int _x, int _y)
*/
void Imagem::limpa()
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].limpa(x, y);
   }
   return;
}
/** \brief Apaga a imagem conforme as novas coordenadas.
* \param[in] _x Nova coordenada horizontal.
* \param[in] _y Nova coordenada vertical.
* @see Imagem::limpa()
*/
void Imagem::limpa(int _x, int _y)
{
   for(int i = 0; i < pontos.size(); ++i)
   {
      pontos[i].limpa(_x, _y);
   }
   return;
}

/** \brief Verifica se houve colisão de imagens.
* \param[in] _i Imagem com a qual será feito o teste de colisão.
* @return true se houve colisão e false caso contrário.
* @see Imagem::colisao(Imagem _i, int _x1, int _y1, int _x2, int _y2)
*/
bool Imagem::colisao(Imagem _i)
{
    vector<Ponto> imagemPontos = _i.getPontos();
    int ix = _i.getX();
    int iy = _i.getY();
    for(int i = 0; i < pontos.size(); ++i)
    {
       for(int j = 0; j < imagemPontos.size(); ++j)
       {
          if((getX() + pontos[i].getX()) == (ix + imagemPontos[j].getX()) &&
             (getY() + pontos[i].getY()) == (iy + imagemPontos[j].getY()))
          {
             return true;
          }
       }
    }
    return false;
}

//coordenadas da 1 imagem e coordenadas da 2 imagem
/** \brief Verifica se houve colisão de imagens.
* \param[in] _i Imagem com a qual será feito o teste de colisão.
* \param[in] _x1 Coordenada horizontal da primeira imagem.
* \param[in] _y1 Coordenada vertical da primeira imagem.
* \param[in] _x2 Coordenada horizontal da segunda imagem.
* \param[in] _y2 Coordenada vertical da segunda imagem.
* @return true se houve colisão e false caso contrário.
* @see Imagem::colisao(Imagem _i)
*/
bool Imagem::colisao(Imagem _i, int _x1, int _y1, int _x2, int _y2)
{
    vector<Ponto> imagemPontos = _i.getPontos();
    for(int i = 0; i < pontos.size(); ++i)
    {
       for(int j = 0; j < imagemPontos.size(); ++j)
       {
          if((_x1 + pontos[i].getX()) == (_x2 + imagemPontos[j].getX()) &&
             (_y1 + pontos[i].getY()) == (_y2 + imagemPontos[j].getY()))
          {
             return true;
          }
       }
    }
    return false;
}

/** \brief Retorna a altura da imagem
* @return Altura da imagem
*/
int Imagem::getAltura(){return altura;}

/** \brief Retorna a largura da imagem
* @return Largura da imagem
*/
int Imagem::getLargura(){return largura;}

/** \brief Muda a cor do texto.
* Altera a cor de qualquer texto que venha depois da chamada dessa funcao, a nao ser que ela seja chamada novamente ou os efeitos de cor sejam limpados.
* @param[in] _corLetra Cor desejada para o texto, de acordo com o enumerador COR.
* @see mudaCor(COR _corLetra, COR _corFundo)
* @see limpaEfeito()
*/
void mudaCor(COR _corLetra)
{
   #if defined (_WIN32)
   static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //handle para o output
   int colorAttribute = 0;
   colorAttribute = (colorAttribute << 4) | _corLetra | 8; //15 para acender bits de intensidade
   SetConsoleTextAttribute(handle, colorAttribute); //seta atributos do texto para handle com colorAttribute caracteristicas
   #elif defined (unix)
   string cor = "\033[;03"; //3x seta texto
   cor += numeroToString(_corLetra) + "m";
   cout << "\033[;0m"; //\033->ESC  [-> CSI, control sequenco introduce, ECMA-48, m-> seta display
    //zero reseta os parametros
   cout << cor; //seta parametros
   #endif
   return;
}

/** \brief Muda a cor do texto e do fundo.
* Altera a cor de qualquer texto e fundo que venham depois da chamada dessa funcao, a nao ser que ela seja chamada novamente ou os efeitos de cor sejam limpados.
* @param[in] _corLetra Cor desejada para o texto, de acordo com o enumerador COR.
* @param[in] _corFundo Cor desejada para o fundo, de acordo com o enumerador COR.
* @see mudaCor(COR _corLetra)
* @see limpaEfeito()
*/
void mudaCor(COR _corLetra, COR _corFundo)
{
   #if defined (_WIN32)
   static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
   int colorAttribute = _corFundo;
   colorAttribute = (colorAttribute << 4) | _corLetra | 136; //136 para acender bits de intensidade
    //8 ultimos bits-> texto, 0000 0000
                  //fundo texto
   SetConsoleTextAttribute(handle, colorAttribute);
   #elif defined (unix)
   string cor = "\033[4"; //4x seta fundo
   cor += numeroToString(_corFundo) + ";03" + numeroToString(_corLetra) + "m";//3x seta texto
   cout << "\033[;0m"; //reseta
   cout << cor; //seta
   #endif
   return;
}

/** \brief Muda a cor do texto.
* Altera a cor de qualquer texto que venham depois da chamada dessa função, a não ser que ela seja chamada novamente ou os efeitos de cor sejam limpados.
* @param[in] _codigo Inteiro de 0 a 255 que representa uma cor.
* @see mudaCor(COR _corLetra);
* @see limpaEfeito();
* @remarks No Windows o argumento _codigo representa uma combinação de cores para letra e fundo, alterando não somente a cor do texto.
*/
void mudaCor255(int _codigo)
{
   #if defined (_WIN32)
   mudaCor(COR(_codigo));

   #elif defined (unix)
   string cor = "\033[38;5;" + numeroToString(_codigo) + "m";
   cout << "\033[;0m";
   cout << cor;
   #endif
}

/** \brief Muda a cor do texto e do fundo.
* Altera a cor de qualquer texto e do fundo que venham depois da chamada dessa função, a não ser que ela seja chamada novamente ou os efeitos de cor sejam limpados.
* @param[in] _codigoLetra Inteiro de 0 a 255 que representa uma cor.
* @param[in] _codigoFundo Inteiro de 0 a 255 que representa uma cor.
* @see mudaCor(COR _corLetra, COR _corFundo);
* @see limpaEfeito();
* @remarks No Windows o argumento _codigoLetra representa uma combinação de cores para letra e fundo, alterando não somente a cor do texto e o argumento _codigoFundo é ignorado.
*/
void mudaCor255(int _codigoLetra, int _codigoFundo)
{
   #if defined (_WIN32)
   mudaCor(COR(_codigoLetra));

   #elif defined (unix)
   string cor = "\033[38;5;" + numeroToString(_codigoLetra) + ";48;5;" + numeroToString(_codigoFundo) + "m";
   cout << "\033[;0m";
   cout << cor;
   #endif
}

/** \brief Limpa efeitos do texto.
* Reseta qualquer alteracao da cor do texto e fundo, feitas anteriormente pelas funcoes mudaCor().
* @see mudaCor(COR _corLetra, COR _corFundo)
* @see mudaCor(COR _corLetra)
*/
void limpaEfeito()
{
    #if defined (_WIN32)
    static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 15); //15=fundo preto(0000) texto branco(1111)
    #elif defined (unix)
    cout << "\033[;0m"; //reseta
    #endif
    return;
}

/** \brief Verifica se alguma tecla foi pressionada.
* Nao para a execucao de um programa, pois nao aguarda uma operacao de I/O.
* @see getch()
* @see verificaKB(char& _tecla)
* @return True se qualquer tecla foi pressionada, caso contrário retorna false.
*/
int kbhit()
{
   #if defined (_WIN32)
   return _kbhit();
   #elif defined (unix)
   struct termios oldTerminal, newTerminal;
   int ch;
   int oldFile;
   tcgetattr(STDIN_FILENO, &oldTerminal); //pega atributos da STDIN_FILENO e coloca na oldt
   newTerminal = oldTerminal;
   newTerminal.c_lflag &= ~(ICANON | ECHO); //desabilita echo e canonical mode

   tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal); //seta newt na STDIN_FILENO agora(TCSANOW)

   oldFile = fcntl(STDIN_FILENO, F_GETFL, 0); //fcntl manipulacao de descriptors de arquivos
         //F_GETFL pega as flags de STDIN_FILENO, zero pois F_GETFL é void
   fcntl(STDIN_FILENO, F_SETFL, oldFile | O_NONBLOCK);
      //F_SETFL seta as flags do terceiro argumento em STDIN_FILENO
      //O_NONBLOCK nao deixa as slow system calls(no caso read) travar o I/O esperando uma entrada

   ch = getchar(); //le o prox char da stdin

   tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal); //seta antigo
   fcntl(STDIN_FILENO, F_SETFL, oldFile); //seta antigo

   if(ch != EOF)
   {
      ungetc(ch, stdin); //coloca ch de volta na stdin
      return 1;
   }
   return 0;
   #endif
}

/** \brief Verifica se alguma tecla foi pressionada.
* Espera por uma operacao de I/O, parando o programa.
* @see kbhit()
* @see verificaKB(char& tecla)
* @return A tecla pressionada.
*/
int getch()
{
   #if defined (_WIN32)
   return _getch();
   #elif defined (unix)
   struct termios oldTerminal, newTerminal;
   int ch;
   tcgetattr(STDIN_FILENO, &oldTerminal); //pega atts da STDIN_FILENO
   newTerminal = oldTerminal;
   newTerminal.c_lflag &= ~(ICANON | ECHO); //desabilita echo e canonical mode
   tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal); //seta agora
   ch = getchar(); //le char
   tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal); //seta antigo
   return ch;
   #endif
}

/** \brief Verifica se alguma tecla foi pressionada.
* Para a execução do programa. Útil quando você deve esperar que o usário digite algo, economizando processamento.
* @param[out] _tecla Tecla pressionada. Caso nenhuma tecla for pressionada seu valor nao e alterado.
* @see getch()
* @see kbhit()
* @return true se alguma tecla foi pressionada ou false, caso contrário.
*/
int verificaKB(char& _tecla)
{
   #if defined (_WIN32)
   _tecla = _getch();
   return 1;

   #elif defined (unix)

   struct termios oldTerminal;
   struct termios newTerminal;

   tcgetattr(STDIN_FILENO, &oldTerminal); //pega atts STDIN_FILENO
   newTerminal = oldTerminal;
   newTerminal.c_lflag &= ~(ICANON | ECHO); //desabilita echo e canonical mode
   tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal); //seta agora
   _tecla = getchar(); //le char
   tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal); //seta antigo

   if (_tecla == END_FILE_CHARACTER)
   {
      _tecla = EOF;
   }
   return _tecla != EOF; //EOF==0, entao retorna true
   #endif
}

/** \brief Limpa a tela.*/
void limparTela()
{
   #if defined (_WIN32)
   system("cls");
   #elif defined (unix)
   cout << "\033[2J\033[0;0f"; //2J apaga tela, o;of posiciona cursor na linha 0; coluna 0
   #endif
   return;
}

/** \brief Seta a posicao do cursor do teclado.
* @param[in] _x Posicao do cursor no eixo X (coluna).
* @param[in] _y Posicao do cursor no eixo Y (linha).
*/
void gotoXY(int _x, int _y)
{
    #if defined (_WIN32)
    COORD coord; //struct de coordenadas
    coord.X = _x; //altera coords
    coord.Y = _y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //seta coordenadas
    #elif defined (unix)
    cout << "\033[" << _y << ";" << _x << "f"; //f posiciona
    cout.flush();
    #endif
}

/** \brief Altera a visibilidade do cursor do teclado.
* @param[in] _liga Se true, seta o cursor como invisivel, se false, seta como visível.
*/
void desligaCursor(bool _liga)
{
   #if defined (_WIN32)
   HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO cursor;
   GetConsoleCursorInfo(output, &cursor);
   cursor.bVisible = !_liga;
   SetConsoleCursorInfo(output, &cursor);
   #elif defined (unix)
   if(_liga)
      cout << "\033[?25l"; //25 visibilidade cursor, l reset mode
   else
      cout << "\033[?25h"; //25 visibilidade cursor, h set mode
   #endif
}

/** \brief Desliga o buffer de impressão na tela.
* A função é utilizada para corrigir eventuais problemas de impressão devido ao buffer criado pelo sistema.
* @param[in] _liga Define se o buffer deve ser desligado ou não.
* @remarks A função só é executada em ambiente Linux, uma vez que somente esse sistema apresenta eventuais problemas com este buffer.
*/
void desligaBufferTela(bool _liga){
   #if defined (unix)
   if(!_liga)
      setvbuf(stdout, NULL, _IOFBF, 80);
   else
      setvbuf(stdout, NULL, _IONBF, 0);
   return;
   #endif
}

/** \brief Apaga um intervalo de linhas.
* @param[in] _yInicial Primeira valor do intervalo de linhas a serem apagadas.
* @param[in] _yFinal Ultimo valor do intervalo de linhas a serem apagadas.
* @remarks Caso yInicial e yFinal sejam iguais apaga somente a linha informada pelos dois argumentos.
*/
void apagaLinha(int _yInicial, int _yFinal)
{
   for(int y = _yInicial; y <= _yFinal; ++y)
   {
      #if defined (_WIN32)
      gotoXY(0, y);

      CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo); //pega informacoes do output
      int tamLinha = consoleInfo.dwSize.X; //grava o tamanho da linha

      for(int x = 0; x <= tamLinha; x++) //apaga tantos caracteres quanto for o tamanho da linha
          cout << ' ';

      #elif defined (unix)
      gotoXY(1, y);
      cout << (char)27 << "[2K"; //apaga a linha
      #endif
   }

   return;
}

/** \brief Muda o tamanho da janela do programa.
* @param[in] _x Novo numero de colunas da janela.
* @param[in] _y Novo numero de linhas da janela.
*/
void mudaTamanhoTerminal(int _x, int _y)
{
    #if defined (_WIN32)
    string command = "mode con cols=" + numeroToString(_x) + " lines=" + numeroToString(_y); //mode altera dispositivos do sistema
        //con eh o console, cols colunas e lines linhas
    system(command.c_str()); //transforma em uma c-string e envia como comando do console

    #elif defined (unix)
    if(_x && _y)
    {
        cout << "\033[8;" << numeroToString(_y) << ";"
            << numeroToString(_x) << "t" << endl;
    }
    #endif
    return;
}

/** \brief Retira o echo do output.
* @param[in] _liga Se true, seta para nao mostrar as teclas pressionadas durante a execucao do programa. O contrario e obtido com false.
* @remarks No sistema Windows não é necessário o uso dessa função.
*/
void noecho(bool _liga)
{
    #if defined (unix)
    static struct termios oldTerminal;
    static struct termios newTerminal;

    if(_liga)
    {
        tcgetattr (0, &oldTerminal); //zero=STDIN_FILENO
        newTerminal = oldTerminal;
        newTerminal.c_lflag &= ~(ECHO | ICANON); //desabilita echo e canonical mode
        newTerminal.c_cc[VMIN] = 1; //read retorna quando VMIN(1) bytes de leitura for atingido
        newTerminal.c_cc[VTIME] = 0;
        tcsetattr(0, TCSAFLUSH, &newTerminal); //seta atts
    }
    else
    {
        tcsetattr(0, TCSAFLUSH, &oldTerminal); //seta antigo
    }
    #endif
    return;
}

/** \brief Gera um numero randomicamente.
* @param[in] _inicial Numero minimo a ser retornado.
* @param[in] _final Numero maximo a ser retornado. Se for omitido, nao ha limite maximo.
* @remarks Se ambos os parametros forem omitidos, entao o intervalo de numeros que podem ser retornados e o proprio limite da variavel.
* @return Um long int com o numero gerado randomicamente.
*/
long randomico(int _inicial, int _final)
{
   static bool ligado = true;
   int numero;

   if(ligado) //se ligado=true inicializa os randomicos
   {
      srand(time(0));
      ligado = false;
   }

   if(_final == 0) //se nao tiver max
      numero = rand();
   else
      numero = rand() % (_final - _inicial); //final-inicial garante o intervalo de numeros

   return numero + _inicial; //num+inicial garante o min
}

/** \brief Calcula o tempo que se passou.
* Inicia uma contagem de tempo em segundos ou retorna o tempo que se passou.
* @param[in] _entrada Opcional, se nao for passado a funcao ira iniciar a contagem (ou reseta-la). Se for passado calculará o tempo decorrido desde a chamada que iniciou a contagem.
* @return O tempo decorrido, em segundos, desde a chamada que iniciou a contagem.
*/
time_t tempoDecorrido(time_t _entrada)
{
    static time_t horaAntes;
    if(_entrada == 0) //se entrada for zero inicializa a contagem
        horaAntes = time(NULL);
    else
        return time(NULL) - horaAntes; //se nao retorna o tempo atual-tempo de inicio=tempo decorrido

    return horaAntes;
}

/** \brief Pausa a execucao do programa.
* @param[in] _tempo Tempo, em milissegundos, que o programa sera pausado(1000 milisegundos = 1 segundo).
*/
void espera(long int _tempo)
{
    #if defined (_WIN32)
    Sleep(_tempo);
    #elif defined (unix)
    long segundos = _tempo/1000;
    _tempo -= (segundos * 1000);

    struct timespec* req = (struct timespec*) new struct timespec;

    req->tv_sec = segundos;
    req->tv_nsec = _tempo * 1000000;

    nanosleep(req, NULL);
    delete req;
    #endif
}

/** \brief Usada para iniciar a contagem do tempo
* @return Uma variável do tipo TEMPO que armazena o momento em que a contagem foi iniciada. É usada como parâmetro na função tempoPassado(clock_t inicio).
*/
clock_t tempoInicio(){return clock();}

/** \brief Calcula quanto tempo se passou desde o início da contagem
* \param[in] _inicio Variável do tipo tempo que armazena quando a contagem foi iniciada. Deve ser inicializada com a função tempoInicio()
* @return O tempo que se passou, sendo que o retorno igual a 100 representa um segundo.
*/
int tempoPassado(clock_t _inicio)
{
   clock_t fim = clock() - _inicio;
   return ((float)fim / CLOCKS_PER_SEC) * 100;
}

/** \brief Le um inteiro do teclado.
* Le outro inteiro ate que o mesmo seja valido.
* @param[in] _mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O inteiro lido.
*/
int readInt(string _mensagem)
{
   int numero;
   bool inputFlag = true;
   while(inputFlag)
   {
      if(!_mensagem.empty())
         cout << _mensagem;
      cin >> numero;
      if(cin.fail())
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return numero;
}

/** \brief Le um float do teclado.
* Le outro float ate que o mesmo seja valido.
* @param[in] _mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O float lido.
*/
float readFloat(string _mensagem)
{
   float numero;
   bool inputFlag = true;
   while(inputFlag)
   {
      if(!_mensagem.empty())
         cout << _mensagem;
      cin >> numero;
      if(cin.fail())
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return numero;
}

/** \brief Le um double do teclado.
* Le outro valor ate que o mesmo seja valido.
* @param[in] _mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O double lido.
*/
double readDouble(string _mensagem)
{
   double numero;
   bool inputFlag = true;
   while(inputFlag)
   {
      if(!_mensagem.empty())
         cout << _mensagem;
      cin >> numero;
      if(cin.fail())
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return numero;
}

/** \brief Le um valor booleano do teclado.
* Le outro bool ate que o mesmo seja valido.
* @param[in] _mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O bool lido.
*/
bool readBool(string _mensagem)
{
   bool logico;
   bool inputFlag = true;
   while(inputFlag)
   {
      if(!_mensagem.empty())
         cout << _mensagem;
      cin >> logico;
      if(cin.fail())
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return logico;
}

/** \brief Le uma string do teclado.
* Le outra string ate que a mesma seja valida.
* @param[in] _mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return A string lida.
*/
string readString(string _mensagem)
{
   string str;
   bool inputFlag = true;
   while(inputFlag)
   {
      if(!_mensagem.empty()) //se houver mensagem, imprime
         cout << _mensagem;
      getline(cin, str, '\n'); //grava a linha atraves do cin na var str ate encontrar o char \n
      if(cin.fail()) //cin.fail() retorna flags de erro: badbit->  failbit->
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
         inputFlag = false;
   }
   //cin.clear();
   //cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

   return str;
}

/** \brief Le um caractere do teclado.
* Le outro caractere ate que o mesmo seja valido.
* @param[in] _mensagem Mensagem a ser mostrada na tela antes da leitura.
* @return O caractere lido.
*/
char readChar(string _mensagem)
{
   char caractere;
   bool inputFlag = true;
   while(inputFlag)
   {
      if(!_mensagem.empty())
         cout << _mensagem;
      cin >> caractere;
      if(cin.fail())
      {
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      else
         inputFlag = false;
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   return caractere;
}

/** \brief Converte um numero para string.
* @param[in] _valor Inteiro a ser convertido.
* @return Uma string contendo o valor convertido.
*/
string numeroToString(int _valor)
{
   std::stringstream out; //stringstream->classe para trabalhar com strings
   out << _valor; //out recebe valor
   return out.str(); //retorna out convertido em string
}

/** \brief Converte um numero para string.
* @param[in] _valor Double a ser convertido.
* @return Uma string contendo o valor convertido.
*/
string numeroToString(double _valor)
{
   std::stringstream out;
   out << _valor;
   return out.str();
}

/** \brief Converte um numero para string.
* @param[in] _valor Float a ser convertido.
* @return Uma string contendo o valor convertido.
*/
string numeroToString(float _valor)
{
   std::stringstream out;
   out << _valor;
   return out.str();
}

/** \brief Desenha um quadrilatero na tela.
* @param[in] _xInicial Coluna onde o quadrilatero começa (Canto superior esquerdo).
* @param[in] _yInicial Linha onde o quadrilatero começa (Canto superior esquerdo).
* @param[in] _xFinal Coluna onde o quadrilatero termina (Canto inferior direito).
* @param[in] _yFinal Coluna onde o quadrilatero termina (Canto inferior direito).
* @param[in] _sequencia String de tres caracteres que determina o desenho do quadrilatero: O primeiro caractere e usado nos quatro cantos do box. O segundo caractere e usado nas linhas inferior e superior. O terceiro caractere e usado nas linhas laterais. Caso nao seja passado o padrao e "+-|".
*/
void box(int _xInicial, int _yInicial, int _xFinal, int _yFinal, string _sequencia)
{
   enum BORDAS {CANTO, SUP_INF, LATERAL};
   for(int x = _xInicial; x <= _xFinal; ++x) //controla colunas
   {
      for(int y = _yInicial; y <= _yFinal; ++y) //controla linhas
      {
         if((x == _xInicial && y == _yInicial) ||
            (x == _xFinal   && y == _yFinal  ) ||
            (x == _xInicial && y == _yFinal  ) ||
            (x == _xFinal   && y == _yInicial))
         {
            gotoXY(x, y); //colocado aqui por questões de performance
            cout << _sequencia[CANTO]; //"+";
         }
         else if (y == _yInicial || y == _yFinal)
         {
            gotoXY(x, y); //colocado aqui por questões de performance
            cout << _sequencia[SUP_INF]; //"-";
         }
         else if(x == _xInicial || x == _xFinal)
         {
            gotoXY(x, y); //colocado aqui por questões de performance
            cout << _sequencia[LATERAL]; //"|";
         }
      }
   }
   return;
}

/** \brief Desenha um circulo na tela.
* @param[in] _x Coluna do centro do circulo.
* @param[in] _y Linha do centro do circulo.
* @param[in] _raio Tamanho do raio do circulo.
*/
void circulo(int _x, int _y, int _raio)
{
   if(_raio < 4) _raio = 4;
   else if(_raio > 10) _raio = 12;
   for(int angulo = 0; angulo <= 360; ++angulo)
   {
      float xPos=ceil(_x + cos(angulo * 3.1415F / 180.0F) * (_raio + 1)); //ceil retorna o menor inteiro que seja maior que o valor passado(1.5 retorna 2)
      float yPos=ceil(_y + sin(angulo * 3.1415F / 180.0F) * (_raio - 1.5));
      gotoXY((int)xPos, (int)yPos);
      cout << ".";
   }
   return;
}

/** \brief Retorna o conteudo de um arquivo.
* Podem acontecer falhas de acordo com o tipo do arquivo.
* @param[in] _nomeArquivo String contendo o caminho e nome do arquivo.
* @return Uma string contendo todas as linhas do arquivo.
* @see retornaArquivoSprites(string _nomeArquivo, string _separador)
*/
string retornaConteudoArquivo(string _nomeArquivo)
{
   std::ifstream leitura(_nomeArquivo.c_str()); //abre o arquivo
   string linhas = "";

   if(leitura)
   {
	  while(leitura.good()) //enquanto nao houver erro na leitura, como badbit ou failbit
	  {
         string temp;
         getline (leitura, temp); //le linha por linha
         temp += "\n"; //colocar o final de linha
	     linhas += temp;
	  }
   }
   else
      linhas = "Arquivo não existe!!";
   leitura.close(); //fecha o arquivo
   return linhas;
}

/** \brief Retorna as sprites contidas em um arquivo de texto simples.
* \param[in] _nomeArquivo String contendo o caminho e nome do arquivo que possui os sprites.
* \param[in] _separador String que funcionará como separador de sprites. Toda vez que houver esse separador a função irá considerar um novo sprite. O padrão é "*????????*"
* @return Um vetor de strings contendo os sprites.
* @see retornaConteudoArquivo(string _nomeArquivo)
* @see retornaImagens(string _nomeArquivo, string _separador)
*/
vector<string> retornaArquivoSprites(string _nomeArquivo, string _separador)
{
   std::ifstream leitura(_nomeArquivo.c_str());
   string linhas = "";
   vector<string> sprites;

   if(leitura)
   {
	   while(leitura.good())
	   {
         string temp;
         getline(leitura, temp); //le linha por linha
         if(temp == _separador)
         {
            sprites.push_back(linhas);
            linhas = "";
         }
	      else
	      {
	         temp += "\n"; //colocar o final de linha
	         linhas += temp;
         }
	   }
   }
   else
      linhas = "Arquivo não existe!!";
   leitura.close();
	return sprites;
}

/** \brief Retorna as imagens criadas a partir de um arquivo de texto simples.
* \param[in] _nomeArquivo String contendo o caminho e nome do arquivo que possui os sprites.
* \param[in] _separador String que funcionará como separador de imagens. Toda vez que houver esse separador a função irá considerar um novo imagens. O padrão é "*????????*"
* @return Um vetor de strings contendo as imagens.
* @remarks Possui a mesma utilidade que a função retornaArquivoSprites(string _nomeArquivo, string _separador), porém retorna um vetor do tipo Imagem e não do tipo string
*/
vector<Imagem> retornaImagens(string _nomeArquivo, string _separador)
{
   vector<string> imagens = retornaArquivoSprites(_nomeArquivo, _separador);
   vector<Imagem> minhasImagens;
   for(int i = 0; i < imagens.size(); ++i)
   {
      minhasImagens.push_back(Imagem(imagens[i]));
   }
   return minhasImagens;
}
/** \brief Imprime uma sequencia de sprites.
* Faz uma animação de diversos sprites.
* \param[in] _sprites Vetor com os sprites.
* \param[in] _x Coordenada horizontal de início dos sprites.
* \param[in] _y Coordenada vertical de início dos sprites.
* \param[in] _tempo Intervalo de tempo que os sprites levam para ser alterados. Caso seja omitido o valor padrão é 1 segundo
* @see imprimeSprite(string _sprite, int _x, int _y)
* @see retornaArquivoSprites(string _nomeArquivo, string _separador)
*/
void animaSprites(vector<string> _sprites, int _x, int _y, int _tempo)
{
   for(int i = 0; i < _sprites.size(); ++i)
   {
      imprimeSprite(_sprites[i], _x, _y);
      if(kbhit()) return;
      espera(_tempo * 100);
   }
   return;
}

/** \brief Imprime um sprite na tela
* O sprite é um arquivo de texto simples contendo strings de caracteres formando imagens.
* @param[in] _sprite String
* @param[in] _x Coordenada horizontal de início do sprite. Se não for informado seu valor padrão é um.
* @param[in] _y Coordenada vertical de início do sprite. Se não for informado seu valor padrão é um.
* @see animaSprites(vector<string> _sprites, int _x, int _y, int _tempo)
* @see retornaConteudoArquivo(string _nomeArquivo)
*/
void imprimeSprite(string _sprite, int _x, int _y)
{
   int pos;
    //quebra os \n para reposicionar e não dar erro
   while((pos = _sprite.find("\n")) != string::npos) //enquanto houver \n no sprite
   {
      gotoXY(_x, _y); //vai para pos de inicio
      string sprite_parcial = _sprite.substr(0, pos + 1);
      cout << sprite_parcial;
      ++_y;
      _sprite.erase(0, pos + 1);
   }
   gotoXY(_x, _y); //imprime última parte que não tem /n
   cout << _sprite;
   cout.flush();
   return;
}

/** \brief Cria um vetor de imagens.
* \param[in] _imagens Vetor de strings contendo as imagens.
* \param[in] _x Posição no eixo X da imagem.
* \param[in] _y Posição no eixo Y da imagem.
* \param[in] _tamanho Quantidade de imagens no vetor.
* @return Um vector de Imagens com as imagens criadas.
*/
vector<Imagem> criaImagens(const string _imagens[], int _x, int _y, int _tamanho){
   vector<Imagem> i;
   for(int j = 0; j < _tamanho; ++j)
   {
      Imagem t(_imagens[j], _x, _y);
      i.push_back(t);
   }
   return i;
}

/** \brief Cria um vetor de imagens.
* \param[in] _imagens Vector de strings contendo as imagens.
* \param[in] _x Posição no eixo X da imagem.
* \param[in] _y Posição no eixo Y da imagem.
* @return Um vector de Imagens com as imagens criadas.
*/
vector<Imagem> criaImagens(const vector<string> _imagens, int _x, int _y){
   vector<Imagem> i;
   for(int j = 0; j < _imagens.size(); ++j)
   {
      Imagem t(_imagens[j], _x, _y);
      i.push_back(t);
   }
   return i;
}

/** \brief Cria um vetor com uma imagem.
* \param[in] _imagem Nome do arquivo com as imagens. Deve ser usado o separador padrão da função retornaArquivoSprites().
* \param[in] _x Posição no eixo X da imagem.
* \param[in] _y Posição no eixo Y da imagem.
* @return Um vector de Imagem com a imagem criada.
*/
vector<Imagem> criaImagens(const string _imagem, int _x, int _y){
   vector<Imagem> i;
   vector<string> imagens = retornaArquivoSprites(_imagem);
   for(int j = 0; j < imagens.size(); ++j)
   {
      Imagem t(imagens[j], _x, _y);
      i.push_back(t);
   }
   return i;
}

/** \brief Limpa uma área da tela
* @param[in] _xInicial Coordenada x do canto superior esquerdo da área a ser apagada. Se não for informado seu valor padrão é um - Windows - .
* @param[in] _yInicial Coordenada y do canto superior esquerdo da área a ser apagada. Se não for informado seu valor padrão é um.
* @param[in] _xFinal Coordenada x do canto inferior direito da área a ser apagada. Se não for informado seu valor padrão é 79.
* @param[in] _yFinal Coordenada y do canto inferior direito da área a ser apagada. Se não for informado seu valor padrão é 24.
* @remarks Caso nenhum parâmetro seja informado ele apaga a tela inteira, se essa estiver com o tamanho padrão.
*/
void limpaArea(int _xInicial, int _yInicial, int _xFinal, int _yFinal)
{
   for(int x = _xInicial; x <= _xFinal; ++x)
   {
      for(int y = _yInicial; y <= _yFinal; ++y)
      {
         gotoXY(x, y);
         cout << " ";
      }
   }
   cout.flush();
   return;
}


/** \brief Randomiza uma palavra de um arquivo.
* \param[in] _palavras String contendo as palavras a serem randomizadas, separadas por um caractere de quebra de linha ('\n').
* @return Uma string contendo a palavra aleatória.
*/
string palavraAleatoria(string _palavras)
{
   int pos;
   vector<string> s;
    //quebra os \n para reposicionar e não dar erro
   while((pos = _palavras.find("\n")) != string::npos)
   {
      string p = _palavras.substr(0, pos);
      _palavras.erase(0, pos + 1);
      if(p != "\n" && !p.empty())
         s.push_back(p);
   }
   pos = randomico(1, s.size() - 1);
   return s[pos - 1];
}

/** \brief Mostra um menu vertical na tela.
* \param[in] _x Coordenada horizontal do menu.
* \param[in] _y Coordenada vertical do menu.
* \param[in] _opcoes Vetor de strings contendo as opções do menu.
* \param[in] _qtd Quantidade de opções do menu.
* \param[in] _ativo Cor da opção atualmente selecionada. Caso seja omitido o valor padrão é azul.
* \param[in] _inativo Cor das opções não selecionadas. Caso seja omitido o valor padrão é branco.
* @return Um inteiro contendo a posição da opção escolhida.
*/
int mostraMenuV(int _x, int _y, string _opcoes[], int _qtd, COR _ativo, COR _inativo)
{
   int newY = _y;
   mudaCor(_inativo);
   for(int i = 0; i < _qtd; ++i)
   {
      gotoXY(_x, newY);
      cout << _opcoes[i];
      ++newY;
   }
   int pos = 0;
   newY = _y;
   while(true)
   {
      char tecla;
      gotoXY(_x, newY);
      mudaCor(_ativo);
      cout << _opcoes[pos];
      if(verificaKB(tecla))
      {
         mudaCor(_inativo);
         gotoXY(_x, newY);
         cout << _opcoes[pos];
         if(tecla == K_UP)
         {
            if(pos == 0)
            {
               pos = _qtd - 1;
               newY = _y + _qtd - 1;
            }
            else
            {
               --pos;
               --newY;
            }
         }
         else if(tecla == K_DOWN)
         {
            if(pos == _qtd - 1)
            {
               pos = 0;
               newY = _y;
            }
            else
            {
               ++pos;
               ++newY;
            }
         }
         #if defined (_WIN32)
         else if((int)tecla == 13) return pos + 1;
         #elif defined (unix)
         else if(tecla == '\n') return pos + 1;
         #endif
      }
   }
   return 0;
}
/** \brief Mostra um menu horizontal na tela.
* \param[in] _x Coordenada horizontal do menu.
* \param[in] _y Coordenada vertical do menu.
* \param[in] _opcoes Vetor de strings contendo as opções do menu.
* \param[in] _qtd Quantidade de opções do menu.
* \param[in] _ativo Cor da opção atualmente selecionada. Caso seja omitido o valor padrão é azul.
* \param[in] _inativo Cor das opções não selecionadas. Caso seja omitido o valor padrão é branco.
* @return Um inteiro contendo a posição da opção escolhida.
*/
int mostraMenuH(int _x, int _y, string _opcoes[], int _qtd, COR _ativo, COR _inativo)
{
   int newX = _x;
   mudaCor(_inativo);
   int lastX;
   for(int i = 0; i < _qtd; ++i)
   {
      gotoXY(newX, _y);
      cout << _opcoes[i];
      lastX = newX;
      newX += _opcoes[i].size() + 2;
   }
   int pos = 0;
   newX = _x;
   while(true)
   {
      char tecla;
      gotoXY(newX, _y);
      mudaCor(_ativo);
      cout << _opcoes[pos];

      if(verificaKB(tecla))
      {
         mudaCor(_inativo);
         gotoXY(newX, _y);
         cout << _opcoes[pos];
         if(tecla == K_RIGHT)
         {
            if(pos == _qtd - 1)
            {
               pos = 0;
               newX = _x;
            }
            else
            {
               newX += _opcoes[pos++].size() + 2;
            }
         }
         else if(tecla == K_LEFT)
         {
            if(pos == 0)
            {
               pos = _qtd - 1;
               newX = lastX;//posicao da ultima opcao
            }
            else
            {
               --pos;
               newX -= (_opcoes[pos].size() + 2);
            }
         }
         #if defined (_WIN32)
         else if((int)tecla == 13) return pos + 1;
         #elif defined (unix)
         else if(tecla == '\n') return pos + 1;
         #endif
      }
   }
   return 0;
}

/** \brief Gera letras randômicas.
* \param[in] _qtd Quantidade de letras a serem geradas.
* @return Uma string com as letras geradas.
*/
string geraLetraRandomico(int _qtd)
{
   int vezes = 0;
   string s;
   while(vezes < _qtd)
   {
     int c;
     do
     {
        c = randomico(65, 122);
     }while(c > 90 && c < 97);
     s += string(1, c);
     ++vezes;
   }
   return s;
}
/** \brief Gera letras maiúsculas randômicas.
* \param[in] _qtd Quantidade de letras a serem geradas.
* @return Uma string com as letras geradas.
*/
string geraLetraRandomicoMaiscula(int _qtd)
{
   int vezes = 0;
   string s;
   while(vezes < _qtd)
   {
     int c;
     c = randomico(65, 90);
     s += string(1, c);
     ++vezes;
   }
   return s;
}
/** \brief Gera letras minúsculas randômicas.
* \param[in] _qtd Quantidade de letras a serem geradas.
* @return Uma string com as letras geradas.
*/
string geraLetraRandomicoMinuscula(int _qtd)
{
   int vezes = 0;
   string s;
   while(vezes < _qtd)
   {
     int c;
     c = randomico(97, 122);
     s += string(1, c);
     ++vezes;
   }
   return s;
}

/** \brief Colore uma image, permite mais de uma cor na mesma imagem
* @param[in] _colorir Imagem base para ser colorida
* @param[in] _referencia Imagem, igual ao parâmetro colorir, porém ao invés dos caracteres desejados, insere-se números de 1(um) a 8(oito), referentes a cor desejada para aquele ponto, conforme o enumerador COR
* @return Imagem com a cor dos pontos já setadas
*/
Imagem modificaCorPontos(Imagem _colorir, Imagem _referencia)
{
   vector<Ponto> pontosColorir = _colorir.getPontos();
   vector<Ponto> pontosReferencia = _referencia.getPontos();
   if(pontosColorir.size() == pontosReferencia.size() ){ //garante que é a mesma imagem
      for(int i = 0; i < pontosColorir.size(); ++i){
         if(pontosReferencia[i].getChar() == "1"){ //BLACK
            pontosColorir[i].setCor(BLACK);
         }
         else if(pontosReferencia[i].getChar() == "2"){ //BLUE
            pontosColorir[i].setCor(BLUE);
         }
         else if(pontosReferencia[i].getChar() == "3"){ //GREEN
            pontosColorir[i].setCor(GREEN);
         }
         else if(pontosReferencia[i].getChar() == "4"){ //CYAN
            pontosColorir[i].setCor(CYAN);
         }
         else if(pontosReferencia[i].getChar() == "5"){ //RED
            pontosColorir[i].setCor(RED);
         }
         else if(pontosReferencia[i].getChar() == "6"){//PURPLE
            pontosColorir[i].setCor(PURPLE);
         }
         else if(pontosReferencia[i].getChar() == "7"){ //YELLOW
            pontosColorir[i].setCor(YELLOW);
         }
         else if(pontosReferencia[i].getChar() == "8"){ //WHITE
            pontosColorir[i].setCor(WHITE);
         }
         pontosColorir[i].colore();
      }
      _colorir.setPontos(pontosColorir);
   }
   return _colorir;
}

/*
void tocaMusica(char* caminhoMusica)
{
    #if defined (_WIN32)
    PlaySound(TEXT(caminhoMusica), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    #elif defined (unix)
    char* buffer;
    buffer = (char*) malloc(strlen(caminhoMusica) + 24);
    sprintf(buffer, "aplay -c 1 -t wav -q %s &", caminhoMusica);
    system(buffer);
    free(buffer);
    #endif
}*/

