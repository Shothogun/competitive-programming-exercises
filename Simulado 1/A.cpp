#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  /* Insira o codigo-fonte aqui */

  ll x, y, z;
  ll vx=0,vy=0,vz=0;
  ll N;

  scanf("%lli", &N);

  for(ll i = 0; i < N; i++){
    scanf("%lli %lli %lli", &x, &y, &z);
    vx+=x;
    vy+=y;
    vz+=z;
  }

  if(vx == 0 && vy == 0 && vz == 0){
    printf("YES\n");
  }

  else{
    printf("NO\n");
  }

  return 0;
}
