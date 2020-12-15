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

  int N, k1, k2, element, i, top = 0;
  long long error=0;
  vector<int> a;
  priority_queue<int> difference;

  scanf("%d %d %d", &N, &k1, &k2);
  for (i = 0; i < N; i++)
  {
    scanf("%d", &element);
    a.pb(element);
  }

  for (i = 0; i < N; i++)
  {
    scanf("%d", &element);
    element = element - a[i];
    if (element < 0)
    {
      element *= -1;
    }
    difference.push(element);
  }

  for (i = 0; i < (k1 + k2); i++)
  {
    top = difference.top();
    top--;

    if (top < 0)
    {
      top *= -1;
    }

    difference.pop();
    difference.push(top);
  }

  while (!difference.empty())
  {
    top = difference.top();
    difference.pop();
    error += (long long) (top) * (top);
  }

  printf("%lld\n", error);

  return 0;
}