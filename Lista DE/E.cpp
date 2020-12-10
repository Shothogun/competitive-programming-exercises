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

  ll n, m, q, element, sum_operation = 0, operation;
  ll l, r, d, x, y;

  scanf("%lli %lli %lli", &n, &m, &q);

  vector<ll> a(n, 0), op(m * 3, 0), op_count(m, 0), delta(n, 0);

  for (ll i = 0; i < n; i++)
  {
    scanf("%lli", &element);
    a[i] = element;
  }

  for (ll i = 0; i < m; i++)
  {
    scanf("%lli %lli %lli", &l, &r, &d);
    l--;
    r--;

    op[i * 3] = l;
    op[i * 3 + 1] = r;
    op[i * 3 + 2] = d;
  }

  for (ll i = 0; i < q; i++)
  {
    scanf("%lli %lli", &x, &y);
    x--;
    y--;

    op_count[x]++;
    if (y < m - 1)
    {
      op_count[y + 1]--;
    }
  }

  for (ll i = 1; i < m; i++)
  {
    op_count[i] += op_count[i - 1];
  }

  for (ll i = 0; i < m; i++){
    l = op[i * 3];
    r = op[i * 3 + 1];
    d = op[i * 3 + 2]*op_count[i];

    delta[l] += d;

    if(r < n-1){
      delta[r+1] -= d;
    }
  }

  for (ll i = 1; i < n; i++)
  {
    delta[i] += delta[i - 1];
  }

  for (ll i = 0; i < n; i++)
  {
    a[i] += delta[i];
  }

  for (ll i = 0; i < n; i++)
  {
    printf("%lli ", a[i]);
  }

  printf("\n");

  return 0;
}
