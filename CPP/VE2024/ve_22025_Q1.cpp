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

    ~Lig4(){delete[] tabuleiro;}

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
    /*
     *
     *
     */
    void resultado(){
      cout << "\tRESULTADO" << endl;
      char *ptr1, *ptr2;
      int countAux = 0;
      int pontos[2] = {0, 0} ;
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
              }else{
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
              }else{
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
              }else{
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
              }else{
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
              }else{
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
              }else{
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
  enum estados { Vitoria1, Vitoria2, Empate, Continua};
  public:
    lig4Tradicional():Lig4(7,6){};
    
};


int main(){
  
  Lig4 a(7,6);
  a.jogo();
  
  return 0;
}