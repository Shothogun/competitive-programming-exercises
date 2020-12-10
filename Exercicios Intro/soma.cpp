#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
    
  int n, i, element = 0;
  int soma = 0;

  scanf("%d", &n);

  for(i = 0; i < n-1; i++){
    scanf("%d ", &element);
    soma += element;
  }

  scanf("%d", &element);
  soma += element;

  printf("%d\n", soma);

  return 0;
}
