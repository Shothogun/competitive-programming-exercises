#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>
#define matrix vector<vector<pll>>
#define DEBUG 0

const ll N = 100002;
const ll INFINITE = 1e18;

ll d[N];
ll predecessors[N];
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
  predecessors[s] = s;

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
        predecessors[v] = u;
        pq.push(mp(v, d[v]));
      }
    }
  }
}

int main()
{
  char element;
  ll s, q, m;
  ll court[201][201];
  map<char, ll> getWeight;

  getWeight['.'] = 1;
  getWeight['A'] = 5;
  getWeight['M'] = INFINITE;

  scanf("%lli %lli", &n, &m);
  getchar();

  ll x_limit = m;
  ll y_limit = 1 + (n - 1) * m;

  for (ll i = 1; i <= n * m; i++)
  {
    scanf("%c", &element);

    if (i % x_limit != 0)
    {
      g[i].pb(mp(i + 1, getWeight[element]));
      g[i + 1].pb(mp(i, INFINITE));
    }

    if (i < y_limit)
    {
      g[i].pb(mp(i + m, getWeight[element]));
      g[i + m].pb(mp(i, INFINITE));
    }

    if(i % x_limit == 0)
    {
      getchar();
    }

  }

  int start = 1;

  dijkstra(start);

  printf("%lli\n", d[n * m]);

  return 0;
}
