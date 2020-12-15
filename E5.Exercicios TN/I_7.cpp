#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

ll pot_ten(ll n)
{
  ll base = 1;

  while (n > 0)
  {
    n /= 10;
    base *= 10;
  }

  return base;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, num, conc, digit, result;

  cin >> n;

  for (ll i = 0; i < n; i++)
  {
    cin >> num;

    result = num % 7;
    result += ((num % 7) * (pot_ten(num) % 7))%7 ;
    result %= 7;

    if (result == 0)
    {
      cout << "Sim" << '\n';
    }
    else
    {
      cout << "Nao" << '\n';
    }
  }

  return 0;
}
