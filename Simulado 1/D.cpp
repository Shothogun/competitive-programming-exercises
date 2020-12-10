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

  ll weight;
  ll X, Y, Z, M, N,j;
  vector<ll> tamandua;
  char wave;

  scanf("%lli %lli %lli", &X, &Y, &Z);
  getchar();
  scanf("%lli %lli", &M, &N);
  getchar();

  tamandua.pb(M);

  for (ll i = 0; i < N; i++)
  {
    scanf("%c", &wave);
    if (wave == 'F')
    {
      weight = X;
    }
    else if (wave == 'A')
    {
      weight = Y;
    }
    else
    {
      weight = Z;
    }

    for(j = 0; j < tamandua.size();j++){
      if(tamandua[j] - weight >= 0){
        break;
      }
    }

    if(j == tamandua.size()){
      tamandua.pb(M-weight);
    }
    else{
      tamandua[j] -= weight; 
    }
  }

  printf("%lu\n", tamandua.size());

  return 0;
}
