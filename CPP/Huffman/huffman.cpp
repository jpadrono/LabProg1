#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define MAX_SIZE 100

class HuffmanTreeNode{
public:
  char data;
  int freq;
  HuffmanTreeNode *left, *right;

  HuffmanTreeNode(char data, int freq):
    data(data), freq(freq), left(NULL), right(NULL){}
  
};

class Compare{
public:
  bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b){
    return a->freq > b->freq;
  }
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, 
                            vector<HuffmanTreeNode*>, Compare> pq)
{
  while(pq.size() != 1){
    HuffmanTreeNode* left = pq.top();
    pq.pop();
    HuffmanTreeNode* right = pq.top();
    pq.pop();
    HuffmanTreeNode* node = new HuffmanTreeNode('$', left->freq+right->freq);
    node->left = left;
    node->right = right;
    pq.push(node);
  }

  return pq.top();
}

void printCodes(HuffmanTreeNode* root, char arr[], int top){
  if(root->left){
    arr[top] = '0';
    printCodes(root->left,arr, top+1);
  }

  if(root->right){
    arr[top] = '1';
    printCodes(root->right,arr, top+1);
  }

  if (!root->left && !root->right) {
    // root->code = arr;
    cout << root->data << " ";
    for (int i = 0; i < top; i++) {
      cout << arr[i];
    }
    cout << endl;
  }
}

void huffmanVector(vector<pair<char,string>> &v, HuffmanTreeNode* root, 
                    char arr[], int top)
{
  if(root->left){
    arr[top] = '0';
    huffmanVector(v, root->left, arr, top+1);
  }

  if(root->right){
    arr[top] = '1';
    huffmanVector(v, root->right, arr, top+1);
  }

  string code = "";
  if (!root->left && !root->right) {
    for (int i = 0; i < top; i++) {
      code += arr[i];
    }
    v.push_back(make_pair(root->data, code));
  }
}

vector<pair<char, string>> HuffmanCodes(vector<pair<char, int>> v, int size){
  priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

  for(int i=0; i < size; i++){
    HuffmanTreeNode* newNode = new HuffmanTreeNode(v[i].first, v[i].second  );
    pq.push(newNode);
  }

  HuffmanTreeNode* root = generateTree(pq);

  char arr[MAX_SIZE], top = 0;
  printCodes(root, arr, top);
  // nodeCodes(root, arr, top);

  vector<pair<char,string>> huffmanVec;
  huffmanVector(huffmanVec, root, arr, top);
  return huffmanVec;
}

//peguei os caracteres que eu vou aceitar ler
set<char> myASCII = {' ', '!', '"', '#', '%', '&', '\'', '(', ')', '*', 
'+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', 
';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
'[', '\\', ']', '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
'{', '|', '}'};

vector<pair<char,int>> readFile(string filename){

  ifstream inputFile(filename);
  if (!inputFile) {
      cerr << "Error: Unable to open the file." << endl;
      exit(1);
  }
  
  //inicializando um vetor de pares com os caracteres de myASCII
  vector<pair<char,int>> v, newv;
  for(auto itr : myASCII){
    v.push_back(make_pair(itr, 0));
  }

  //lendo cada palavra do arquivo
  char c;
  while (inputFile.get(c)) {
      for(auto& itr2 : v){
        if(itr2.first == c){
          itr2.second++;
          break;
        }
    }
  }
  for(auto itr : v){
    if(itr.second != 0){
      newv.push_back(itr);
    }
  }
  inputFile.close();
  return newv;
}

// estrutura da função de decodificação
// void DecodedFile(vector<pair<char,string>>, string filename){

//     ifstream inputFile(filename);
//     if (!inputFile) {
//         cerr << "Error: Unable to open the file." << endl;
//         exit(1);
//     }

//     string textoDescodificado = "";
//     string codigoH = "";
//     char c;
//     while(inputFile.get(c)){
//       codigoH += c;
//       for(auto itr: v){
//         if(itr.second == codigoH){
//            textoDescodificado += itr.first
//            codigoH = ""; 
//         }
//       }
//     }

//     inputFile.close();

// }

// void codedFile(vector<pair<char,string>>, string filename){

//     ifstream inputFile(filename);
//     if (!inputFile) {
//         cerr << "Error: Unable to open the file." << endl;
//         exit(1);
//     }

//     string textoDescodificado = "";
//     string codigoH = "";
//     char c;
//     while(inputFile.get(c)){
//       codigoH += c;
//       for(auto itr: v){
//         if(itr.second == codigoH){
//            textoDescodificado += itr.first
//            codigoH = ""; 
//         }
//       }
//     }

//     inputFile.close();

// }

int main() {
    string filename;
    cout << "filename: ";
    cin >> filename;

    vector<pair<char,int>> v;
    v = readFile(filename);
    for(auto itr : v){
      cout << "f: " << itr.first << " s: " << itr.second << endl;
    }

    vector<pair<char,string>> huffmanVec;
    huffmanVec = HuffmanCodes(v, v.size());

    for(auto itr:huffmanVec){
      cout << itr.first << " " << itr.second << endl;
    }
    

    return 0;
}
