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

  int n_cash, n_client, cash_index = 0, next_t_wait = 0, last_one = 0;
  vi t_cash_vector;
  queue<int> client;
  int element, time = 0, current_client, t_wait = 0;

  scanf("%d %d", &n_cash, &n_client);

  vi cash_state(n_cash, 0);

  for (int i = 0; i < n_cash; i++)
  {
    scanf("%d", &element);
    t_cash_vector.pb(element);
  }

  for (int i = 0; i < n_client; i++)
  {
    scanf("%d", &element);
    client.push(element);
  }

  while (!client.empty())
  {
    current_client = client.front();
    client.pop();

    // KD caixa livre
    while (cash_state[cash_index] != 0)
    {
      cash_index++;

      // Estourou caixa
      if (cash_index == n_cash)
      {
        t_wait = next_t_wait;

        cash_index = 0;
        time += t_wait;

        next_t_wait = cash_state[cash_index] - t_wait;

        for (int i = 0; i < n_cash; i++)
        {
          cash_state[i] -= t_wait;
        }
      }

      if (cash_state[cash_index] <= 0)
      {
        cash_state[cash_index] = 0;
        break;
      }

      next_t_wait = min(next_t_wait, cash_state[cash_index]);
    } // while caixa livre

    // Aqui um caixa livre!
    cash_state[cash_index] = t_cash_vector[cash_index] * current_client;

    // Tempo de atendimento
    if (next_t_wait == 0)
    {
      next_t_wait = t_cash_vector[cash_index] * current_client;
    }

    else
    {
      next_t_wait = min(next_t_wait, t_cash_vector[cash_index] * current_client);
    }

    if (client.empty())
    {
      last_one = cash_state[0];
      for (int i = 0; i < n_cash; i++)
      {
        last_one = max(last_one, cash_state[i]);
      }

      time += last_one;
      break;
    }
  }

  printf("%d\n", time);

  return 0;
}
