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
  ll n, S, element, l, r, k,m, result, cost=0;
  vector<ll> a,b;

  scanf("%lli %lli", &n, &S);
  for (ll i = 0; i < n; i++)
  {
    scanf("%lli", &element);
    a.pb(element);
    b.pb(element);
  }

  l = 1;
  r = n;
  k = 0;

  while (l <= r)
  {
    m = (r + l) / 2;
    result = 0;

    for (ll i = 0; i < n; i++){
      b[i] = a[i] + m*(i+1); 
    }

    sort(b.begin(), b.end());

    for (ll i = 0; i < m; i++){
      result += b[i]; 
    }

    if (result > S)
    {
      r = m - 1;
    }
    else
    {
      l = m + 1;
      k = m;
      cost = result;
    }
  }


  printf("%lli %lli\n", k, cost);

  return 0;
}
