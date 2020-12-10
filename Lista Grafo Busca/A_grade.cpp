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
  int N, E, Q, v1, v2, t, x;
  queue<int> q;

  scanf("%d %d %d", &N, &E, &Q);

  matrix graph(N+2);
  vector<ll> inputEdges(N+2, 0);

  for (int i = 0; i < E; i++)
  {
    scanf("%d %d", &v1, &v2);

    graph[v1].pb(v2);
    inputEdges[v2]++;
  }

  for (int i = 0; i < Q; i++)
  {
    scanf("%d %d", &t, &x);
    if (t == 1)
    {
      printf("%lu\n", graph[x].size());
    }

    else
    {
      printf("%lli\n", inputEdges[x]);
    }
  }

  return 0;
}
