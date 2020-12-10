#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<int>>
#define DEBUG 0

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  queue<int> q;
  set<int> v_visited;
  int V, E, n_subgraphs = 1;
  int v1, v2;

  cin >> V >> E;

  matrix graph(V + 2);
  vector<bool> visited(V + 2, false);

  for (int i = 1; i <= V; i++)
  {
    v_visited.insert(i);
  }

  while (E--)
  {
    cin >> v1 >> v2;

    if (v1 != v2)
    {
      graph[v1].pb(v2);
      graph[v2].pb(v1);
    }
  }

  q.push(1);
  visited[1] = true;
  v_visited.erase(1);

  while (q.size())
  {
    int u = q.front();
    q.pop();
    v_visited.erase(u);

    for (int adj : graph[u])
    {
      if (visited[adj] == false)
      {
        visited[adj] = true;
        q.push(adj);

        if (DEBUG)
        {
          cout << "Vertice:" << adj << endl;
        }
      }
    } // for

    if (q.empty() && !v_visited.empty())
    {
      n_subgraphs++;

      if (DEBUG)
      {
        cout << "N Vert:" << n_subgraphs << endl;
      }

      q.push(*(v_visited.begin()));
    }
  } // while

  cout << n_subgraphs << '\n';

  return 0;
}