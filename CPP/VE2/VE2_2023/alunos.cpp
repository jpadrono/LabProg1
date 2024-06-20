#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){
  string nome, nomezin;
  float nota;
  ifstream arqAlunos, arqNotas;
  stringstream ss;
  vector<string> nomes;
  vector<float> notas;
  map<string, vector<float>> alunos;

  arqAlunos.open("alunos.txt");
  if(!arqAlunos.is_open()){
    cout << "Erro ao abrir o arquivo alunos.txt" << endl;
    return 1;
  }
  
  while(!arqAlunos.eof()){
    arqAlunos >> nome;
    if(arqAlunos.good()){
      ss << nome << " ";
      nomes.push_back(nome);
    }
  }
  arqAlunos.close();

  for(int i = 0; i < 3; i++){
    ss >> nomezin;
    cout << nomezin << endl;
  }
  
  while(getline(ss, nomezin, ' ')){
    cout << "opa "<< nomezin << endl;
  }

  for(auto itr:nomes){
    nome = itr + ".txt";
    arqNotas.clear();
    
    arqNotas.open(nome.c_str(), ios::in);
    if(!arqNotas.is_open()){
      cout << "Erro ao abrir o arquivo " << nome << endl;
      return 1;
    }

    while(!arqNotas.eof()){
      arqNotas >> nota;
      if(arqNotas.good()){
        notas.push_back(nota);
      }
    }
    arqNotas.close();
    alunos.insert({itr, notas});
    notas.clear();
  }

  for(auto itr : alunos){
    cout << "aluno: " << itr.first << endl;
    for(auto itr2 : itr.second){
      cout << itr2 << " ";
    }
    cout << endl;
  } 

  return 0;
}