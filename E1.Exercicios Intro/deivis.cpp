#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  int i,j;
  int menor_x, maior_x;
  int menor_y, maior_y;
  int altura, lado, bit;
  int linha;
  int divider, element;
  int ordem_grandeza = 1;
  int tem_um = 0;
  ii retangulo = mp(0,0);
  vi matriz(10,0);

  scanf("%d %d", &altura, &lado);

  menor_x = lado - 1;
  maior_x = 0;

  menor_y = altura - 1;
  maior_y = 0;

  for(i = 0; i < altura; i++){
    scanf("%d", &linha);
    matriz[i] = linha;
  }

  for(i = 0; i < lado-1; i++){
    ordem_grandeza *= 10;
  }

  for(i = 0; i < altura; i++){
    divider = ordem_grandeza;
    element = matriz[i];

    for(j = 0; j < lado; j++){

      bit = element/divider;

      // Menor eixo x
      if(bit == 1 && j <= menor_x){
        menor_x = j;
        tem_um = 1;
      }

      // Maior eixo x
      if(bit == 1 && j >= maior_x){
        maior_x = j;
        tem_um = 1;   
      }

      // Menor eixo y
      if(bit == 1 && i <= menor_y){
        menor_y = i;
        tem_um = 1;
      }

      // Maior eixo y
      if(bit == 1 && i >= maior_y){
        maior_y = i;
        tem_um = 1;
      }

      element %= divider;
      divider /= 10;
    }
  }

  if(!tem_um){
    printf("0x0\n");
  }

  else{
    retangulo.first = maior_x -  menor_x + 1;
    retangulo.second = maior_y -  menor_y + 1;

    printf("%dx%d\n", retangulo.first, retangulo.second);
  }

  return 0;
}
