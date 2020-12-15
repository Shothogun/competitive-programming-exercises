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

  ll n, q, element, l, r, sum=0;

  scanf("%lli %lli", &n, &q);

  vector<ll> delta(n, 0);
  priority_queue<ll> a;

  for (ll i = 0; i < n; i++)
  {
    scanf("%lli", &element);
    a.push(element);
  }

  for (ll i = 0; i < q; i++)
  {
    scanf("%lli %lli", &l, &r);

    l--;
    r--;

    delta[l]++;

    if (r < n - 1)
    {
      delta[r + 1]--;
    }
  }


  for (ll i = 1; i < n; i++)
  {
    delta[i] += delta[i-1];
  }

  sort(delta.begin(), delta.end(), greater<ll>());

  for (ll i = 0; i < n; i++)
  {
    auto number = a.top();
    a.pop();
    sum += number*delta[i];
  }

  printf("%lli\n", sum);

  return 0;
}
