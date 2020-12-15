#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 1e9;
ll costs[1000][1000];
vector<ll> p;
vector<ll> v;
ll W, N;

ll minCost(ll i, ll c)
{
  ll pegar=-INFINITE
  ll n_pegar;

  if (i <= 0 || c <= 0)
  {
    return 0;
  }

  if (costs[i][c] != -1)
  {
    return costs[i][c];
  }

  if (p[i] <= c)
  {
    pegar = v[i] + minCost(i - 1, c - p[i]);
  }

  n_pegar = minCost(i - 1, c);

  return costs[i][c] = max(pegar, n_pegar);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll element;

  cin >> W >> N;

  for (ll i = 0; i <= N; i++)
  {
    for (ll j = 0; j <= W; j++)
    {
      costs[i][j] = -1;
    }
  }

  p.pb(0);
  for (ll i = 0; i < N; i++)
  {
    cin >> element;
    p.pb(element);
  }

  v.pb(0);
  for (ll i = 0; i < N; i++)
  {
    cin >> element;
    v.pb(element);
  }

  cout << minCost(N, W) << "\n";

  return 0;
}
