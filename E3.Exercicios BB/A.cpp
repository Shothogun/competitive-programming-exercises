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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vi v;
    int n,q,element;

    scanf("%d %d", &n,&q);

    for(int i = 0; i < n; i++){
      scanf("%d", &element);
      v.pb(element);
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < q; i++){
      scanf("%d", &element);
      auto u = lower_bound(v.begin(), v.end(), element);
      if(u != v.end()){
        printf("%d\n", *u);
      }
      else{
        printf("-1\n");
      }
    }

    return 0;
}
