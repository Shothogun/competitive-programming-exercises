#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  int n_child, child, i;
  int size_1 = 0, size_2 = 0, size_3 = 0;
  vi t1,t2,t3;
  vi teams;
  int n_teams;

  scanf("%d", &n_child);

  if(n_child == 0){
    printf("0\n");
    return 0;
  }

  for(i = 1; i < n_child; i++){
    scanf("%d ", &child);
    
    if(child == 1){
      t1.pb(i);
      size_1++;
    }

    else if(child == 2){
      t2.pb(i);
      size_2++;
    }

    else{
      t3.pb(i);
      size_3++;
    }
  }

  scanf("%d", &child);
  if(child == 1){
    t1.pb(i);
    size_1++;
  }

  else if(child == 2){
    t2.pb(i);
    size_2++;
  }

  else{
    t3.pb(i);
    size_3++;
  }

  int menor_1 = min(size_1, size_2);
  n_teams = min(menor_1, size_3);

  printf("%d\n", n_teams);

  if(!n_teams){
    return 0;
  }

  while(t1.size() != 0 && t2.size() != 0 && t3.size() != 0){
    printf("%d %d %d\n", t1[0], t2[0], t3[0]);
    t1.erase(t1.begin());
    t2.erase(t2.begin());
    t3.erase(t3.begin());
  }

  return 0;
}
