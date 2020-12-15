#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 10e9
#define DEBUG 1

ll profit[200005][2];
vector<ll> values(200005, -1);
ll N, C, day_profit;

ll profitCompute(ll day, ll invest)
{
  ll max_profit, do_invest, dont_invest;

  if (day >= N)
  {
    return 0;
  }

  if (profit[day][invest] != -1)
  {
    return profit[day][invest];
  }

  if (invest == 1)
  {
    do_invest = values[day] + profitCompute(day + 1, 0);
    dont_invest = profitCompute(day + 1, 1);
  }

  else
  {
    do_invest = profitCompute(day + 1, 1) - values[day] - C;
    dont_invest = profitCompute(day + 1, 0);
  }

  max_profit = max(dont_invest, do_invest);

  return profit[day][invest] = max_profit;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(profit, -1, sizeof(profit));

  ll element;

  cin >> N >> C;

  for (ll i = 0; i < N; i++)
  {
    cin >> element;
    values[i] = element;
  }

  cout << profitCompute(0, 0) << "\n";

  return 0;
}
