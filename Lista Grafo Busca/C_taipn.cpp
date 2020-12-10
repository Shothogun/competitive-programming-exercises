#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<ll>>
char pixels[501][501];
queue<ll> q;
set<ll> not_visited_v;
#define DEBUG 0

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  char character;
  ll n, m, areas = 0, u;

  cin >> n >> m;

  ll V = n * m;

  matrix graph(V + 1);
  vector<bool> visited(V+1, false);

  for (ll i = 1; i <= V; i++)
  {
    not_visited_v.insert(i);
  }

  for (ll i = 1; i <= n; i++)
  {
    cin >> s;

    for (ll j = 1; j <= m; j++)
    {
      pixels[i][j] = s[j - 1];

      // Right Adj.
      if (j < m)
      {
        graph[(i - 1) * m + j].pb((i - 1) * m + j + 1);
        graph[(i - 1) * m + j + 1].pb((i - 1) * m + j);
      }

      // Below Adj.
      if (i < n)
      {
        graph[(i - 1) * m + j].pb(i * m + j);
        graph[i * m + j].pb((i - 1) * m + j);
      }
    }
  }

  if (pixels[1][1] == '.')
  {
    areas = 1;
    q.push(1);
    visited[1] = true;
    not_visited_v.erase(1);
  }

  if (q.empty() && not_visited_v.size() > 0)
  {
    while (not_visited_v.size() > 0)
    {
      u = *(not_visited_v.begin());

      if (DEBUG)
      {
        cout << u / m << " " << u % m << endl;
      }

      if (pixels[(u - 1) / m + 1][(u - 1) % m + 1] == '#')
      {
        not_visited_v.erase(u);
      }

      else
      {
        areas++;
        q.push(u);
        break;
      }
    } //while erase #
  }   // if subgraph

  while (q.size())
  {
    u = q.front();
    q.pop();
    not_visited_v.erase(u);
    if (DEBUG)
    {
      cout << "FATHER: " << u << endl;
    }

    for (auto adj : graph[u])
    {
      if (visited[adj] == false)
      {
        visited[adj] = true;

        if (pixels[(adj - 1) / m + 1][(adj - 1) % m + 1] == '.')
        {
          if (DEBUG)
          {
            cout << "DOT: " << adj << endl;
          }
          q.push(adj);
        }

        else
        {
          if (DEBUG)
          {
            cout << "SHARP: " << (adj - 1) / m + 1 << " "
                 << (adj - 1) % m + 1 << endl;
          }
          not_visited_v.erase(adj);
        }
      }
    }

    if (q.empty() && not_visited_v.size() > 0)
    {
      while (not_visited_v.size() > 0)
      {
        u = *(not_visited_v.begin());

        if (DEBUG)
        {
          cout << u / m << " " << u % m << endl;
        }

        if (pixels[(u - 1) / m + 1][(u - 1) % m + 1] == '#')
        {
          not_visited_v.erase(u);
        }

        else
        {
          areas++;
          q.push(u);
          break;
        }
      } //while erase #
    }   // if subgraph
  }     // while queue

  cout << areas << '\n';

  return 0;
}
