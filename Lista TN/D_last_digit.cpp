#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAX 100000000000

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, p, number;
  ll exp2 = 0, exp5 = 0;
  ll fat_mod = 1;

  cin >> n >> p;

  if (n == 0)
  {
    cout << "1\n";
    return 0;
  }

  for (ll i = n - p + 1; i <= n; i++)
  {
    number = i;
    while (number % 2 == 0)
    {
      number /= 2;
      exp2++;
    }

    while (number % 5 == 0)
    {
      number /= 5;
      exp5++;
    }
  }

  ll exp = min(exp2,exp5);
  exp2 = exp;
  exp5 = exp;

  for (ll i = n - p + 1; i <= n; i++)
  {
    number = i;

    while (number %5 == 0 && exp5 > 0)
    {
      number /= 5;
      exp5--;
    }

    while (number %2 == 0 && exp2 > 0)
    {
      number /= 2;
      exp2--;
    }

    fat_mod = (number % 10) * (fat_mod % 10);
    fat_mod %= 10;
  }

  cout << fat_mod % 10 << "\n";

  return 0;
}
