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
  ll n, q, t, l, r, x;
  scanf("%lli %lli %lli", &n, &q, &t);

  vector<ll> delta(n, 0), a(n, 0);

  for (ll i = 0; i < q; i++)
  {
    scanf("%lli %lli %lli", &l, &r, &x);
    l--;
    r--;
    delta[l] += x;
    if (r < n - 1)
    {
      delta[r + 1] -= x;
    }
  }

  ll atual = 0;

  for (ll i = 0; i < n; i++)
  {
    atual += delta[i];
    a[i] = atual;
  }

  sort(a.begin(), a.end());

  auto begin = lower_bound(a.begin(), a.end(), t);
  printf("%li\n", distance(begin, a.end()));

  return 0;
}
