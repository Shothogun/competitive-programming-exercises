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
  int n, t, c, element;
  int possibilities = 0;
  vi prisioners;
  queue<int> group;

  scanf("%d %d %d", &n, &t, &c);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &element);
    prisioners.pb(element);
  }

  for (int i = 0; i < n; i++)
  {
    if(group.empty() && prisioners[i] <= t){
      group.push(prisioners[i]);
    }

    else if(group.size() < c && prisioners[i] <= t){
      group.push(prisioners[i]);
    }

    else if(prisioners[i] > t){
      while(!group.empty()){
        group.pop();
      }
    }

    if(group.size() == c){
      group.pop();
      possibilities++;
    }
  }

  printf("%d\n", possibilities);

  return 0;
}