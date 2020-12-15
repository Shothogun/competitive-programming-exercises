#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>
#define matrix vector<vector<pll>>
#define DEBUG 1

const ll N = 255;
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

  pq.push(mp(s, d[s]));

  while (!pq.empty())
  {
    tie(u, dist_su) = pq.top();
    pq.pop();

    for (auto edge : g[u])
    {
      tie(v, w) = edge;

      if (w + d[u] < d[v])
      {
        d[v] = d[u] + w;
        pq.push(mp(v, d[v]));
      }
    }
  }
}

int main()
{

  ll N, M, C, K, U, V, P;
  ll least, greater;

  scanf("%lli %lli %lli %lli", &N, &M, &C, &K);

  for (ll i = 0; i < M; i++)
  {
    scanf("%lli %lli %lli", &U, &V, &P);
    least = min(U, V);
    greater = max(U, V);

    if (least <= C && greater > C)
    {
      g[greater].pb(mp(least, P));
      g[least].pb(mp(greater, INFINITE));
    }

    else if (least <= C && greater <= C && greater == least + 1)
    {
      g[least].pb(mp(greater, P));
      g[greater].pb(mp(least, INFINITE));
    }

    else if (least <= C && greater <= C && greater != least + 1)
    {
      continue;
    }

    else
    {
      g[U].pb(mp(V, P));
      g[V].pb(mp(U, P));
    }
  }

  int start = K;

  dijkstra(start);

  printf("%lli\n", d[C]);

  return 0;
}
