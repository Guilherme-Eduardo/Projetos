// jogo da velha
// utilizando o conceitos de vectores
// e aplicando vários conceitos já vistos até o momento
// funções, constantes, estruturas de repetição e condição
// programa_004.cpp
#include "biblaureano.h"

// constantes globais
const char X = 'X';
const char O = 'O';
const char VAZIO = ' ';
const char EMPATE = 'E';
const char NINGUEM = 'N';

// protótipos
void instrucoes();
string simOuNao(string questao);
int numero(string questao, int alto, int baixo=0);
char pecaHumana();
char oponente(char peca);
void mostrarTabuleiro(const vector<char> tabuleiro);
inline bool eLegal(int movimento, const vector<char> tabuleiro);
int movimentoHumano(const vector<char> tabuleiro, char humano);
int movimentoComputador(vector<char> tabuleiro, char computador);
char vencedor(const vector<char> tabuleiro);
void anuncioVencedor(char vencedor, char computador, char humano);

// programa principal
int main() {
   int movimento;
   const int NUM_SQUARES = 9;
   vector<char> tabuleiro(NUM_SQUARES, VAZIO);

   instrucoes();
   char humano = pecaHumana();
   char computador = oponente(humano);
   char turno = X;
   mostrarTabuleiro(tabuleiro);

   //enquanto não houver vencedor
   while (vencedor(tabuleiro) == NINGUEM){
      if (turno == humano) {
         movimento = movimentoHumano(tabuleiro, humano);
         tabuleiro[movimento] = humano;
      }
      else {
         movimento = movimentoComputador(tabuleiro,computador);
         tabuleiro[movimento] = computador;
      }

      mostrarTabuleiro(tabuleiro);
      turno = oponente(turno);
   }

   anuncioVencedor(vencedor(tabuleiro), computador, humano);

   return 0;
}

// funções
void instrucoes() {
   cout << "Bem-vindo ao ultimo confronto homem-maquina: Velha 100 AC." << endl;
   cout << "-- onde cerebro humano e combatera o processador de silicio." << endl << endl;

   cout << "Faca a sua jogada! Introduza um numero, 0 - 8.  O numero" << endl;
   cout << "corresponde a posicao desejada do tabuleiro, tal como ilustrado:" << endl << endl;

   cout << "       0 | 1 | 2" << endl;
   cout << "       ---------" << endl;
   cout << "       3 | 4 | 5" << endl;
   cout << "       ---------" << endl;
   cout << "       6 | 7 | 8" << endl << endl;

   cout << "Prepare-se, humano. A batalha está prestes a comecar." << endl << endl;
   return;
}

string simOuNao(string questao) {
   string resposta;
   questao += ":[sn]";
   do {
      resposta = readString(questao);
   } while (resposta != "s" && resposta != "n");

   return resposta;
}

int numero(string questao, int alto, int baixo) {
   int numero;
   questao += " (" + numeroToString(baixo) + " - " + numeroToString(alto) + "):";
   do {
      numero = readInt(questao);
   } while (numero> alto || numero < baixo);

   return numero;
}

//verifica a peça (X ou O) do jogador humano
char pecaHumana() {
   string primeiro = simOuNao("Voce quer o primeiro movimento?");
   if (primeiro == "s") {
      cout << endl << "Pegue o primeiro movimento, você ira precisar mesmo..." << endl;
      return X;
   }
   else {
      cout << endl << "Sua coragem sera a sua ruína... Eu vou primeiro!" << endl;
      return O;
   }
}

//verifica qual o próximo a jogar
char oponente(char peca) {
   if (peca == X) {
      return O;
   }
   else {
      return X;
   }
}

//mostra a situação atual do jogo e a referência do tabuleiro
void mostrarTabuleiro(const vector<char> tabuleiro) {
   cout << "\n\t" << tabuleiro[0] << " | " << tabuleiro[1] << " | " << tabuleiro[2] << "\t\t\t0 | 1 | 2";
   cout << "\n\t" << "---------"  << "\t\t\t---------";
   cout << "\n\t" << tabuleiro[3] << " | " << tabuleiro[4] << " | " << tabuleiro[5] << "\t\t\t3 | 4 | 5";;
   cout << "\n\t" << "---------"  << "\t\t\t---------";
   cout << "\n\t" << tabuleiro[6] << " | " << tabuleiro[7] << " | " << tabuleiro[8] << "\t\t\t6 | 7 | 8";;
   cout << endl << endl;
   return;
}

//verifica se houve vencedor
char vencedor(const vector<char> tabuleiro) {
    // combinações possíveis de vencedores
    const int SEQUENCIAS_VENCEDORAS[24] = { 0, 1, 2,
                                            3, 4, 5,
                                            6, 7, 8,
                                            0, 3, 6,
                                            1, 4, 7,
                                            2, 5, 8,
                                            0, 4, 8,
                                            2, 4, 6 };
   for(int i = 0; i<24; i+=3) {
      if( (tabuleiro[ SEQUENCIAS_VENCEDORAS[i] ]   != VAZIO) &&
          (tabuleiro[ SEQUENCIAS_VENCEDORAS[i] ]   == tabuleiro[ SEQUENCIAS_VENCEDORAS[i+1] ]) &&
          (tabuleiro[ SEQUENCIAS_VENCEDORAS[i+1] ] == tabuleiro[ SEQUENCIAS_VENCEDORAS[i+2] ])) {
         return tabuleiro[ SEQUENCIAS_VENCEDORAS[i]];
      }

   }
   // se ninguém ganhou, checando para ver se ainda existem espaços vazios no tabuleiro
   if (count(tabuleiro.begin(), tabuleiro.end(), VAZIO) == 0) {
      return EMPATE;
   }

   // ninguém ganhou e ainda existem espaços vazios, o jogo não acabou
   return NINGUEM;
}

//verifica se o movimento é válido
inline bool eLegal(int movimento, const vector<char> tabuleiro) {
   return (tabuleiro[movimento] == VAZIO);
}

//retorna o movimento do jogador
int movimentoHumano(const vector<char> tabuleiro, char humano) {
   int movimento = numero("Qual o seu movimento?", (tabuleiro.size() - 1));
   while (!eLegal(movimento, tabuleiro)) {
      cout << endl << "Este espaco esta ocupado, humano tolo." << endl;
      movimento = numero("Qual o seu movimento?", (tabuleiro.size() - 1));
   }
   cout << "Bom..." << endl;
   return movimento;
}

//retorna o movimento do computador
int movimentoComputador(vector<char> tabuleiro, char computador) {
   cout << "Eu escolho o espaco ";

   // se o computador pode ganhar na próxima jogada...
   for(int movimento = 0; movimento < tabuleiro.size(); ++movimento) {
      if (eLegal(movimento, tabuleiro)) {

         tabuleiro[movimento] = computador;

         if(vencedor(tabuleiro) == computador) {
            cout << movimento << endl;
            return movimento;
         }
          // movimento verificado, tenho que desfaze-lo
         tabuleiro[movimento] = VAZIO;
      }
   }

   // se o jogador humano for ganhar na próxima jogada, é necessário bloquea-lo
 /*  char humano = oponente(computador);
   for(int movimento = 0; movimento < tabuleiro.size(); ++movimento)
   {
      if (eLegal(movimento, tabuleiro)) {

         tabuleiro[movimento] = humano;

         if (vencedor(tabuleiro) == humano) {
            cout << movimento << endl;
            return movimento;
         }
         // movimento verificado, tenho que desfaze-lo
         tabuleiro[movimento] = VAZIO;
      }
   }
*/
   // a melhor sequência de jogadas
   const int MELHORES_MOVIMENTOS[]={4, 8, 6, 0, 1, 3, 5, 7};
   // se não posso ganhar nesta jogada, tento escolher a melhor jogada possível
   for(int i = 0; i < tabuleiro.size(); ++i) {
      int movimento = MELHORES_MOVIMENTOS[i];
      if (eLegal(movimento, tabuleiro)){
         cout << movimento << endl;
         return movimento ;
      }
   }
}

void anuncioVencedor(char vencedor, char computador, char humano) {
   if(vencedor == computador ) {
      cout << vencedor << " ganhou!" << endl;
      cout << "Como eu previ, humano, eu sou vitorioso mais uma vez -- a prova" << endl;
      cout << "que os computadores sao superiores aos seres humanos em todos os aspectos." << endl;
   }

	else if (vencedor == humano) {
      cout << vencedor << " ganhou!" << endl;
      cout << "Nao, nao! Nao pode ser! De alguma forma, você me enganou, humano." << endl;
      cout << "Mas esta sera a ultima vez, eu prometo!!" << endl;
   }
	else{
      cout << "Temos um empate!" << endl;
      cout << "Você tem sorte, humano, e de alguma forma conseguiu empatar comigo." << endl;
      cout << "Celebre... pois e o melhor que ira conseguir de mim." << endl;;
	}
	return;
}
