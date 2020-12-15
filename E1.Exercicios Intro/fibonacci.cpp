#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){

  int n, i;
  int next;
  vi fibo;

  scanf("%d", &n);

  // n = 0
  fibo.pb(0);
  // n = 1
  fibo.pb(1);
  // n = 2
  fibo.pb(1);

  if(n <= 2){
    printf("%d\n", fibo[n]);

    return 0;
  }

  for(i = 2; i < n; i++){
    next = fibo[i] + fibo[i-1];
    fibo.pb(next); 
  }

  printf("%d\n", fibo[n]);

  return 0;
}
