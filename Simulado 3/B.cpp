#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>
#define matrix vector<vector<pll>>
#define MAX 100000
const ll INFINITE = 1e18;

ll D[MAX][MAX];
ll n;

int main()
{
  ll m, v1, v2, w, source, P, dst;

  scanf("%lli %lli", &n, &m);

  scanf("%lli %lli %lli", &source, &dst, &P);

  for (int i = 1; i < n+1; i++)
  {
    for (int j = 1; j < n+1; j++)
    {
      if (i == j)
      {
        D[i][j] = 0;
      }

      else
      {
        D[i][j] = -INFINITE;
      }
    }
  }

  for (ll i = 0; i < m; i++)
  {
    scanf("%lli %lli %lli", &v1, &v2, &w);

    if (v1 != v2)
    {
      D[v1][v2] = w - 1;
      D[v2][v1] = w - 1;
    }
  }

  for (int k = 1; k < n+1; k++)
  {
    for (int i = 1; i < n+1; i++)
    {
      for (int j = 1; j < n+1; j++)
      {
        D[i][j] = max(D[i][j], min(D[i][k], D[k][j]));
      }
    }
  }

  int min_travel = ceil((double)P / (double)D[source][dst]);

  printf("%d\n", min_travel);

  return 0;
}
