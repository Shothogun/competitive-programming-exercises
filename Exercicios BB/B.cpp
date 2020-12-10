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

  int n, m, element;
  vi a;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &element);
    a.pb(element);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < m; i++)
  {
    scanf("%d", &element);
    auto u = lower_bound(a.begin(), a.end(), element);
    if (u != a.end() && *u == element)
    {
      printf("%li ", u - a.begin() + 1);
    }
    else
    {
      printf("-1 ");
    }
  }

  printf("\n");

  return 0;
}
