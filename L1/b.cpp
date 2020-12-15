#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  
  int n,i,element, greater, coin = 0;
  vi a;

  scanf("%d", &n);

  for(i = 0; i< n - 1;i++){
    scanf("%d ", &element);
    a.pb(element);
  }

  scanf("%d", &element);
  a.pb(element);

  sort(a.begin(),a.end());

  greater = a[n-1];

  for(i=0; i<n;i++){
    coin += greater - a[i];
  }

  printf("%d\n", coin);

  return 0;
}
