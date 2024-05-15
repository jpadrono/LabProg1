#include <iostream>
#include <string>
#include <algorithm>
#include <random>


using namespace std;
/******************************************************************************
 *você poderia usar rand e srand mas por mais que seja "aleatório", quando    *
 *você faz %10 ou %100 você tá dependendo dos ultimos bits do número gerados  * 
 *e no caso do rand e srand a distribuição de bits não é muito homogênea      *  
 *resumindo, por mais que seja aleatório não seria homogeneamente distribuido *
 *então rand()%10+1 > 8 não da tão perto de 20% quanto deveria                *
 ******************************************************************************/
int gen(int num)
{
    random_device rd;
    mt19937 gen_numb(rd());
    uniform_int_distribution<> dis(1, num);

    return dis(gen_numb);
}

class Soldado{
    string nome;
    double saude;
    double poderDeAtaque;

  public:
    Soldado(string nome, double saude, double poder): 
      nome(nome), saude(saude), poderDeAtaque(poder){}

    void atacar(Soldado &s){
      cout << nome << " atacou o soldado " << s.getNome() << endl;
      s.defender(poderDeAtaque);
    }

    void defender(double poder){
      saude -= poder;
      cout << nome << " recebeu " << poder << endl;
    }

    string getNome(){
      return nome;
    }

    double getSaude(){
      return saude;
    }

    double getPoderDeAtaque(){
      return poderDeAtaque;
    }
};

class Elfo:public Soldado{
  public:

    Elfo(string nome, double saude, double poder):
      Soldado(nome, saude, poder + 1){}
    
    void atacar(Soldado &s){
      defender(this->getPoderDeAtaque());
      cout << this->getNome() << " ataca " << s.getNome() << endl;
    }
};

class Anao:public Soldado{
  public:
  
    Anao(string nome, double saude, double poder):
      Soldado(nome, saude, poder + 20){}

    void atacar(Soldado &s){
      cout << this->getNome() << " ataca " << s.getNome() << endl;
      if((gen(10) > 4)){
        s.defender(this->getPoderDeAtaque());
      }
    }
};

class Humano:public Soldado{
  public:
    Humano(string nome, double saude, double poder):
      Soldado(nome, saude, poder){}
    
    void atacar(Soldado &s){
      cout << this->getNome() << " ataca " << s.getNome() << endl;
      if((gen(10) > 9)){
        s.defender(this->getPoderDeAtaque()*2);
      }else {
        s.defender(this->getPoderDeAtaque());
      }
    }
};

class Sauron:public Soldado{
  public:
    Sauron(string nome, double saude, double poder):
      Soldado(nome, 10*saude, poder){}

    void atacar(Soldado &s){
      if(gen(10) > 7){
        s.defender(this->getPoderDeAtaque()*2);
      }else {
        s.defender(this->getPoderDeAtaque());
      }
    }

};

class Orc:public Soldado{
  public:
    Orc(string nome, double saude, double poder):
      Soldado(nome, saude, poder){}

    void atacar(Soldado &s){
      if(gen(10) > 8){
        s.defender(this->getPoderDeAtaque()*1.1*2);
      }
    }
};

// Nosso mago consegue diminuir 40% do dano do inimigo e consegue sempre infligir +25%
class Mago:public Soldado {
  public:
    Mago(string nome, double saude, double poder):
      Soldado(nome, saude, poder){}
    void defender(double poder) {
        Soldado::defender(poder * 0.6);
    }
    void atacar(Soldado &s) {
        s.defender(getPoderDeAtaque()*1.25);
    }
};

int main() {
  vector<Soldado*> v;
  v.push_back(new Sauron("Zelda", 10, 2));
  v.push_back(new Mago("Skyrim", 55, 4));
  v.push_back(new Orc("Portal", 25, 3));
  v.push_back(new Orc("Super Mario", 22, 4));
  v.push_back(new Orc("Minecraft", 23, 3));
  v.push_back(new Orc("God of War", 24, 4));
  v.push_back(new Orc("Final Fantasy", 30, 2));
  v.push_back(new Orc("The Witcher", 22, 3));
  v.push_back(new Orc("Assassin's Creed", 28, 4));
  v.push_back(new Orc("Shadow of the Colossus", 23, 4));
  v.push_back(new Orc("nUdertale", 22, 5));
  v.push_back(new Orc("Doom", 23, 4));
  v.push_back(new Elfo("Dark Souls", 25, 4));
  v.push_back(new Elfo("Elden Ring", 28, 3));
  v.push_back(new Elfo("Hades", 22, 4));
  v.push_back(new Elfo("Stardew Valley", 30, 3));
  v.push_back(new Elfo("Hollow Knight", 22, 4));
  v.push_back(new Humano("Celeste", 25, 5));
  v.push_back(new Humano("The Sims", 26, 4));
  v.push_back(new Humano("Palworld", 26, 4));
  v.push_back(new Humano("Cuphead", 30, 4));
  v.push_back(new Humano("Enter the Gungeon", 23, 5));
  v.push_back(new Anao("Outer Wilds", 16, 2));
  v.push_back(new Anao("Papers Please", 20, 2));
  v.push_back(new Anao("Dead Cells", 24, 1));
  v.push_back(new Anao("Chants of Sennaar", 25, 1));
  v.push_back(new Anao("Catamari", 23, 1));
  int ind = 0;
  while(v.size() > 1) {
    // shuffle(v.begin(), v.end(), gen(1000));
    ind = gen(1000)%v.size();
    auto first = v[ind];
    v.erase(v.begin() + ind);
    ind = gen(1000)%v.size();
    auto second = v[ind];
    v.erase(v.begin() + ind);
    cout << first->getNome();
    first->atacar(*second);
    v.push_back(first);
    if(second->getSaude() > 0) {
      v.push_back(second);
    } else {
      cout << second->getNome() << " morreu lutando contra " << first->getNome() << endl;
    }
  }
  cout << "O campeão é " << v[0]->getNome() << " com " << v[0]->getSaude() << " ponto(s) de vida!" << endl;
  return 0;
}
