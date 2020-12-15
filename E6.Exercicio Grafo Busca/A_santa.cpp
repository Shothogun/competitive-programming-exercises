#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<ii>>

int main()
{

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int N, A, a, b, t;
  matrix graph(1003);
  queue<int> q;

  scanf("%d %d", &N, &A);

  vector<bool> visited(N + 1, false);

  for (int i = 0; i < A; i++)
  {
    scanf("%d %d %d", &a, &b, &t);

    if (a != b)
    {
      graph[a].pb(mp(b, t));
      graph[b].pb(mp(a, t));
    }
  }

  q.push(1);
  visited[1] = true;
  int valid=1;

  while (q.size())
  {
    int u = q.front();
    q.pop();

    for (ii v : graph[u])
    {
      int index = v.first;
      int T = v.second;
      if (visited[index] != true && T >= 0)
      {
        q.push(index);
        visited[index] = true;
        valid++;
      }
    }
  }

  printf("%d\n", N-valid);

  return 0;
}
