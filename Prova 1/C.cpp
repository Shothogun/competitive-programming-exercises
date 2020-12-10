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

  ll N, M, Q, element;
  ll l, r, x, m;

  scanf("%lli %lli %lli", &N, &M, &Q);

  vector<ll> a(N, 0), delta(N, 0);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli", &element);
    a[i] = element;
  }

  for (ll i = 0; i < Q; i++)
  {
    scanf("%lli %lli %lli %lli", &l, &r, &x, &m);
    l--;
    r--;

    if (m <= 5)
    {
      delta[l] += x;

      if (r < N - 1)
      {
        delta[r + 1] -= x;
      }
    }
  }

  for (ll i = 1; i < N; i++)
  {
    delta[i] += delta[i - 1];
  }

  for (ll i = 0; i < N; i++)
  {
    a[i] += delta[i];
    cout << a[i] << ' ';
  }


  cout << endl;


  return 0;
}
