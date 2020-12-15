#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  
  int A, N;

  scanf("%d %d", &N, &A);

  N %= 500;
  if(N-A <= 0){
    printf("Sim\n");
  }

  else{
    printf("Nao\n");
  }

  return 0;
}
