#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

ll payable[100005];
vector<ll> values(1005, -1);
ll V, M;

ll isPayable(ll V, ll start)
{
  if (V == 0)
  {
    return 1;
  }

  if (payable[V] != -1)
  {
    return payable[V];
  }

  for (ll i = start; i < M; i++)
  {
    if (values[i] <= V)
    {
      payable[V] = isPayable(V - values[i], i + 1);
    }

    if(payable[V] != -1)
    {
      break;
    }
  }

  return payable[V];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll element;

  cin >> V >> M;
  memset(payable, -1, sizeof(payable));

  for (ll i = 0; i < M; i++)
  {
    cin >> element;
    values[i] = element;
  }

  sort(values.begin(), values.begin() + M, greater<ll>());

  isPayable(V, 0);

  if (payable[V] != -1)
  {
    cout << "S\n";
  }

  else
  {
    cout << "N\n";
  }

  return 0;
}
