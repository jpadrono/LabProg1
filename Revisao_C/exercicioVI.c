#include <stdio.h>

int n;
int resp = 1;
int aux = 0;

int main(){

  printf("escolha um valor pra n: ");
  scanf("%d", &n);
  
  for(int i = 1; i < n; i++){
    int temp = resp;
    resp += aux;
    aux = temp;
  }

  printf("O %dº número da série de fibonacci é: %d", n, resp);

  return 0;
}