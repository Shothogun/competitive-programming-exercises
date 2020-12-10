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
  unsigned long long x, result, l, r, m, ans;
  scanf("%llu", &x);

  l = 1;
  r = 5000000000;
  ans = 2;

  while (l <= r)
  {
    m = (r + l) / 2;
    result = m * (m + 1) / 2;

    if (result > x)
    {
      r = m - 1;
      ans = m;
    }
    else
    {
      l = m + 1;
    }
  }

  printf("%llu\n", ans);

  return 0;
}
