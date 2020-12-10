#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
      
  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  int n,f,p,i, element,
  counter = 1, time = 0;
  queue<int> q;

  scanf("%d %d %d", &n, &f, &p);  
  for(i = 0; i<n-1;i++){
    scanf("%d ", &element);
    q.push(element);
  }

  scanf("%d", &element);
  q.push(element);

  while(!q.empty()){
    // Analise
    if(f == 1 || counter == 1){
      auto f = q.front();
      if(f <= p){
        time += 5;
        q.pop();
      }
      else{
        time += 10;
        q.pop();
        q.push(f-2);
      }
    }

    else if(counter != 1){
      q.pop();
      time += 1;
    }

    
    if(f > 1) {
      counter++;
      counter %= f;
      }
  }

  printf("%d\n", time);

  return 0;
}
