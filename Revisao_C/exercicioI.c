#include <stdio.h>

int n;

int main(void){
  // recebe o valor de n
  printf("Insira o valor de n: ");
  scanf("%d", &n);

  //printar os valores de 2 em 2
  for(int i = 2; i < n; i += 2){
    printf("%d\t", i);
  } 

  return (0);
}