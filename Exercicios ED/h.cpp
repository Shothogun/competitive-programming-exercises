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
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  stack<int> stack;
  set<int> weights;
  char querie;
  int n, argument;

  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++)
  {
    scanf("%c %d", &querie, &argument);
    getchar();
    if(querie == 'A'){
      weights.insert(argument);
      stack.push(argument);
    }
    else if(querie == 'R'){
      weights.erase(stack.top());
      stack.pop();
    }
    else {
      if(weights.empty()){
        printf("0\n");
        continue;
      }
      auto last = weights.end();
      last--;
      printf("%d\n", *last);
    }
  }

  return 0;
}
