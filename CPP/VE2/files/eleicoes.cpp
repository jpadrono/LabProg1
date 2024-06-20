#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
  string candidato, partido, nomeArq, teste1, teste2;
  stringstream urna;
  int n,j,i,c, total=0;
  ifstream arqCandidatos, arqVotos;
  vector<string> candidatos;
  vector<int> votos, ordem;


  arqCandidatos.open("candidatos.txt");
  if(!arqCandidatos.is_open()){
    cout << "Arquivo Inválido de Candidatos" << endl;
    return 1;
  }
  
  while(!arqCandidatos.eof()){
    arqCandidatos >> n >> candidato >> partido;
    if(arqCandidatos.good()){
      // candidatos.resize(candidatos.size() + 1);
      // candidatos[n-1] = candidato;
      candidatos.push_back(candidato);
    }
  }
  arqCandidatos.close();

  votos.resize(n);
  for(i = 0;i < n; i++)
    votos[i] = 0;

  for(j = 1; j < 5; j++)
    urna << "urna" << j << ".txt ";
  
  for(j = 1; j < 5; j++){
    urna >> nomeArq;
    arqVotos.open(nomeArq.c_str(), ios::in);
    if(!arqVotos.is_open()){
      cout << "Arquivo Inválido de Votos " << j << endl;
      return j+1;
    }
    arqVotos.clear();
    while(!arqVotos.eof()){
      arqVotos >> c;
      if(arqVotos.good()){
        votos[c-1]++;
        total++;
      }
    }
    arqVotos.close();
  }

  ordem.resize(n);
  for(i = 0; i < n; i++)
    ordem[i] = i;
  for(i = 0;i < n; i++)
    for(j = i+1; j < n; j++)
      if(votos[ordem[i]] < votos[ordem[j]]) 
        swap(ordem[i], ordem[j]);
  
  for(auto itr : ordem){
    cout << setw(3) << right << 1+itr << " " << left << setw(8) <<
      candidatos[itr] << " " << votos[itr] << " " <<
      setprecision(3) << setiosflags(ios::showpoint) <<
      votos[itr]*100.0/total << "%" << endl;
  }
  
  return 0;
}

