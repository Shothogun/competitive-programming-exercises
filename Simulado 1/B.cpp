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

  ll N, M, element, dist, ans;
  vector<ll> A;

  scanf("%lli %lli", &N, &M);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli", &element);
    A.pb(element);
  }

  ll l = 0;
  ll r = N - 1;
  ll m;

  sort(A.begin(), A.end());

  for (ll i = 0; i < M; i++)
  {
    scanf("%lli", &element);

    l = 0;
    r = N - 1;
    ans = 0;

    while (l <= r)
    {
      m = (r + l) / 2;

      if (A[m] > element)
      {
        ans = m;
        r = m - 1;
      }

      else
      {
        l = m + 1;
      }
    }

    if (ans == 0 && element > A[0])
    {
      printf("%lli ", N);
    }

    else
    {
      printf("%lli ", ans);
    }
  }

  printf("\n");

  return 0;
}
