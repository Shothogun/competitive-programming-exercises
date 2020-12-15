#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  /* Insira o codigo-fonte aqui */

  ll lines, N = -1, element, flag;
  vector<ll> a;

  scanf("%lli", &lines);

  for (ll i = 0; i < lines; i++)
  {
    scanf("%lli", &element);
    a.pb(element);
    N = max(N, element);
  }

  vector<bool> isPrime(N + 1, true);
  vector<ll> primes;

  isPrime[0] = 0;
  isPrime[1] = 0;

  for (ll i = 3; i < N; i += 2)
  {
    isPrime[i + 1] = false;

    if (isPrime[i])
    {
      primes.pb(i);
      for (ll j = i + i; j <= N; j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  for (ll i = 0; i < lines; i++)
  {
    ll number = a[i];
    flag = 1;
    while (number > 0)
    {
      if (isPrime[number])
      {
        number /= 10;
      }
      else
      {
        flag = 0;
        break;
      }
    }

    if (flag)
    {
      printf("S\n");
    }
    else
    {
      printf("N\n");
    }
  }

  return 0;
}
