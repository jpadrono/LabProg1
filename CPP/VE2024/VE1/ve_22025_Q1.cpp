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
          tabuleiro[i][j] = l.tabuleiro[i][j];
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
  int moves;
  long long nodeCount;

  public:
    lig4Tradicional():Lig4(7,6), moves(0), nodeCount(0){};

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
    
    void jogar(int colunaSelecionada){
      if(jogadaValida(colunaSelecionada-1)){
        for(int i = linhas-1; i >= 0; i--){
          if(tabuleiro[colunaSelecionada-1][i] == '.'){
            tabuleiro[colunaSelecionada-1][i] = jogadores[vez];
            moves++;
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

    bool jogadaGanhadora(int colunaSelecionada){
      lig4Tradicional ligTemp(*this);
      ligTemp.jogar(colunaSelecionada);
      if(ligTemp.resultado() == VitoriaX && !getVez()){
        return true;
      }else if(ligTemp.resultado() == VitoriaO && getVez()){
        return true;
      }
      return false;
    }

    pair<int,int> negamax(const lig4Tradicional& lig, int alpha, int beta) {
      nodeCount++; // increment counter of explored nodes

      if(resultado() == Empate){
        return {0,0}; 
      } // check for draw game

      for(int x = 1; x <= colunas; x++){
        if(jogadaValida(x-1) && jogadaGanhadora(x)){
          return {(colunas*linhas+1 - nbMoves())/2, x};
        }
      } // check if current player can win next move

      int max = (colunas*linhas-1 - nbMoves())/2;
      if(beta > max){
        beta = max;
        if(alpha >= beta) return {beta, 0};
      }
      int bestMove = -1;

      for(int x = 1; x <= colunas; x++){
        if(jogadaValida(x-1)) {
          lig4Tradicional lig_2(lig);
          lig_2.jogar(x);               // It's opponent turn in P2 position after current player plays x column.
          int score = -lig_2.negamax(lig_2, -beta, -alpha).first; // If current player plays col x, his score will be the opposite of opponent's score after playing col x
          if(score >= beta) return {score, x};
          if(score > alpha){
            alpha = score;
            bestMove = x;
          } 
        }
      } // compute the score of all possible next move and keep the best one

      return {alpha, bestMove};
    }

    int solve(const lig4Tradicional &lig) 
    {
      nodeCount = 0;
      return negamax(lig, -99999, 99999).second;
    }

    void jogadaBot(){
      int melhorJogada = solve(*this);
      jogar(melhorJogada);
    }

    void jogadaAleatoria(){
      while(!tabuleiroCompleto()){
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<int> dis(1, 7);
        int random_number = dis(gen);
        if(jogadaValida(random_number-1)){
            jogar(random_number);
            return;
        }
      }
    }
    int nbMoves(){
      return moves;
    }
};


int main(){
  
  lig4Tradicional a;
  
  return 0;
}