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

  ll l, r, n, q, element;

  scanf("%lli %lli", &n, &q);

  vector<ll> a(n, 0), psum(n, 0);

  for (ll i = 0; i < n; i++)
  {
    scanf("%lli", &element);
    a[i] = element;
  }

  psum[0] = a[0];

  for (ll i = 1; i < n; i++)
  {
    psum[i] = a[i] + psum[i - 1];
  }

  for (ll i = 0; i < q; i++)
  {
    scanf("%lli %lli", &l, &r);
    if (l == 1)
    {
      printf("%lli\n", psum[r - 1]);
    }
    else
    {
      printf("%lli\n", psum[r - 1] - psum[l - 2]);
    }
  }

  return 0;
}
