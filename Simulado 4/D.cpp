#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 1e9;
ll mem[10005][805];
ll gas_station[10005];
ll price[10005];
ll TOTAL_DISTANCE, N_GAS_STATION, K_CAPACITY;

ll travelCost(ll current, ll last_one, ll capacity)
{
  ll full = INFINITE;
  ll bypass = INFINITE;
  ll distance_driven = gas_station[current] - gas_station[last_one];
  ll next_distance = gas_station[current + 1] - gas_station[current];
  ll new_capacity = capacity - (gas_station[current] - gas_station[current-1]);

  if (current > N_GAS_STATION+1 && capacity > 0)
  {
    return 0;
  }

  else if (current > N_GAS_STATION+1 && capacity <= 0)
  {
    return INFINITE;
  }

  if (mem[current][capacity] != -1)
  {
    return mem[current][capacity];
  }

  if(current > 0 && current <= N_GAS_STATION
    && next_distance < K_CAPACITY)
  {
    full = distance_driven * price[current] +
          travelCost(current + 1, current, K_CAPACITY);
  }

  if (next_distance < new_capacity)
  {
    bypass = travelCost(current + 1, last_one, new_capacity);
  }

  return mem[current][capacity] = min(full, bypass);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll element;

  memset(mem, -1, sizeof(mem));

  cin >> TOTAL_DISTANCE >> N_GAS_STATION >> K_CAPACITY;

  gas_station[0] = 0;
  for (ll i = 1; i <= N_GAS_STATION; i++)
  {
    cin >> element;
    gas_station[i] = element;
  }
  gas_station[N_GAS_STATION + 1] = TOTAL_DISTANCE;

  price[0] = 0;
  for (ll i = 1; i <= N_GAS_STATION; i++)
  {
    cin >> element;
    price[i] = element;
  }
  price[N_GAS_STATION + 1] = 0;

  ll result = travelCost(0, 0, K_CAPACITY);

  if (result < 1e9)
  {
    cout << result << "\n";
  }

  else
  {
    cout << "-1"
         << "\n";
  }

  return 0;
}