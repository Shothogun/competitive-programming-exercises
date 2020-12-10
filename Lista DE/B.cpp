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
  ll N, M, element, l, r, a, count = 0;
  scanf("%lli %lli", &N, &M);

  vector<ll> delta(N, 0), p(N, 0), op(N, 0);

  for (ll i = 0; i < N; i++)
  {
    scanf("%lli", &element);
    p[i] = element;
  }

  for (ll i = 0; i < M; i++)
  {
    scanf("%lli %lli %lli", &l, &r, &a);
    l--;
    r--;

    delta[l] -= a;
    op[l]++;

    if (r < N - 1)
    {
      delta[r + 1] += a;
      op[r + 1]--;
    }
  }

  p[0] += delta[0];

  //cout << "p" << 0 << " " << p[0] << endl;

  for (ll i = 1; i < N; i++)
  {
    delta[i] += delta[i - 1];
    op[i] += op[i - 1];
    p[i] += delta[i];
    //cout << "p" << i << " " << p[i] << endl;
    if (p[i] < 0)
      p[i] = 0;
  }

  for (ll i = 0; i < N; i++)
  {
    if (p[i] > 0)
      count += op[i];
  }

  printf("%lli\n", count);

  return 0;
}
