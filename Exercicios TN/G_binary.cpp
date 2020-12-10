#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define SECRET_NUMBER 131071
#define mod(n) ((n) % SECRET_NUMBER)

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string bin_number;

  cin >> bin_number;

  ll size = bin_number.size();

  // 2^n % SECRET_NUMBER
  vector<ll> power_two(size, 1);

  power_two[1] = 2;
  ll result = 0;

  for (ll i = 2; i < size; i++)
  {
    power_two[i] = power_two[i - 1] * 2;
    power_two[i] %= SECRET_NUMBER;
  }

  ll j = size - 1;
  for (ll i = 0; i < size; i++)
  {
    if (bin_number[j] == '1')
    {
      result += power_two[i];
      result = mod(result);
    }
    j--;
  }

  if (result == 0)
  {
    cout << "Sim" << '\n';
  }

  else
  {
    cout << "Nao" << '\n';
  }

  return 0;
}
