#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 1e9;
ll T, MIN, MAX;
ll mem[55][100005];

ll calcNDiffExercices(ll time_left, ll level)
{
  ll up = 0, down = 0;

  if (time_left <= 1)
  {
    return 1;
  }

  if(mem[time_left][level] != -1)
  {
    return mem[time_left][level];
  }

  if (level < MAX && time_left-1 > 0)
  {
    up = calcNDiffExercices(time_left - 1, level + 1)%1000000007;
  }

  if (level > MIN && time_left-1 > 0)
  {
    down = calcNDiffExercices(time_left - 1, level - 1)%1000000007;
  }

  mem[time_left][level] = up%1000000007 + down%1000000007;
  mem[time_left][level] %= 1000000007;

  return mem[time_left][level];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(mem, -1, sizeof(mem));

  cin >> T >> MAX >> MIN;

  ll total = 0;

  for (ll i = MIN; i <= MAX; i++)
  {
    total += calcNDiffExercices(T, i)%1000000007;
  }

  cout << total%1000000007 << "\n";

  return 0;
}