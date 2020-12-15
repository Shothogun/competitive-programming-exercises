#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAX 100001

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  /* Insira o codigo-fonte aqui */

  ll n, q, m, price;
  vector<ll> x(MAX, 0);

  scanf("%lli", &n);

  for (ll i = 0; i < n; i++)
  {
    scanf("%lli", &price);
    x[price]++;
  }

  for (ll i = 1; i < MAX; i++)
  { 
    x[i] += x[i-1];
  }

  scanf("%lli", &q);

  for(ll i = 0; i<q; i++){
    scanf("%lli", &m);

    if(m > MAX){
      printf("%lli\n", n);
      continue;  
    }

    printf("%lli\n", x[m]);
  }

  return 0;
}
