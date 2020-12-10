#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>
#define matrix vector<vector<pll>>
#define MAX 100
const ll INFINITE = 1e18;

ll D[MAX][MAX];
ll n;

int main()
{
  ll m, v1, v2;

  scanf("%lli %lli", &n, &m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        D[i][j] = 0;
      }

      else
      {
        D[i][j] = INFINITE;
      }
    }
  }

  for (ll i = 0; i < m; i++)
  {
    scanf("%lli %lli", &v1, &v2);

    if (v1 != v2)
    {
      D[v1][v2] = 1;
      D[v2][v1] = 1;
    }
  }

  ll start, rendezvous;
  scanf("%lli %lli", &start, &rendezvous);

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }

  ll min_trail = -INFINITE;

  for(int i = 0; i < n; i++)
  {
    min_trail = max(min_trail, D[start][i] + D[i][rendezvous]);
  }

  printf("%lld\n", min_trail);

  return 0;
}
