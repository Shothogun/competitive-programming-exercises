#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAX 1000002

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<ll> primes_flag(MAX, -1);
  vector<ll> primes_count(MAX, 0);
  ll q, l, r, counter = 0;

  for (ll i = 2; i < MAX; i++)
  {
    if (primes_flag[i] == -1)
    {
      for (ll m = i + i; m < MAX; m += i)
      {
        primes_flag[m] = i;
      }
    }
  }

  for (ll i = 2; i < MAX; i++)
  {
    if (primes_flag[i] == -1)
    {
      counter++;
    }
    primes_count[i] = counter;
  }

  cin >> q;

  for (ll i = 0; i < q; i++)
  {
    cin >> l >> r;

    if (l == 0)
    {
      cout << primes_count[r] << '\n';
    }

    else
    {
      cout << primes_count[r] - primes_count[l - 1] << '\n';
    }
  }

  return 0;
}
