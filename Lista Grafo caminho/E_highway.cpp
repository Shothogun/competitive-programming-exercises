#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>
#define matrix vector<vector<pair<ll, pll>>>
#define DEBUG 1

const ll N = 10001;
const ll INFINITE = 1e18;

ll predecessor_cost[N];
ll d[N];
ll c[N];
ll n;
ll total_cost = 0;

matrix g(N);

void dijkstra(ll s)
{
  ll v, w, u, dist_su;
  pll weights;

  for (ll i = 0; i < N; i++)
  {
    d[i] = INFINITE;
    c[i] = INFINITE;
    predecessor_cost[i] = 0;
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;

  d[s] = 0;
  c[s] = 0;
  predecessor_cost[s] = 0;

  pq.push(mp(d[s],s));

  while (!pq.empty())
  {
    tie(dist_su,u) = pq.top();
    pq.pop();

    for (auto edge : g[u])
    {
      tie(v, weights) = edge;
      int w = weights.first;
      int cost = weights.second;

      if (w + d[u] < d[v])
      {
        d[v] = d[u] + w;
        c[v] = cost;
        pq.push(mp(d[v], v));
      }

      else if (w + d[u] == d[v] &&
               cost < c[v])
      {
        c[v] = cost;
      }
    }
  }
}

int main()
{

  ll N, M, A, B, L, C;
  ll least, greater;

  scanf("%lli %lli", &N, &M);

  for (ll i = 0; i < M; i++)
  {
    scanf("%lli %lli %lli %lli", &A, &B, &L, &C);
    if (A != B)
    {
      g[A].pb(mp(B, mp(L, C)));
      g[B].pb(mp(A, mp(L, C)));
    }
  }

  int start = 1;

  dijkstra(start);

  for(auto i : c)
  {
    if(i < INFINITE)
    {
      total_cost += i; 
    }
  }

  printf("%lli\n", total_cost);

  return 0;
}
