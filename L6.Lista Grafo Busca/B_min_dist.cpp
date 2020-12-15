#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<ll>>

int main()
{
  ll N, M, Q, X, v1, v2, K;

  scanf("%lli %lli", &N, &M);
  scanf("%lli %lli", &K, &Q);

  matrix graph(N + 1);
  vector<bool> visited(N + 1, false);
  vector<ll> dist(N + 1, 0);
  queue<ll> q;

  while (M--)
  {
    scanf("%lli %lli", &v1, &v2);
    if (v1 != v2)
    {
      graph[v1].pb(v2);
      graph[v2].pb(v1);
    }
  }

  q.push(K);
  visited[K] = true;

  while (q.size())
  {
    ll u = q.front();
    q.pop();

    for (auto adj : graph[u])
    {
      if (visited[adj] == false)
      {
        visited[adj] = true;
        q.push(adj);

        dist[adj] = dist[u] + 1;
      }
    }
  }

  while (Q--)
  {
    scanf("%lli", &X);

    if (dist[X] == 0 && X != K)
    {
      printf("infinito\n");
    }
    else
    {
      printf("%lli\n", dist[X]);
    }
  }

  return 0;
}
