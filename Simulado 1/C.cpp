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

  ll N, Q, x, y;
  ll l_ans = -1, r_ans = -1;
  vector<ll> A;

  scanf("%lli %lli", &N, &Q);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli %lli", &x, &y);
    for (ll j = x; j <= y; j++)
    {
      A.pb(j);
    }
  }

  // for (auto u = A.begin(); u != A.end(); ++u)
  // {
  //   printf("%lli ", *u);
  // }

  // printf("\n");

  sort(A.begin(), A.end());

  ll l = 0;
  ll r = A.size()-1;
  ll m;

  while (l <= r)
  {
    m = (r + l) / 2;

    if (A[m] >= Q)
    {
      l_ans = m;
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }

  l = 0;
  r = A.size()-1;

  while (l <= r)
  {
    m = (r + l) / 2;

    if (A[m] <= Q)
    {
      r_ans = m;
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }

  if (r_ans == -1 || l_ans == -1)
  {
    printf("-1\n");
  }

  else
  {
    printf("%lli %lli \n", l_ans, r_ans);
  }

  return 0;
}
