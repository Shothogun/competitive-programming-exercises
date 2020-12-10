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

const ll N = 27;
const ll INFINITE = 1e18;

ll d_ober[N];
ll d_taxi[N];
ll d_conj[N];
ll n;

matrix g_ober(N);
matrix g_taxi(N);

void dijkstra_taxi(ll s, matrix g)
{
  ll v, w, dist_su, u;
  ll cost = INFINITE;

  for (ll i = 0; i < N; i++)
  {
    d_taxi[i] = INFINITE;
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;

  d_taxi[s] = 0;

  pq.push(mp(s, d_taxi[s]));

  while (!pq.empty())
  {
    tie(u, dist_su) = pq.top();
    pq.pop();

    for (auto edge : g[u])
    {
      tie(v, w) = edge;

      if (w + d_taxi[u] < d_taxi[v])
      {
        d_taxi[v] = d_taxi[u] + w;
        pq.push(mp(v, d_taxi[v]));
      }
    }
  }
}

void dijkstra_ober(ll s, matrix g)
{
  ll v, w, dist_su, u;
  ll cost = INFINITE;

  for (ll i = 0; i < N; i++)
  {
    d_ober[i] = INFINITE;
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;

  d_ober[s] = 0;

  pq.push(mp(s, d_ober[s]));

  while (!pq.empty())
  {
    tie(u, dist_su) = pq.top();
    pq.pop();

    for (auto edge : g[u])
    {
      tie(v, w) = edge;

      if (w + d_ober[u] < d_ober[v])
      {
        d_ober[v] = d_ober[u] + w;
        pq.push(mp(v, d_ober[v]));
      }
    }
  }
}

int main()
{
  char type, direction, city1, city2;
  ll total_cost = INFINITE, cost;
  ll N;

  scanf("%lli", &N);
  getchar();

  for (ll i = 0; i < N; i++)
  {
    scanf("%c %c %c %c %lli", &type, &direction, &city1, &city2, &cost);

    if (type == 'O')
    {
      g_ober[city1 - 'A'].pb(mp(city2 - 'A', cost));

      if (direction == 'B')
      {
        g_ober[city2 - 'A'].pb(mp(city1 - 'A', cost));
      }

      else
      {
        g_ober[city2 - 'A'].pb(mp(city1 - 'A', INFINITE));
      }
    }

    else
    {
      g_taxi[city1 - 'A'].pb(mp(city2 - 'A', cost));

      if (direction == 'B')
      {
        g_taxi[city2 - 'A'].pb(mp(city1 - 'A', cost));
      }

      else
      {
        g_taxi[city2 - 'A'].pb(mp(city1 - 'A', INFINITE));
      }
    }
    getchar();
  }

  char start_ober;
  char start_taxi;

  scanf("%c %c", &start_ober, &start_taxi);

  dijkstra_ober(start_ober - 'A', g_ober);
  dijkstra_taxi(start_taxi - 'A', g_taxi);

  for (ll i = 0; i < 26; i++)
  {
    if (DEBUG)
    {
      printf("%lli %lli\n", d_ober[i], d_taxi[i]);
    }
    if (d_ober[i] < INFINITE && d_taxi[i] < INFINITE)
    {
      total_cost = min(total_cost, d_ober[i] + d_taxi[i]);
    }
  }

  for (ll i = 0; i < 26; i++)
  {
    if (d_ober[i] < INFINITE && d_taxi[i] < INFINITE)
    {
      total_cost = min(total_cost, d_ober[i] + d_taxi[i]);
    }
  }

  if (total_cost == INFINITE)
  {
    printf("-1\n");
  }

  else
  {
    printf("%lli\n", total_cost);

    for (ll i = 0; i < 26; i++)
    {
      if (d_ober[i] + d_taxi[i] == total_cost)
      {
        printf("%c ", 'A' + i);
      }
    }
    printf("\n");
  }

  return 0;
}
