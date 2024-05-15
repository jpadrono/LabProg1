#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Character{
    string nome;
    string ocupacao;
  public:
    Character(string nome, string ocupacao): 
      nome(nome), ocupacao(ocupacao){}
    
    string getNome(){
      return nome;
    }

    string getOcupacao(){
      return ocupacao;
    }

    void setOcupacao(string novaOcupacao){
      ocupacao = novaOcupacao;
    }
};



class CharacterDatabase{
    vector<Character*> characters;
    vector<pair<string, pair<Character, Character>>> relacionamentos;
  public:

    string searchCharacter(string nome){
      auto itr = characters.begin();
      for(; itr != characters.end(); itr++){
        if((*itr)->getNome() == nome){
          break;
        }
      }
      if(itr == characters.end()){
        return "Personagem não cadastrado";
      }
      return (*itr)->getOcupacao();
    }
    vector<Character*> getCharacters(){
      return characters;
    }
    void addCharacter(Character &c){
      auto itr = characters.begin();
      for(; itr != characters.end(); itr++){
        if((*itr)->getNome() == c.getNome()){
          cout << "Personagem já cadastrado" << endl;
          return;
        }
      }
      characters.push_back(&c);
    }

    void deleteCharacter(string nome){
      auto itr = characters.begin();
      for(; itr != characters.end(); itr++){
        if((*itr)->getNome() == nome)
        break;
      }
      if(itr == characters.end()){
        cout << "Personagem não cadastrado" << endl;
        return;
      }
      if(itr != characters.end()){
        characters.erase(itr);
        int cont = 0;
        for(auto itr : relacionamentos){
          if(itr.second.first.getNome() == nome || itr.second.second.getNome() == nome){
            relacionamentos.erase(relacionamentos.begin() + cont);
          }
          cont++;
        }
        cout << "Personagem excluido com sucesso" << endl;
      }
      return;
    }

    void editCharacter(string nome, string novaOcupacao){
      auto itr = characters.begin();
      for(; itr != characters.end(); itr++){
        if((*itr)->getNome() == nome)break;
      }
      if(itr == characters.end()){
        cout << "Personagem não cadastrado" << endl;
        return;
      }
      if(itr != characters.end()){
        (*itr)->setOcupacao(novaOcupacao);
        cout << "Ocupação editada com sucesso" << endl;
      }
      return;
    }

    void relate(Character c1, Character c2, string relacao){
      auto itr = characters.begin();
      for(; itr != characters.end(); itr++){
        if((*itr)->getNome() == c1.getNome())break;
      }
      if(itr == characters.end()){
        cout << "Personagem " << c1.getNome() << " não cadastrado" << endl;
        return;
      }
      auto itr2 = characters.begin();
      for(; itr2 != characters.end(); itr2++){
        if((*itr2)->getNome() == c2.getNome())break;
      }
      if(itr2 == characters.end()){
        cout << "Personagem " << c2.getNome() << " não cadastrado" << endl;
        return;
      }
      relacionamentos.push_back(make_pair(relacao, make_pair(c1, c2)));
      return;
    }

    void imprimir(){
      cout << "Lista de Personagens" << endl;
      auto itr = characters.begin();
      int cPersonagens = 1, cRelacionamentos = 1;
      for(; itr != characters.end(); itr++){
        cout << "Personagem " << cPersonagens++ << ": " << (*itr)->getNome() << endl;
      }
      for(auto itr: relacionamentos){
        cout << "Relacionamento " << cRelacionamentos++ << ": " << itr.second.first.getNome() << "e " << itr.second.second.getNome() << " possuem relação de " << itr.first << endl;
      }

    }
};

int main(){
  CharacterDatabase database;
  Character c1 = Character("Rachel Green", "Garçonete"); 
  Character c2 = Character("Monica Geller", "Chef");
  Character c3 = Character("Phoebe Buffay", "Massagista"); 
  Character c4 = Character("Chandler Bing", "Desconhecido");
  Character c5 = Character("Ross Geller", "Professor"); 
  Character c6 = Character("Joey Tribbiani", "Ator");
  database.addCharacter(c1); 
  database.addCharacter(c2); 
  database.addCharacter(c3);
  database.addCharacter(c4); 
  database.addCharacter(c5); 
  database.addCharacter(c6);
  database.editCharacter("Rachel Green", "Design de Moda");
  cout << database.searchCharacter("Gunther") << endl; 
  cout << database.searchCharacter("Rachel Green") << endl;
  database.relate(c2, c5, "irmãos"); 
  database.relate(c2, c4, "casados");
  database.relate(c1, c2, "roommates"); 
  database.relate(c4, c6, "roommates");
  database.deleteCharacter("Phoebe Buffay"); 
  database.imprimir();
}