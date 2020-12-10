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
  vector<ii> park;
  stack<int> exit_order;
  int arrive, exit, vacancy, impossible = 0;
  int n, k;

  scanf("%d %d", &n, &k);

  vacancy = k;

  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &arrive, &exit);
    park.pb(mp(arrive, exit));
  }

  for (int i = 0; i < n; i++)
  {
    while (!exit_order.empty())
    {
      if (exit_order.top() <= park[i].first)
      {
        exit_order.pop();
        vacancy++;
      }
      else{
        break;
      }
    }

    //Preenche
    if (vacancy > 0)
    {
      exit_order.push(park[i].second);
      vacancy--;
    }

    else if (vacancy == 0)
    {
      impossible = 1;
    }
  }


  while(exit_order.size() > 1)
  {
    auto back = exit_order.top();
    exit_order.pop();
    if (back > exit_order.top())
    {
      impossible = 1;
      break;
    }
  }

  impossible == 1 ? printf("Nao\n") : printf("Sim\n");

  return 0;
}