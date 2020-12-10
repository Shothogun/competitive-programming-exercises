#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  
  int n,x,i, j, element, flag=0;
  vi a,b;

  scanf("%d %d", &n, &x);

  for(i = 0; i< n -1;i++){
    scanf("%d ", &element);
    a.pb(element);
  }

  scanf("%d ", &element);
  a.pb(element);


  for(i = 0; i< n -1;i++){
    scanf("%d", &element);
    b.pb(element);
  }

  scanf("%d", &element);
  b.pb(element);

  for(i = 0; i < n; i++){
    for(j=0; j< n; j++){
      if(a[i] + b[j] == x){
        flag=1;
        break;
      }
    }
    if(flag){break;}
  }

  printf("%d\n", flag);

  return 0;
}
