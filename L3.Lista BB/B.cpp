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
  int N, M, element, ans;
  int l,r,m, counter=0;
  vi v;

  scanf("%d %d", &N,&M);

  for(int i=0; i < N; i++){
    scanf("%d", &element);
    v.pb(element);
  }

  sort(v.begin(), v.end());

  l = 1;
  r = 2000000000;

  while(l<=r){
    counter=0;
    m=(r+l)/2;

    for(int i=0; i < N; i++){
      if(v[i]/m > 0){
        counter += v[i]/m;
      }
    }

    if(counter >= M){
      ans = m;
      l = m + 1;
    }
    else{
      r = m-1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
