#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
 
int bn(vector<ll> V, ll number, ll N)
{
  ll l, r, m, ans = -1;
  l = 0;
  r = N - 1;
 
  while (l <= r)
  {
    m = (l + r) / 2;
 
    if (V[m] == number)
    {
      ans = m;
    }
 
    if (V[m] < number)
    {
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }
 
  return ans;
}
 
int main()
{
 
  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
 
  /* Insira o codigo-fonte aqui */
 
  ll N, sum = 0, element, arc_size, i = 0, ans_1, ans_2;
  ll l, r, m;
  ll vertice_1, vertice_2, vertice_3;
  vector<ll> V;
  map<ll, ll> triangle_vertices;
 
  scanf("%lli", &N);
 
  for (ll i = 0; i < N; i++)
  {
    scanf("%lli", &element);
    sum += element;
    V.pb(sum);
  }
 
  arc_size = sum / 3;
 
  for (ll i = 0; i < N; i++)
  {
    vertice_1 = V[i];
    vertice_2 = (V[i] + arc_size) % sum;
    vertice_3 = (V[i] + arc_size * 2) % sum;
 
    l = 0;
    r = N - 1;
    ans_1 = -1;
 
    while (l <= r)
    {
      m = (l + r) / 2;
 
      if (V[m] == vertice_2)
      {
        ans_1 = m;
      }
 
      if (V[m] < vertice_2)
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
 
    l = 0;
    r = N - 1;
    ans_2 = -1;
 
    while (l <= r)
    {
      m = (l + r) / 2;
 
      if (V[m] == vertice_3)
      {
        ans_2 = m;
      }
 
      if (V[m] < vertice_3)
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
 
    if (ans_1 != -1 && ans_2 != -1 &&
        triangle_vertices[i] == 0)
    {
      //cout << V[i] << ' ' << V[ans_1] << ' ' << V[ans_2] << endl;
      triangle_vertices[i]++;
      triangle_vertices[ans_1]++;
      triangle_vertices[ans_2]++;
    }
  }
 
  if (sum % 3 != 0)
  {
    printf("0\n");
  }
 
  else
  {
    printf("%lu\n", triangle_vertices.size() / 3);
  }
 
  return 0;
}