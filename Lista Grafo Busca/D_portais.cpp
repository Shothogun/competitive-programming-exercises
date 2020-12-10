#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define matrix vector<vector<ll>>
#define DEBUG 0

int main()
{
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  ll inicial = 1;
  ll t, n, element;

  scanf("%lli %lli", &n, &t);
  vector<ll> portals(n+1, 0);

  for (ll i = 1; i < n; i++)
  {
    scanf("%lli", &element);
    portals[i] = element;
  }

  for (ll i = 1; i <= n; i++)
  {
    if (inicial == t)
    {
      break;
    }
    inicial += portals[inicial];
  }

  if (inicial == t)
  {
    printf("sim\n");
  }

  else
  {
    printf("nao\n");
  }
}
