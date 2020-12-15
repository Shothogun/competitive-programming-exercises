#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

ll min_coins[1005];
vector<ll> values(1005, -1);
ll N;

ll return_min(ll X)
{
  if(X == 0)
  {
    return 0;
  }

  if(min_coins[X] != -1)
  {
    return min_coins[X];
  }

  ll best_choice=10e9;

  for(ll i = 0; i < N; i++)
  {
    if(values[i] <= X)
    {
      best_choice = min(best_choice, 1 + return_min(X-values[i]));
    }
  }

  return min_coins[X] = best_choice;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll X, element;

  cin >> N >> X;
  memset(min_coins, -1, sizeof(min_coins));
  
  for(ll i = 0; i < N; i++)
  {
    cin >> element;
    values[i] = element;
  }

  cout << return_min(X) << "\n";

  return 0;
}
