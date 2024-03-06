#include <stdio.h>
#include <stdlib.h>

float media(float *v, int n){
  float m = 0;
  for(int i = 0; i < n; i++){
    m += v[i];
  }
  return m/n;
}

int n;
float *v= NULL;

int main(){
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  v = (float *)(malloc(sizeof(float)*n));

  if (v == NULL) {
      printf("Alocação de memória falhou.\n");
      return 1;
  }

  printf("digite os valores das notas:");
  for(int i = 0; i < n; i++){
    scanf("%f", &v[i]);
  }

  printf("a média das notas é: %f", media(v,n));

  free(v);

  return 0;
}

