#include <stdio.h>

//inteiro que recebe os números do arquivo
int num;
//variável para armazenar as operações dos números ímpares e pares
//perceba que o valor inicial dos números pares deve ser 1 por ser um produtório
int even = 1;
int odd = 0;
//ponteiro para ler o arquivo
FILE *fptr;
//contador para saber o tamanho da array
int count = 0;

int main() {

  //abrir arquivo no modo "r", read
  fptr = fopen("C:\\Users\\Lenovo\\Desktop\\cpp\\Revisao_C\\exercicioIII.txt", "r");

  //caso der erro ao abrir o arquivo
  if(fptr == NULL){
    printf("Não foi possível abrir o arquivo\n");
    return 1;
  }

  // fscanf lê as linhas do arquivo no formato especificado
  // como temos apenas um núemro por linha o formato é simplesmente "%d"
  // o valor lido é então armazenado na variável num
  while(fscanf(fptr, "%d", &num) == 1){
    if(!(num%2)){
      even *= num;
    } else{
      odd += num;
    }
  }

  // lembrar de fechar o arquivo, seu pc agradece
  fclose(fptr);

  printf("Produtório dos números pares: %d\n", even);
  printf("Somatório dos números ímpares: %d", odd);

  return 0;
}