#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<int>>

int main()
{

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  queue<ii> q;
  int C, E, L, P, a, b;

  scanf("%d %d %d %d", &C, &E, &L, &P);

  vector<bool> visited(C + 1, false);
  matrix graph(C + 1);

  for (int i = 0; i < E; i++)
  {
    scanf("%d %d", &a, &b);
    if (a != b)
    {
      graph[a].pb(b);
      graph[b].pb(a);
    }
  }

  q.push(mp(L, 0));
  visited[L] = true;

  while (q.size())
  {
    ii u = q.front();
    int cidade = u.first;
    int toll = u.second;
    q.pop();

    if (toll >= P)
      break;

    for (int adj : graph[cidade])
    {
      if (visited[adj] != true && toll <= P)
      {
        q.push(mp(adj, toll + 1));
        visited[adj] = true;
      }
    }
  }

  for (int city = 1; city <= C; city++)
  {
    if (visited[city] == true && city != L)
    {
      printf("%d ", city);
    }
  }

  printf("\n");

  return 0;
}
