#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int no_stack;
  char last_one;
  set<string> containers_stack_set;
  string containers, containers_stack;

  cin >> containers;

  for (auto container = containers.begin();
       container != containers.end(); container++)
  {
    // Pilha pos insercao
    containers_stack = "";

    // Flag de nao ha nenhuma stack disponivel
    no_stack = 1;

    if (container == containers.begin())
    {
      containers_stack += *container;
      containers_stack_set.insert(containers_stack);
    }

    // Olha as pilhas
    for (string stack : containers_stack_set)
    {
      // Empilha
      if (stack.front() >= *container)
      {
        containers_stack = *container + stack;
        containers_stack_set.erase(stack);
        containers_stack_set.insert(containers_stack);
        no_stack = 0;
        break;
      }
    }

    // Nova pilha se nenhuma disponivel
    if (no_stack)
    {
      containers_stack += *container;
      containers_stack_set.insert(containers_stack);
    }
  }

  cout << containers_stack_set.size() << endl;

  // while(!containers_stack_set.empty())
  // {
  //   auto container = containers_stack_set.top();
  //   containers_stack_set.pop();
  //   cout << container << endl;
  // }

  return 0;
}