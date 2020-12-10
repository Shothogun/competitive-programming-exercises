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
vector<vector<ll>> visitors(N);

void dijkstra(ll s)
{
  ll v, w, dist_su, u, instant;

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

    instant = dist_su;

    for (int visit_time : visitors[u])
    {
      if (instant == visit_time)
      {
        instant++;
      }
    }

    for (auto edge : g[u])
    {
      tie(v, w) = edge;

      if (w + instant < d[v])
      {
        d[v] = instant+ w;
        pq.push(mp(d[v], v));
      }
    }
  }
}

int main()
{

  ll m, v1, v2, w;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (ll i = 0; i < m; i++)
  {
    cin >> v1 >> v2 >> w;
    g[v1].pb(mp(v2, w));
    g[v2].pb(mp(v1, w));
  }

  int n_visitors;
  int visit_time;

  for (ll i = 1; i < n; i++)
  {
    cin >> n_visitors;
    for (ll j = 0; j < n_visitors; j++)
    {
      cin >> visit_time;
      visitors[i].pb(visit_time);
    }
  }

  int start = 1;

  dijkstra(start);

  if(d[n] == INFINITE)
  {
    cout << "-1\n";
  }

  else
  {
    cout << d[n] << "\n";
  }


  return 0;
}
