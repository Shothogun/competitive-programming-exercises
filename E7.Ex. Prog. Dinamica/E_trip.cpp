#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define ii pair<int, int>
#define INFINITE 10e9
#define DEBUG 0

#define TIME 0
#define PRICE 1

ll n;
int trip[10005][2];
double min_travel[10005][8][125];

double bestTravel(ll time_left, ll n_trip, ll order)
{
  double buy, wait;
  if (n_trip >= n)
  {
    return 0;
  }

  if(time_left <= 0)
  {
    order = 0;
    time_left = 120;
  }

  if(min_travel[n_trip][order][time_left] != -1)
  {
    return min_travel[n_trip][order][time_left];
  }

  if (order == 0 || order > 5)
  {
    if (DEBUG)
    {
      cout << "PASSEI1\n";
      cout << "time:" << time_left << " n_trip:" << n_trip << " order:" << order << "\n";
    }

    buy = trip[n_trip][PRICE] + bestTravel(time_left - trip[n_trip][TIME], n_trip + 1, order + 1);
    wait = trip[n_trip][PRICE] + bestTravel(120, n_trip + 1, 0);
  }

  else if (order == 1)
  {
    if (DEBUG)
    {
      cout << "PASSEI2\n";
      cout << "time:" << time_left << " n_trip:" << n_trip << " order:" << order << "\n";
    }

    buy = trip[n_trip][PRICE] * 0.5 + bestTravel(time_left - trip[n_trip][TIME], n_trip + 1, order + 1);
    wait = trip[n_trip][PRICE]*0.5 + bestTravel(120, n_trip + 1, 0);
  }

  else if (order > 1 || order <= 5)
  {
    if (DEBUG)
    {
      cout << "PASSEI3\n";
      cout << "time:" << time_left << " n_trip:" << n_trip << " order:" << order << "\n";
    }

    buy = trip[n_trip][PRICE] * 0.25 + bestTravel(time_left - trip[n_trip][TIME], n_trip + 1, order + 1);
    wait = trip[n_trip][PRICE]*0.25 + bestTravel(120, n_trip + 1, 0);
  }


  if (DEBUG)
  {
    cout << "Wait:" << wait << endl;
    cout << time_left << endl;
  }

  return min_travel[n_trip][order][time_left] = min(wait, buy);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll duration, cost;
  cin >> n;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      for(int k = 0; k < 125; k++)
      {
        min_travel[i][j][k] = -1.0;
      }
    }
  }

  for (ll i = 0; i < n; i++)
  {
    cin >> duration >> cost;
    trip[i][TIME] = duration;
    trip[i][PRICE] = cost;
  }

  printf("%.2lf\n", bestTravel(120, 0, 0));

  return 0;
}