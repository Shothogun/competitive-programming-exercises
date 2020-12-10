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
  ll N, M, element, t, l, r;

  scanf("%lli %lli", &N, &M);

  vector<ll> v(N, 0), u(N, 0), psum(N, 0), psum_sorted(N, 0);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli", &element);
    v[i] = element;
    u[i] = element;
  }

  sort(u.begin(), u.end());

  psum[0] = v[0];
  psum_sorted[0] = u[0];

  for (ll i = 1; i < N; i++)
  {
    psum[i] = v[i] + psum[i - 1];
    psum_sorted[i] = u[i] + psum_sorted[i - 1];
  }

  for (ll i = 0; i < M; i++)
  {
    scanf("%lli %lli %lli", &t, &l, &r);
    l--;
    r--;

    if (l == 0)
    {
      t == 1 ? printf("%lli\n", psum[r]) : printf("%lli\n", psum_sorted[r]);
    }

    else
    {
      t == 1 ? printf("%lli\n", psum[r] - psum[l - 1]) : printf("%lli\n", psum_sorted[r] - psum_sorted[l - 1]);
    }
  }

  return 0;
}
