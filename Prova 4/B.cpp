#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>
#define matrix vector<vector<pll>>

const ll N = 100002;
const ll INFINITE = 1e18;

ll d[N];
ll n;

matrix g(N);

void dijkstra(ll s)
{
  ll v, w, dist_su, u;

  for (ll i = 0; i < N; i++)
  {
    d[i] = INFINITE;
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;

  d[s] = 0;

  pq.push(mp(d[s], s));

  while (!pq.empty())
  {
    tie(dist_su, u) = pq.top();
    pq.pop();

    for (auto edge : g[u])
    {
      tie(v, w) = edge;

      if (w + d[u] < d[v])
      {
        d[v] = d[u] + w;
        pq.push(mp(d[v], v));
      }
    }
  }
}

int main()
{

  ll m, v1, v2, w, src, dst;

  scanf("%lli %lli %lli %lli", &n, &m, &src, &dst);

  for (ll i = 0; i < m; i++)
  {
    scanf("%lli %lli %lli", &v1, &v2, &w);
    g[v1].pb(mp(v2, w));
    g[v2].pb(mp(v1, w));
  }

  int start = src;

  dijkstra(start);

  if (d[dst] < INFINITE)
  {
    printf("%lli\n", d[dst]);
  }

  else
  {
    printf("-1\n");
  }

  return 0;
}
