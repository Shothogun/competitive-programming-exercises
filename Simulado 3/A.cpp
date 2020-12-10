#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<int>>

int domain[505][505];
matrix g(505);
vector<bool> visited(505, false);
vector<bool> new_visited(505, false);

void dfs(int u)
{
  visited[u] = true;

  for (auto v : g[u])
  {
    if (!visited[v])
    {
      dfs(v);
    }
  }
}

void dfs_remove(int u, int r)
{
  new_visited[u] = true;
  for (auto v : g[u])
  {
    if (!new_visited[v] && v != r)
    {
      dfs_remove(v, r);
    }
  }
}

int main()
{

  int N, M, Q, v1, v2, v, w, med, dst;
  scanf("%d %d %d", &N, &M, &Q);

  for (int i = 0; i < M; i++)
  {
    scanf("%d %d", &v1, &v2);

    if (v1 != v2)
    {
      g[v1].pb(v2);
    }
  }

  dfs(1);

  while (Q--)
  {
    scanf("%d %d", &med, &dst);

    for (int i = 0; i < 505; i++)
    {
      new_visited[i] = false;
    }

    dfs_remove(1, med);

    if (med == 1 && visited[dst] == true)
    {
      printf("sim\n");
    }

    else if (med == dst && visited[dst] == true)
    {
      printf("sim\n");
    }

    else if (visited[dst] == true && new_visited[dst] == false)
    {
      printf("sim\n");
    }

    else
    {
      printf("nao\n");
    }
  }

  return 0;
}
