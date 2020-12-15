#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 1e9;
ll N, X;
vll coins;
ll possibilities[10005];

ll coinsComb(ll tip)
{
  if (tip == 0)
  {
    return 1;
  }

  if (tip < 0)
  {
    return 0;
  }

  if (possibilities[tip] != -1)
  {
    return possibilities[tip];
  }

  ll n_comb = 0;

  for (ll i = 1; i <= N; i++)
  {
    if (coins[i] <= tip)
    {
      n_comb += coinsComb(tip - coins[i]);
    }
  }

  return possibilities[tip] = n_comb % 1000000007;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll element;
  cin >> N >> X;

  for (ll i = 0; i < 10005; i++)
  {
    possibilities[i] = -1;
  }

  coins.pb(0);
  for (ll i = 0; i < N; i++)
  {
    cin >> element;
    coins.pb(element);
  }

  sort(coins.begin(), coins.end());

  cout << coinsComb(X) % 1000000007 << "\n";

  return 0;
}
