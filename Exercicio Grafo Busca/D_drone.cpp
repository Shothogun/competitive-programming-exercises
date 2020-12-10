#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<int>>
#define DEBUG 1

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, position, n_ops;
  matrix graph(100000);
  vector<bool> visited(100000, false);
  queue<ii> q;

  cin >> N >> M;

  q.push(mp(N, 0));
  visited[N] = true;

  while (q.size())
  {
    ii u = q.front();
    q.pop();

    position = u.first;
    n_ops = u.second;

    if (position == M)
      break;

    if (position * 2 <= 100000 &&
        visited[position * 2] == false)
    {
      q.push(mp(position * 2, n_ops + 1));
      visited[position * 2] = true;
    }

    if (position + 1 <= 100000 &&
        visited[position + 1] == false)
    {
      q.push(mp(position + 1, n_ops + 1));
      visited[position + 1] = true;
    }

    if (position / 2 >= 1 &&
        visited[position / 2] == false &&
        position % 2 == 0)
    {
      q.push(mp(position / 2, n_ops + 1));
      visited[position / 2] = true;
    }

    if (position - 1 >= 1 &&
        visited[position - 1] == false)
    {
      q.push(mp(position - 1, n_ops + 1));
      visited[position - 1] = true;
    }
  }

  cout << n_ops << endl;

  return 0;
}