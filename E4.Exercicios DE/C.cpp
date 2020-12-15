#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAX_TEMP 200000

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  /* Insira o codigo-fonte aqui */

  ll l, r, n, q, x, k, element, a, b;

  scanf("%lli %lli %lli", &n, &k, &q);

  vector<ll> delta(MAX_TEMP, 0), v(MAX_TEMP, 0), counter(MAX_TEMP, 0);

  for (ll i = 0; i < n; i++)
  {
    scanf("%lli %lli", &l, &r);
    delta[l]++;

    if (r != MAX_TEMP-1)
    {
      delta[r + 1]--;
    }
  }

  ll current = 0;

  for (ll i = 0; i < MAX_TEMP; i++)
  {
    current += delta[i];
    v[i] = current;
  }

  for (ll i = 0; i < MAX_TEMP; i++)
  {
    v[i] /= k;
    if (v[i] > 0)
    {
      counter[i]++;
    }
  }

  for (ll i = 1; i < MAX_TEMP; i++)
  {
    counter[i] += counter[i - 1];
  }

  // for (ll i = 90; i < 101; i++)
  // {
  //   printf("%lli ", counter[i]);
  // }
  // printf("\n");

  for (ll i = 0; i < q; i++)
  {
    scanf("%lli %lli", &a, &b);
    if (a == 0)
    {
      printf("%lli\n", counter[b]);
    }
    else{
      printf("%lli\n", counter[b] - counter[a-1]);
    }
  }

  return 0;
}
