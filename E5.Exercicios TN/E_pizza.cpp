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
 
  double angle, R;
  ll count=0;
  set<ll> angles;
 
  scanf("%lf", &R);

  angle = R;

  do
  {
    angle += R;
    while(angle > 360){
      angle -= 360;
    }

    count++;
    
  } while (fabs(angle-R) >  0.001 && count < 36000);
 
  printf("%lli\n", count);
 
  return 0;
}