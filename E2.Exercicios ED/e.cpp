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

  int n, k, i = 0, j = 0, element;
  int posicao = -1, flag = 0;
  vi a;
  set<int> complementares;

  scanf("%d %d", &n, &k);

  for (i = 0; i < n; i++)
  {
    scanf("%d", &element);
    complementares.insert(element - k);
    a.pb(element);
  }

  for (j = 0; j < n; j++)
  {
    if (complementares.find(a[j]) != complementares.end())
    {
      for (i = 0; i < n; i++)
      {
        if (i != j && a[i] - k == a[j])
        {
          flag = 1;
          break;
        }
      }
    }

    if (flag)
    {
      break;
    }
  }

  if (flag)
  {
    printf("Sim\n");
    printf("%d %d\n", i + 1, j + 1);
  }
  else
  {
    printf("Nao\n");
  }

  return 0;
}
