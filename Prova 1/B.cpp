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

  ll N, counter = 0, element, number, ans;
  ll l, r, m;
  vector<ll> athletes, athletes_times;

  scanf("%lli", &N);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli", &element);
    athletes.pb(element);
    athletes_times.pb(element);
  }

  sort(athletes_times.begin(), athletes_times.end());

  for (ll i = 0; i < N; i++)
  {
    l = 0;
    r = N-1;
    ans=0;
    number = athletes[i];

    while (l <= r)
    {
      m = (l + r) / 2;

      if(athletes_times[m] == number){
        ans = m;
      }

      if(athletes_times[m] < number){
        l = m+1;
      }
      else{
        r = m-1;
      }
    }

    cout << ans+1 << ' ';
  }

  cout << endl;

  return 0;
}
