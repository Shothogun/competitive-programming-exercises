#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, size, X, Y, apply_x, apply_y;
  vector<bool> visited(100005, false);
  queue<pair<int, ii>> q;

  cin >> N >> M;

  q.push(mp(N, mp(0, 0)));
  visited[N] = true;

  while (!q.empty())
  {
    pair<int, ii> u = q.front();
    size = u.first;
    X = u.second.first;
    Y = u.second.second;
    q.pop();

    apply_x = size * 2;
    apply_y = size - 1;

    if (size == M)
    {
      break;
    }

    if (apply_x <= 100000)
    {
      if (visited[apply_x] == false)
      {
        q.push(mp(apply_x, mp(X + 1, Y)));
        visited[apply_x] = true;
      }
    }

    if (apply_y >= 1)
    {
      if (visited[apply_y] == false)
      {
        q.push(mp(apply_y, mp(X, Y + 1)));
        visited[apply_y] = true;
      }
    }
  }

  cout << X + Y << "\n";

  return 0;
}
