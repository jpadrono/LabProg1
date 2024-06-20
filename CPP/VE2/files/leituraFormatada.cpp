#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::vector<int>> lerArquivo(const std::string& nomeArquivo) {
    std::ifstream inputFile(nomeArquivo);
    std::vector<std::vector<int>> numeros;

    if (!inputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return numeros;
    }

    std::string linha;
    while (std::getline(inputFile, linha)) {
        std::vector<int> linhaNumeros;
        std::stringstream ss(linha);
        std::string numero;

        while (std::getline(ss, numero, ',')) {
            linhaNumeros.push_back(std::stoi(numero)); // std::stof ou std::stod para float e double
        }

        numeros.push_back(linhaNumeros); // Adiciona o vetor de números da linha ao vetor principal
    }

    inputFile.close();
    return numeros;
}

int main() {
    std::string nomeArquivo = "numeros.txt"; // Substitua pelo nome do seu arquivo
    std::vector<std::vector<int>> numeros = lerArquivo(nomeArquivo);

    // Exemplo de como acessar os números lidos
    for (const auto& linha : numeros) {
        for (int numero : linha) {
            std::cout << numero << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
