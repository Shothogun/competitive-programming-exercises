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
  ll n, p, element, ans=0;
  ll l, r, m, sum=0, first=0, last=0, j=0;
  vector<ll> v;

  scanf("%lli %lli", &n, &p);
  for(ll i=0; i<n; i++){
    scanf("%lli", &element);
    v.pb(element);
  }

  l = 0;
  r = n;

  while (l <= r)
  {
    m = (l + r) / 2;

    j=0;
    first=0;
    last=m-1;
    sum=0;
    //printf("%lli\n", m);

    for(ll i = 0; i < n; i++){
      sum += v[i];
 
      if(i > m-1){
        sum -= v[first];
        first++;
        last++;
      }

      if(i>=m-1 && sum < p){
        break;
      }
    }

    if(sum > p){
      r = m-1;
    }
    else{
      //printf("%lli\n",sum);
      l = m+1;
      ans=m;
    }

  }

  printf("%lli\n", ans);

  return 0;
}
