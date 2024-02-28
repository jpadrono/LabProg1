#include <stdio.h>
#include <stdlib.h>

//a característica de um vetor é a alocação dinâmica da memória
//como C não possui um tipo vector, vamos ter que criar um usando ponteiros

int n;

int main(){
  int *vector = NULL;
  int len = 0;

  //alocação dinâmica de memória
  vector = (int *)malloc(sizeof(int) * len);

  if (vector == NULL) {
      printf("Memory allocation failed.\n");
      return 1;
  }

  printf("escolha o tamanho do vetor: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    len++;
    vector = (int *)realloc(vector, sizeof(int) * len);

    if (vector == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    int a;
    scanf("%d", &a);
    vector[len-1] = a;
  }

  //podemos usar qualquer algorítimo de sort então usarei o mais simples
  
  //bubble sort
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - 1  ; j++){
      if(vector[j + 1] < vector[j]){
        int temp = vector[j+1];
        vector[j + 1] = vector[j];
        vector[j] = temp;
      }
    }
  }

  for(int i = 0; i < n; i++){
    printf("%d ", vector[i]);
  }

  return 0;
}