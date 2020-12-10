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

  ll m, n,person;
  ll x, y, eggs;
  cin >> m >> n;

  set<ll> divisors;
  vector<ll> friends_egg_day(n + 1, -1);

  for (ll day = 0; day < m; day++)
  {
    cin >> x >> y;
    eggs = 0;

    for (person = 1; person * person <= x; person++)
    {
      if (person > n)
      {
        break;
      }

      if (x % person == 0)
      {
        if (day - friends_egg_day[person] > y)
        {
          friends_egg_day[person] = day;
          eggs++;
        }

        if (person != x / person &&  x / person <= n)
        {
          divisors.insert(x / person);

          if (day - friends_egg_day[x / person] > y)
          {
            friends_egg_day[x / person] = day;
            eggs++;
          }
        }
      }
    }

    cout << eggs << "\n";

    divisors.clear();
  }

  return 0;
}