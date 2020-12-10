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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<int, int> stock;
  int n, querie, argument;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &querie, &argument);
    if(querie == 1){
      stock[argument] = 1;
    }
    else{
      stock[argument] == 1 ? printf("Sim\n") : printf("Nao\n");
    }
  }

  return 0;
}
