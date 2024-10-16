#include <stdio.h>

int mult(int a, int b){
  return a*b;
}

int main(){
  int a;
  int b;

  printf("Escolha um número: ");
  scanf ("%d", &a);
  printf("Escolha outro número: ");
  scanf ("%d", &b);

  int res = mult(a, b);
    
  printf ("O resultado da multiplição entre %d e %d é %d", a, b, res);
  
  return 0;
}
