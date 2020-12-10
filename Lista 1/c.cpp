#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  
  int old, candle,k,extra,hours;
  
  scanf("%d %d", &candle, &k);

  hours = candle;
  old = candle;

  while(old >= k){
    candle = old/k;
    old = old%k; 
    hours += candle;
    old += candle; 
  }
  
  printf("%d\n", hours);

  return 0;
}
