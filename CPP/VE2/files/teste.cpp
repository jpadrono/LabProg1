#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    std::stringstream oss; // Cria um objeto ostringstream

    // Adiciona diferentes tipos de dados na stream
    int idade = 30;
    double altura = 1.75;
    string nome = "João";

    oss << "Nome: " << nome << "\n";
    oss.str(""); // limpa a sstream
    oss << "Idade: " << idade << " anos\n";
    oss << "Altura: " << altura << " metros\n";

    // Converte o conteúdo da stream para uma string
    string resultado = oss.str();

    // Imprime a string formatada
    cout << resultado;

    fstream file("teste.txt", ios::out | ios::in | ios::app);
    file << resultado;
    file.close();

    return 0;
}