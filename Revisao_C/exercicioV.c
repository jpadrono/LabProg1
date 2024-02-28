#include <stdio.h>

//função recursiva de fibonacci
//no slide começa do 0 mas como a série começa do 1 considerei o valor zero como
//sendo o termo 0 da sequência
int fb (int a){
  if(a == 0){
    return 0;
  }
 if (a == 2 || a == 1) {
  return 1;
 }
 return fb(a-1) + fb(a-2);
}

int n;

int main() {
  printf("escolha um valor pra n: ");
  scanf("%d", &n);

  int resposta = fb(n);
  printf("O %dº número da série de fibonacci é: %d", n, resposta);

  return 0;
}