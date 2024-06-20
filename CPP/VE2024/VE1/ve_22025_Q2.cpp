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

class FuncionarioBase{
    int id;
    string name;
    double salary;
    string tipo;
  public:
    FuncionarioBase(){
    }
    FuncionarioBase(int id, string name, double salary, string tipo):
      id(id), name(name), salary(salary), tipo(tipo){}
    FuncionarioBase(const FuncionarioBase& f){
			id = f.id;
			name = f.name;
			salary = f.salary;
			tipo = f.tipo;
		}
    
    void exibirDetalhes(){
      cout << "Detalhes do Funcionário" << endl;
      cout << "id: " << id << endl;
      cout << "name: " << name << endl;
      cout << "salary: " << salary << endl;
      cout << "tipo: " << tipo << endl;
    }

    double getSalary(){
      return salary;
    }

};

class Funcionario: public FuncionarioBase{
  public:
    Funcionario(int id, string name, double salary, string tipo):
      FuncionarioBase(id, name, salary, tipo){}
};

class Gerente: public FuncionarioBase{
  FuncionarioBase **equipe;
  int nEquipe;
  public:
    Gerente(int id, string name, double salary):
      FuncionarioBase(id, name, salary, "gerente"), nEquipe(0){
        equipe = new FuncionarioBase*[10];
      }

    Gerente(const FuncionarioBase& g){
			equipe = new FuncionarioBase*[10];
		}

    ~Gerente(){delete[] equipe;}

    bool adicionarFuncionario(FuncionarioBase &f){
      if(nEquipe == 10){
        return false;
      }
      equipe[nEquipe++] = &f;
      return true;
    }

    void mostrarTime(){
      for(int i = 0; i < nEquipe; i++){
        cout << "Membro: " << i+1 << endl;
        equipe[i]->exibirDetalhes();
      }
    }
    double salarioTotal(){
      double total = 0.0;
      total += this->getSalary();
      for(int i = 0; i < nEquipe; i++){
        total += equipe[i]->getSalary();
      }
      return total;
    }
};

int main(){
  Funcionario f1(1, "joão", 10, "aluno");
  Funcionario f2(2, "brito", 15, "aluno2");
  Funcionario f3(3, "augusto", 15, "aluno3");
  Funcionario f4(4, "ikro", 15.5, "aluno4");
  Funcionario f5(5, "felipe", 10, "aluno5");
  Funcionario f6(6, "camatari", 20, "aluno6");
  Funcionario f7(7, "mateus", 2, "aluno7");
  Funcionario f8(8, "bruno", 10.5, "aluno8");
  Funcionario f9(9, "thiago", 10.6, "aluno9");
  Funcionario f10(10, "pedro", 10.7, "aluno10");
  Funcionario f11(11, "saboya", 10.8, "aluno11");
  Gerente g1(12, "saka", 20);
  g1.adicionarFuncionario(f1);
  g1.adicionarFuncionario(f2);
  g1.adicionarFuncionario(f3);
  g1.adicionarFuncionario(f4);
  g1.adicionarFuncionario(f5);
  g1.adicionarFuncionario(f6);
  g1.adicionarFuncionario(f7);
  g1.adicionarFuncionario(f8);
  g1.adicionarFuncionario(f9);
  g1.adicionarFuncionario(f10);
  g1.adicionarFuncionario(f11);
  cout << f1.getSalary() << endl;
  g1.mostrarTime();
  cout << g1.salarioTotal() << endl;
  return 0;
}