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

  ll T, element, flag = 1;
  ll N, greatest, least, number;
  vector<ll> a;
  vector<ll> primes(1000005, -1);

  cin >> T;

  for (ll i = 2; i < primes.size(); i++)
  {
    if (primes[i] == -1)
    {
      for (ll m = i + i; m < primes.size(); m += i)
      {
        primes[m]++;
      }
    }
  }

  for (ll i = 0; i < T; i++)
  {
    cin >> N;
    greatest = -1;
    least = 100000000;
    flag = 1;

    for (ll j = 0; j < N; j++)
    {
      cin >> element;
      a.pb(element);
      greatest = max(element, greatest);
      least = min(element, least);
    }

    if (N == 1)
    {
      if (primes[a[0]] == -1)
      {
        cout << a[0] * a[0] << '\n';
      }

      else
      {
        cout << "-1\n";
      }

      continue;
    }

    ll result = greatest * least;

    sort(a.begin(), a.end());

    ll w = 0;
    for (ll j = 2; j * j <= result; j++)
    {
      if (result % j == 0)
      {
        ll q = result / j;
        if (a[w] != j || a[N - w - 1] != q)
        {
          flag = 0;
          break;
        }
        w++;
      }
    }

    if (flag == 1)
    {
      cout << result << '\n';
    }

    else
    {
      cout << "-1\n";
    }

    a.clear();
  }

  return 0;
}
