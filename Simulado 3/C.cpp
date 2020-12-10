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

  int O, D, K, channel, clicks, jump = 0;
  queue<ii> q;

  scanf("%d %d %d", &O, &D, &K);
  vector<bool> visited(100000, false);
  vector<int> forbiden;

  while (K--)
  {
    scanf("%d", &channel);
    forbiden.pb(channel);
  }

  q.push(mp(O, 0));
  visited[O] = true;

  while (q.size())
  {
    ii u = q.front();
    channel = u.first;
    clicks = u.second;
    jump = 0;
    q.pop();

    for (int i = 0; i < forbiden.size(); i++)
    {
      if (channel == forbiden[i])
      {
        jump = 1;
        break;
      }
    }

    if (jump)
    {
      continue;
    }

    if (channel == D)
    {
      break;
    }

    if (channel * 2 <= 100000 && visited[channel * 2] == false)
    {
      q.push(mp(channel * 2, clicks + 1));
      visited[channel * 2] = true;
    }

    if (channel * 3 <= 100000 && visited[channel * 3] == false)
    {
      q.push(mp(channel * 3, clicks + 1));
      visited[channel * 3] = true;
    }

    if (channel + 1 <= 100000 && visited[channel + 1] == false)
    {
      q.push(mp(channel + 1, clicks + 1));
      visited[channel + 1] = true;
    }

    if (channel / 2 > 0 && channel % 2 == 0 && visited[channel / 2] == false)
    {
      q.push(mp(channel / 2, clicks + 1));
      visited[channel / 2] = true;
    }

    if (channel - 1 > 0 && visited[channel - 1] == false)
    {
      q.push(mp(channel - 1, clicks + 1));
      visited[channel - 1] = true;
    }
  }

  if (channel == D)
  {
    printf("%d\n", clicks);
  }

  else
  {
    printf("-1\n");
  }

  return 0;
}
