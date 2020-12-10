#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

// Aprendizado: ao fazer um find no vetor para achar um outro elemento
// que nao inclua o atual em um loop, VERIFIQUE QUE VC ESTA GARANTINDO ISSO

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int N, M, element;
  int l, r, m, diff, pair;
  int book1, book2;
  multiset<int> p;

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &element);
    p.insert(element);
  }

  diff= 1000000000;

  for (auto u = p.begin(); u != p.end(); ++u)
  {
    pair = M - *u;
    if (p.find(pair) != p.end() && 
    abs(pair-*u) < diff         &&
    p.find(pair) != u)
    {
      book1 = min(*u, pair);
      book2 = max(*u, pair);
      diff = book2-book1;
    }
  }

  printf("%d %d\n", book1, book2);

  return 0;
}
