#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<ll, ll>

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  /* Insira o codigo-fonte aqui */

  vector<pll> divisors;
  vector<ll> primes(10000005, -1);
  ll N, number, exp, K = 0;

  cin >> N;

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

  number = N;

  for (ll d = 2; d * d < N; d++)
  {
    if (number % d == 0)
    {
      exp = 0;
      while (number % d == 0)
      {
        number /= d;
        exp++;
      }

      divisors.pb(mp(d, exp));
    }
  }

  if (number > 1)
  {
    divisors.pb(mp(number, 1));
  }

  for (auto u = divisors.begin(); u != divisors.end(); u++)
  {
    K += u->first + u->second;
  }

  if (N == 1)
  {
    cout << "-1\n";
    return 0;
  }

  if (primes[K] == -1)
  {
    cout << K << '\n';
  }

  else
  {
    cout << "-1\n";
  }

  return 0;
}
