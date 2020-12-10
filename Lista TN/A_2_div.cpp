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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<ll> v(1000002,0);

  ll n, x, counter;

  cin >> n;

  for(ll i = 1; i < v.size()+1; i++){
    for(ll m = i; m < v.size(); m+=i){
      v[m]++;
    }
  }

  for (ll i = 0; i < n; i++)
  {
    cin >> x;
    cout << v[x] << '\n';
  }

  return 0;
}
