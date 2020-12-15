#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

ll sum_digit(ll number){
  ll ratio, sum=0;
  while(number > 0){
    sum += number%10;
    number /= 10;
  }

  return sum;
}

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ll n, k, y, sum=0;
  ll l, r, m, ans=0, counter;

  scanf("%lli %lli", &n, &y);

  l = 1;
  r = n;
  //r = 1000000000000000;

  while (l <= r)
  {
    m = (l + r) / 2;

    sum = sum_digit(m);

    if (m-sum >= y)
    {
      ans = n-m+1;
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }

  printf("%lli\n", ans);

  return 0;
}
