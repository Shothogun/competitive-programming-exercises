#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 10e9
#define DEBUG 1

ll spendings[205][25];
vector<vector<ll>> prices(25);
ll V, C, layer=-1;

ll spendCompute(ll spent, ll part)
{
  ll spend = -1, flag = 0;

  if (spent > V || part >= C)
  {
    return 0;
  }

  if (spendings[spent][part] != -1)
  {
    return spendings[spent][part];
  }

  for (ll price : prices[part])
  {
    if (spent + price <= V)
    {
      layer = max(layer,part+1);
      spend = max(spend, price + spendCompute(spent + price, part + 1));
    }
  }


  return spendings[spent][part] = spend;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(spendings, -1, sizeof(spendings));

  ll element, K;

  cin >> V >> C;

  for (ll i = 0; i < C; i++)
  {
    cin >> K;

    while (K--)
    {
      cin >> element;
      prices[i].pb(element);
    }
  }

  spendCompute(0, 0);

  ll ans = -INFINITE;

  for (ll i = 0; i < 25; i++)
  {
    ans = max(ans, spendings[0][i]);
  }

  if(layer < C)
  {
    cout << "-1\n";
  }
  else
  {
    cout << ans<< "\n";
  }

  return 0;
}
