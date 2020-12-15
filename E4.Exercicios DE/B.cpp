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

  ll l, r, n, q, x, element;

  scanf("%lli %lli", &n, &q);

  vector<ll> delta(n, 0), v(n,0);

  for(ll i=0; i < q; i++){
    scanf("%lli %lli %lli", &l, &r, &x);
    l--;
    r--;

    delta[l]+=x;

    if(r != n-1){
      delta[r+1]-=x;
    }
  }

  ll current=0;

  for(ll i = 0; i < n; i++){
    current += delta[i];
    v[i] = current;
  }

  for(ll i=0; i < n; i++){
    printf("%lli ", v[i]);
  }

  printf("\n");

  return 0;
}
