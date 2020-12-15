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
  ll n, k, element;
  ll l, r, m, ans=0, counter;
  vector<ll> p;

  scanf("%lli %lli", &n, &k);

  for (int i = 0; i < n; i++)
  {
    scanf("%lli", &element);
    p.pb(element);
  }

  sort(p.begin(), p.end());

  l = 1;
  r = 100000000000000;

  while (l <= r)
  {
    m = (l + r) / 2;
    counter = 0;

    for (int i = 0; i < p.size(); i++)
    {
      counter += p[i] / m;
    }

    if (counter >= k)
    {
      ans = m;
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }

  printf("%lli\n", ans);

  return 0;
}
