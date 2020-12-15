#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define UGLY_NUMBER 1000000007

ll mod_fat(ll n)
{
  if (n == 0)
  {
    return 1;
  }

  else
  {
    return (n % UGLY_NUMBER) * (mod_fat((n - 1)) % UGLY_NUMBER) % UGLY_NUMBER;
  }
}

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll X, Y, result;

  cin >> X >> Y;

  result = (mod_fat(X) + mod_fat(Y)) % UGLY_NUMBER;

  cout << result << '\n';

  return 0;
}