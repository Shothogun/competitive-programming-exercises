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

  ll N, cubic_flag = 0, root = 0;
  ll root_exp;

  scanf("%lli", &N);

  for (ll i = 1; (i * i * i) <= N; i++)
  {
    if((i*i*i) == N){
      cubic_flag = 1;
      root = i;
      break;
    }
  }

  if (cubic_flag)
  {
    printf("%lli\n", root);
  }

  else
  {
    printf("-1\n");
  }

  return 0;
}
