#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>
#include <random>
#include <memory>

using namespace std;

class Lig4{
  protected:
    int colunas, linhas;
    bool vez;
    char **tabuleiro;
    char jogadores[2];
  public:
    Lig4(int n, int m): colunas(n), linhas(m), jogadores{'X', 'O'}{
      vez = false;
      tabuleiro = new char*[n];
      for (int i = 0; i < n; i++)
      {
          tabuleiro[i] = new char[m];
      }
      for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
          tabuleiro[i][j] = '.';
        }
      }
    }

    Lig4(const Lig4& l){
      colunas = l.colunas;
      linhas = l.linhas;
      tabuleiro = new char*[l.colunas];
      for (int i = 0; i < l.colunas; i++)
      {
          tabuleiro[i] = new char[l.linhas];
      }
      for(int i = 0 ; i < l.colunas; i++){
        for(int j = 0; j < l.linhas; j++){
          tabuleiro[i][j] = '.';
        }
      }
      vez = l.vez;
      jogadores[0] = l.jogadores[0];
      jogadores[1] = l.jogadores[1];
      
      
    }

    ~Lig4(){
      for (int i = 0; i < colunas; i++) {
        delete[] tabuleiro[i];
      }
      delete[] tabuleiro;
    }

    void exibe(){
      for(int i = 0 ; i < linhas; i++){
        cout << "\t";
          for(int j = 0; j < colunas; j++){
            cout << tabuleiro[j][i];
          }
          cout << endl;
        }
    }
    void limpar(){
      for(int i = 0 ; i < colunas; i++){
          for(int j = 0; j < linhas; j++){
            tabuleiro[i][j] = '.';
          }
        }
    }
    void trocarVez(){
        vez = !vez;
    }



    bool jogadaValida(int colunaSelecionada){
      if(colunaSelecionada > colunas){
        return false;
      }
      if(tabuleiro[colunaSelecionada][0] != '.'){
        return false;
      }
      return true;
    }

    void jogar(int colunaSelecionada){
      if(jogadaValida(colunaSelecionada-1)){
        for(int i = linhas; i >= 0; i--){
          if(tabuleiro[colunaSelecionada-1][i] == '.'){
            tabuleiro[colunaSelecionada-1][i] = jogadores[vez];
            if(tabuleiroCompleto()){
              resultado();
              return;
            }
            trocarVez();
            break;
          }
        }
      }
      else{
        cout << "jogada inválida" << endl;
      }
    }

    bool tabuleiroCompleto(){
      for(int i = 0; i < colunas; i++){
        if(tabuleiro[i][0] == '.'){
          return false;
        }
      }
      return true;
    }
    
    void resultado(){
      cout << "\tRESULTADO" << endl;
      char *ptr1, *ptr2;
      int countAux = 0;
      int pontos[2] = {0, 0} ;
      /*
       *
       *
       */
      for(int i = 0; i < colunas; i++){
        ptr1 = &tabuleiro[i][0];
        countAux = 0;
        for(int j = 0; j < linhas; j++){
          ptr2 = &tabuleiro[i][j];
          if(*ptr2 == *ptr1){
            countAux++;
          }
          if(*ptr1 != *ptr2 || j == linhas - 1){
            if(countAux >= 4){
              if(*ptr1 == 'X'){
                pontos[0] += countAux-3;
              }else if(*ptr1 == 'O'){
                pontos[1] += countAux-3;
              }
            }
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      /****/
      for(int i = 0; i < linhas; i++){
        ptr1 = &tabuleiro[0][i];
        countAux = 0;
        for(int j = 0; j < colunas; j++){
          ptr2 = &tabuleiro [j][i];
          if(*ptr2 == *ptr1){
            countAux++;
          }
          if(*ptr1 != *ptr2 || j == colunas - 1){

            if(countAux >= 4){
              if(*ptr1 == 'X'){
                pontos[0] += countAux-3;
              }else if(*ptr1 == 'O'){
                pontos[1] += countAux-3;
              }
            }
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }

      /*
        *
         *
          */
      for(int i = 0; i < colunas - 3; i++){
        ptr1 = &tabuleiro[i][0];
        countAux = 0;
        for(int j = 0; i+j < colunas && j < linhas; j++){
          ptr2 = &tabuleiro [i+j][j];
          if(*ptr2 == *ptr1){
            countAux++;
          }
          if(*ptr1 != *ptr2 || j+i == colunas - 1 || j == linhas - 1 ){

            if(countAux >= 4){
              if(*ptr1 == 'X'){
                pontos[0] += countAux-3;
              }else if(*ptr1 == 'O'){
                pontos[1] += countAux-3;
              }
            }
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      for(int i = 1; i < linhas-3; i++){
        ptr1 = &tabuleiro[0][i];
        countAux = 0;
        for(int j = 0; j+i < linhas; j++){
          ptr2 = &tabuleiro [j][i+j];
          if(*ptr2 == *ptr1){
            countAux++;
          }
          if(*ptr1 != *ptr2 || j+i == linhas - 1){

            if(countAux >= 4){
              if(*ptr1 == 'X'){
                pontos[0] += countAux-3;
              }else if(*ptr1 == 'O'){
                pontos[1] += countAux-3;
              }
            }
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
          /*
          *
         *
        */
      for(int i = 0; i < colunas - 3; i++){
        ptr1 = &tabuleiro[i][linhas-1];
        countAux = 0;
        for(int j = 0; i+j < colunas && linhas-1-j >= 0; j++){
          ptr2 = &tabuleiro [i+j][linhas-1-j];
          if(*ptr2 == *ptr1){
            countAux++;
          }
          if(*ptr1 != *ptr2 || j+i == colunas - 1 || linhas-1-j == 0 ){

            if(countAux >= 4){
              if(*ptr1 == 'X'){
                pontos[0] += countAux-3;
              }else if(*ptr1 == 'O'){
                pontos[1] += countAux-3;
              }
            }
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      for(int i = 1; i < linhas-3; i++){
        ptr1 = &tabuleiro[0][linhas-1-i];
        countAux = 0;
        for(int j = 0; j < colunas && linhas-1-i-j >= 0; j++){
          ptr2 = &tabuleiro [j][linhas-1-i-j];
          if(*ptr2 == *ptr1){
            countAux++;
          }
          if(*ptr1 != *ptr2 || j == colunas - 1 || linhas-1-i-j == 0){

            if(countAux >= 4){
              if(*ptr1 == 'X'){
                pontos[0] += countAux-3;
              }else if(*ptr1 == 'O'){
                pontos[1] += countAux-3;
              }
            }
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      

      cout << "Pontos do Jogador " << jogadores[0] << ": " <<  pontos[0] << endl;
      cout << "Pontos do Jogador " << jogadores[1] << ": " <<  pontos[1] << endl;
    }

    void jogo(){
      cout << "    JOGO INICIADO!" << endl;
      limpar();
      while(!tabuleiroCompleto()){
        exibe();
        int n;
        cout << "Vez do jogador " << jogadores[vez] << endl;
        cout << "escolha a coluna em que será colocada a peça: ";
        cin >> n;
        jogar(n);
      }
      exibe();
    }

    bool getVez(){
      return vez;
    }

    char getJogador(){
      return jogadores[vez];
    }
};

class lig4Tradicional: public Lig4{
  enum estado { VitoriaX, VitoriaO, Empate, Continua};
  public:
    lig4Tradicional():Lig4(7,6){};

    estado resultado(){

      char *ptr1, *ptr2;
      int countAux = 0;
      /*
       *
       *
       */
      for(int i = 0; i < colunas; i++){
        ptr1 = &tabuleiro[i][0];
        countAux = 0;
        for(int j = 0; j < linhas; j++){
          ptr2 = &tabuleiro[i][j];
          if(*ptr2 == *ptr1){
            countAux++;
            if(countAux == 4){
              if(*ptr1 == 'X'){
                return VitoriaX;
              }else if(*ptr1 == 'O'){
                return VitoriaO;
              }
            }
          }
          if(*ptr1 != *ptr2 || j == linhas - 1){
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      /****/
      for(int i = 0; i < linhas; i++){
        ptr1 = &tabuleiro[0][i];
        countAux = 0;
        for(int j = 0; j < colunas; j++){
          ptr2 = &tabuleiro [j][i];
          if(*ptr2 == *ptr1){
            countAux++;
            if(countAux == 4){
              if(*ptr1 == 'X'){
                return VitoriaX;
              }else if(*ptr1 == 'O'){
                return VitoriaO;
              }
            }
          }
          if(*ptr1 != *ptr2 || j == colunas - 1){
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }

      /*
        *
         *
          */
      for(int i = 0; i < colunas - 3; i++){
        ptr1 = &tabuleiro[i][0];
        countAux = 0;
        for(int j = 0; i+j < colunas && j < linhas; j++){
          ptr2 = &tabuleiro [i+j][j];
          if(*ptr2 == *ptr1){
            countAux++;
            if(countAux == 4){
              if(*ptr1 == 'X'){
                return VitoriaX;
              }else if(*ptr1 == 'O'){
                return VitoriaO;
              }
            }
          }
          if(*ptr1 != *ptr2 || j+i == colunas - 1 || j == linhas - 1 ){
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      for(int i = 1; i < linhas-3; i++){
        ptr1 = &tabuleiro[0][i];
        countAux = 0;
        for(int j = 0; j+i < linhas; j++){
          ptr2 = &tabuleiro [j][i+j];
          if(*ptr2 == *ptr1){
            countAux++;
            if(countAux == 4){
              if(*ptr1 == 'X'){
                return VitoriaX;
              }else if(*ptr1 == 'O'){
                return VitoriaO;
              }
            }
          }
          if(*ptr1 != *ptr2 || j+i == linhas - 1){
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
          /*
          *
         *
        */
      for(int i = 0; i < colunas - 3; i++){
        ptr1 = &tabuleiro[i][linhas-1];
        countAux = 0;
        for(int j = 0; i+j < colunas && linhas-1-j >= 0; j++){
          ptr2 = &tabuleiro [i+j][linhas-1-j];
          if(*ptr2 == *ptr1){
            countAux++;
            if(countAux == 4){
              if(*ptr1 == 'X'){
                return VitoriaX;
              }else if(*ptr1 == 'O'){
                return VitoriaO;
              }
            }
          }
          if(*ptr1 != *ptr2 || j+i == colunas - 1 || linhas-1-j == 0 ){
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      for(int i = 1; i < linhas-3; i++){
        ptr1 = &tabuleiro[0][linhas-1-i];
        countAux = 0;
        for(int j = 0; j < colunas && linhas-1-i-j >= 0; j++){
          ptr2 = &tabuleiro [j][linhas-1-i-j];
          if(*ptr2 == *ptr1){
            countAux++;
            if(countAux == 4){
              if(*ptr1 == 'X'){
                return VitoriaX;
              }else if(*ptr1 == 'O'){
                return VitoriaO;
              }
            }
          }
          if(*ptr1 != *ptr2 || j == colunas - 1 || linhas-1-i-j == 0){
            countAux = 1;
            ptr1 = ptr2;
          }
        }
      }
      
      if(tabuleiroCompleto()){
        return Empate;
      }
      return Continua;

    }
    
    void jogo(){
      cout << "    JOGO INICIADO!" << endl;
      limpar();
      while(resultado() == 3){
        exibe();
        int n;
        cout << "Vez do jogador " << jogadores[vez] << endl;
        cout << "escolha a coluna em que será colocada a peça: ";
        cin >> n;
        jogar(n);
      }
      exibe();
      switch (resultado()){
        case VitoriaX:
          cout << "Vitória do Jogador" << jogadores[0] << endl;
          break;
        case VitoriaO:
          cout << "Vitória do Jogador" << jogadores[1] << endl;
          break;
        case Empate:
          cout << "Jogo terminou empatado" << endl;
          break;
       case Continua:
          cout << "Erro encontrado, Jogo finalizou em Continua" << endl;
          exit(1); 
      }
    }

    int negamax(const char **tabuleiro) {
      nodeCount++; // increment counter of explored nodes

      if(P.nbMoves() == Position::WIDTH*Position::HEIGHT) // check for draw game
        return 0; 

      for(int x = 0; x < Position::WIDTH; x++) // check if current player can win next move
        if(P.canPlay(x) && P.isWinningMove(x)) 
          return (Position::WIDTH*Position::HEIGHT+1 - P.nbMoves())/2;

      int bestScore = -Position::WIDTH*Position::HEIGHT; // init the best possible score with a lower bound of score.
      
      for(int x = 0; x < Position::WIDTH; x++) // compute the score of all possible next move and keep the best one
        if(P.canPlay(x)) {
          Position P2(P);
          P2.play(x);               // It's opponent turn in P2 position after current player plays x column.
          int score = -negamax(P2); // If current player plays col x, his score will be the opposite of opponent's score after playing col x
          if(score > bestScore) bestScore = score; // keep track of best possible score so far.
        }

      return bestScore;
    }
};


int main(){
  
  lig4Tradicional a;
  a.jogo();
  
  return 0;
}