#include <stdio.h>

float n;
int m;

//função recursiva para printar o maior par menor que um valor n
void subtracaoRecursiva (int a) {
  //se a <= 2 encerra a fução (caso fundamental)
  if(a < 2){
    return;
  }
  else{
    //função recursiva é chamada no início para que os números sejam printados
    //em ordem crescente 
    subtracaoRecursiva(a - 2);
    //calculo do maior número par menor que a
    int p = a - a%2;
    printf("%d\t", p);
    return;
  }
}

int main(void) {
   //recebe o valor de n
  printf("escolha o valor de n: ");
  scanf("%f", &n);

  //consideração para n float
  m = (int) n;
  if(n - m) {
    subtracaoRecursiva(m);
  }else if (!(m%2)) {
    subtracaoRecursiva(m-2);
  }else {
    subtracaoRecursiva(m);
  }

  return 0;
}