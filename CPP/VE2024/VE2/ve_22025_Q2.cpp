#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
//ideia: utilizar map

class Personagem{
  string nome, classe;
  int saudeInicial;
public:
  Personagem(string nome, string classe, int saudeIni):
    nome(nome), classe(classe), saudeInicial(saudeIni){}
  
  ~Personagem(){}

  string getNome(){
    return nome;
  }

  static Personagem readFromFile(istream& arq){
    string linha;
    stringstream ss, tempLinha;
    string proxNome, proxClasse,temp;
    int proxSaude, count = 3;
    if(arq.good()){
      getline(arq, linha);
      ss << linha;
      cout << linha << endl;
      if(arq.good()){      
        while (getline(ss, temp, ',')) {
          if(count == 3){
            proxNome = temp;
            count--;
          }else if(count == 2){
            proxClasse = temp;
            count--;
          }else if(count == 1){
            proxSaude = stoi(temp);
            count--;
          }else{
            break;
          }
        }
        tempLinha >> proxNome >> proxClasse >> proxSaude;
      }
    }
    Personagem newPersonagem(proxNome, proxClasse, proxSaude);
    return newPersonagem;
  }

  void writeToFile(ostream& arq){
    string linha;
    arq << nome << "," << classe << "," << saudeInicial << endl;
  }

  bool operator==(Personagem &p){
    return nome==p.nome;
  }
};

int main(){
  ifstream arqEntrada;
  ofstream arqSaida;
  vector<Personagem> personagens; 

  arqEntrada.open("entrada.txt");
  if(!arqEntrada.is_open()){
    cout << "Arquivo Inválido de entrada" << endl;
    return 1;
  }

  while(!arqEntrada.eof()){
    Personagem cTemp(Personagem::readFromFile(arqEntrada));
    auto itr = personagens.begin();
    for(;itr != personagens.end(); itr++){
      if(itr->getNome() == cTemp.getNome()){
        cout << itr->getNome() << " repetido" << endl;
        break;
      }
    } 
    if(itr == personagens.end())
      personagens.push_back(cTemp);
  }

  arqEntrada.close();

  arqSaida.open("saida.txt");

  for(auto itr : personagens){
    if(itr.getNome() != ""){
      itr.writeToFile(arqSaida);
    }
  }

  arqSaida.close();
  return 0;
}

