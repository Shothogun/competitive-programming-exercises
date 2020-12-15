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

  int N, R, M, element, time = 1;
  multiset<int> ships;

  scanf("%d %d %d", &N, &R, &M);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &element);
    ships.insert(element);
  }

  R -= N * M;

  while (R > 0)
  {
    for (auto ship = ships.begin(); ship != ships.end(); ++ship)
    {
      //printf("%d %d %d\n", *ship, R, time);
      if ((time - 1) % *ship == 0 && time != 1)
      {
        R -= M;
      }

      if (R <= 0)
      {
        break;
      }
    }

    R++;
    time++;
  }

  printf("%d\n", time);

  return 0;
}