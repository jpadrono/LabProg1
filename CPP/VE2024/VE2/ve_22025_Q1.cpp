#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;
//combinação sem repetição de cores

class SabreDeLuz{
  int tamanho, energia;
  string cor, dono;

  SabreDeLuz(int tamanho, int energia, string cor, string dono):
    tamanho(tamanho), energia(energia), cor(cor), dono(dono){}
public:
  SabreDeLuz(int tamanho, string cor, string dono):
    tamanho(tamanho), cor(cor), dono(dono){
      if(dono == "sith"){
        energia = 100;
      }else if(dono == "jedi"){
        energia = 105;
      }
    }
  
  ~SabreDeLuz(){}

  operator int(){
    return energia;
  }

  operator string(){
    return cor;
  }

  SabreDeLuz operator+(SabreDeLuz sl){
    string newDono = "jedi";
    if(dono == "sith" && sl.dono == "sith"){
      newDono = "sith";
    }
    string newCor, temp;
    set<string> cores;
    stringstream ss;
    ss << cor << ',' << sl.cor;
    while (getline(ss, temp, ',')) {
      cores.insert(temp);
    }
    for(auto itr: cores){
      newCor += itr + ",";
    }
    newCor[newCor.size() - 1] = '\0';
    return SabreDeLuz(tamanho + sl.tamanho, energia + sl.energia, newCor, newDono);
  }

  SabreDeLuz embate(SabreDeLuz &sl1, SabreDeLuz &sl2){
    if(sl1.tamanho*sl1.energia == sl2.tamanho*sl2.energia){
      SabreDeLuz vencedor(*this);
      return vencedor;
    }else if(sl1.tamanho*sl1.energia > sl2.tamanho*sl2.energia){
      SabreDeLuz vencedor(*this);
      return vencedor;
    }else{
      SabreDeLuz vencedor(sl2);
      return vencedor;
    }
  }

  SabreDeLuz operator*(SabreDeLuz sl){
    SabreDeLuz vencedor = embate(*this, sl);
    if(vencedor.dono == "jedi"){
      return SabreDeLuz(vencedor.tamanho*0.9, vencedor.energia*0.95, vencedor.cor, vencedor.dono);
    }else{
      return SabreDeLuz(vencedor.tamanho*0.9, vencedor.energia*0.9, vencedor.cor, vencedor.dono);
    }
  }

  friend istream& operator >> (istream &is, SabreDeLuz &obj);
  friend ostream& operator << (ostream &os, const SabreDeLuz &obj);

  void imprimir(){
    cout << "tamanho: " << tamanho << endl;
    cout << "cor: " << cor << endl;
    cout << "energia: " << energia << endl;
    cout << "dono: " << dono << endl;
  }
};

istream& operator >> (istream &is, SabreDeLuz &obj){
  is >> obj.tamanho >> obj.cor >> obj.dono;
  return is;
}

ostream& operator << (ostream &os, const SabreDeLuz &obj){
  os << "Sabre de luz:\n" << "tamanho: " << obj.tamanho << "\nenergia: " << 
    obj.energia << "\ncor: " << obj.cor << "\ndono: " << obj.dono << endl;
  return os;
}

int main(){
  SabreDeLuz sl1(4, "verde", "jedi"), sl2(4, "vermelho", "sith"), sl3(4, "azul", "sith");

  cout << sl1 << sl2 << sl3;

  SabreDeLuz sl4 = sl1 + sl2; cout << sl4;
  SabreDeLuz sl5 = sl2 + sl3; cout << sl5;
  SabreDeLuz sl6 = sl4 + sl5; cout << sl6;


  SabreDeLuz sl7 = sl1*sl2; cout << sl7;
  SabreDeLuz sl8 = sl2*sl3; cout << sl8;
  SabreDeLuz sl9 = sl1*sl4; cout << sl9;
  SabreDeLuz sl10 = sl4*sl5; cout << sl10;
  SabreDeLuz sl11 = sl2*sl6; cout << sl11;

  cout << endl << endl;

  cin >> sl7;
  cout << sl7;
}