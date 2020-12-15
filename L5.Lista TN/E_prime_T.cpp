#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define ii pair<int, int>
#define MAX 100000000000

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll Q;
  ll X, counter, flag;
  map<ll, ll> exp;

  cin >> Q;

  vector<ll> primes_div(1000005, -1);
  set<ll> t_primes;

  for (ll i = 2; i <= 1000005; i++)
  {
    if (primes_div[i] == -1)
    {
      for (ll m = i; m <= 1000005; m += i)
      {
        primes_div[m] = i;
      }

      t_primes.insert(i*i);
    }
  }

  for (ll i = 0; i < Q; i++)
  {
    cin >> X;
    if(t_primes.find(X) == t_primes.end()){
      cout << "0\n";
    }

    else{
      cout << "1\n";
    }

    exp.clear();
  }

  return 0;
}