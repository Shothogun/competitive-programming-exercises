#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<ll> primes(1000005, -1);
  vector<ll> primes_dist(1000005, -1);
  vector<ll> primes_pair(1000005, -1);

  ll last_one, min_distance = 1000005, Q, N, M;
  pair<ll, ll> adj;

  cin >> Q;

  for (ll i = 2; i < primes.size(); i++)
  {
    if (primes[i] == -1)
    {
      for (ll m = i + i; m < primes.size(); m += i)
      {
        primes[m]++;
      }

      if (i > 2)
      {
        ll new_distance = i - last_one;

        primes_dist[last_one] = new_distance;
        primes_pair[last_one] = i;
        //cout << last_one << " "<< primes_dist[last_one] << " "<< primes_pair[last_one] << endl;
      }
      last_one = i;
    }
  }

  for (ll i = 0; i < Q; i++)
  {
    cin >> N >> M;
    ll min_dist = 100000000000;
    ll a, b;
    ll flag = 0;

    for (ll j = N; j <= M; j++)
    {
      if (primes_dist[j] != -1 &&
          primes_pair[j] <= M)
      {
        flag = 1;
        if (primes_dist[j] < min_dist)
        {
          min_dist = primes_dist[j];
          a = j;
          b = primes_pair[j];
        }
      }
    }

    if (flag)
    {
      cout << a << " " << b << "\n";
    }

    else
    {
      cout << "-1\n";
    }
  }

  return 0;
}
