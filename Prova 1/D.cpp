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

  ll P, N, t, X;
  stack<ll> raise;

  scanf("%lli %lli", &P, &N);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli %lli", &t, &X);

    if (t == 1)
    {
      raise.push(X);
    }

    else
    {
      for(ll j =0; j<X; j++){
        raise.pop();
      }
    }
  }

  while(!raise.empty()){
    auto up = raise.top();
    raise.pop();

    P += up;
  }

  cout << P << endl;

  return 0;
}
