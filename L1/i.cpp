#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
 
int main(){
 
  int n, i, element, days = 1;
  int counter = 0;
  vi a;
  map<int, int> m;
 
  scanf("%d", &n);
 
  for(i = 0; i< n-1;i++){
    scanf("%d ", &element);
    a.pb(element);
    m[element] += 1;
  }
 
  scanf("%d", &element);
  a.pb(element);
  m[element] += 1;
 
  sort(a.begin(), a.end());
  int biggest = a.back();
 
  i = 1;
  while(1) {
    if(i > biggest){
      break;
    }
 
    if(m[i] > 0 && i >= days){
      m[i]--;
      days++;
    }
    else{
      i++;
    }
  }
 
  printf("%d\n", days-1);
 
  return 0;
}