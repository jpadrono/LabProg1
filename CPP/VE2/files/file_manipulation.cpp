#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int escrita(string nome_do_arquivo, string frase)
{
    ofstream file(nome_do_arquivo);

    if (!file)
    {
        cerr << "Erro ao abrir o arquivo para escrita" << endl;
        return 0; // deu ruim
    }
    // Escreve dados no arquivo
    file << frase << endl;
    // Fecha o arquivo
    file.close();

    return 1; // deu bão
}

int leitura(string nome_do_arquivo)
{
    // Cria um objeto de entrada de arquivo
    ifstream file(nome_do_arquivo);

    // Verifica se o arquivo foi aberto corretamente
    if (!file)
    {
        cerr << "Erro ao abrir o arquivo para leitura" << endl;
        return 0; // deu ruim
    }

    // Lê dados do arquivo
    string linha;
    while (getline(file, linha))
    {
        cout << linha << endl;
    }

    // Fecha o arquivo
    file.close();

    return 1; // deu bão
}

string lertudao(string filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return "";
    }

    string content((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());

    return content;
}

int main()
{
    // ios::in: Abre o arquivo para leitura.
    // ios::out: Abre o arquivo para escrita.
    // ios::app: Abre o arquivo para escrita, adicionando novos dados ao final do arquivo sem apagar o conteúdo existente.
    // ios::ate: Abre o arquivo e move o ponteiro de escrita para o final do arquivo.
    // ios::binary: Abre o arquivo em modo binário.
    fstream arquivo("exemplo.txt", ios::in | ios::out | ios::app);
    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    arquivo << "Adicionando uma nova linha." << endl;

    arquivo.seekg(0);

    // lê um caractere
    char caractere;
    if (arquivo.get(caractere))
    {
        std::cout << "O primeiro caractere lido é: " << caractere << std::endl;
    }
    else
    {
        std::cerr << "Erro ao ler o caractere do arquivo" << std::endl;
    }
    // lê uma linha
    string linha;
    while (getline(arquivo, linha))
    {
        cout << linha << endl;
    }

    arquivo.close();

    return 0;
}
