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

  int N, element, error_number;
  map<int,int> new_errors, old_errors;

  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &element);
    old_errors[element] += 1;
  }

  for (int i = 0; i < N - 1; i++)
  {
    scanf("%d", &element);
    new_errors[element] += 1;
  }

  for (auto error = old_errors.begin(); error != old_errors.end(); ++error)
  {
    if (error->second != new_errors[error->first])
    {
      error_number = error->first;
      break;
    }
  }

  printf("%d\n", error_number);

  old_errors[error_number] -= 1;

  new_errors.clear();

  for (int i = 0; i < N - 2; i++)
  {
    scanf("%d", &element);
    new_errors[element] += 1;
  }

  for (auto error = old_errors.begin(); error != old_errors.end(); ++error)
  {
    if (error->second != new_errors[error->first])
    {
      error_number = error->first;
      break;
    }
  }

  printf("%d\n", error_number);

  return 0;
}