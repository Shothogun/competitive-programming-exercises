#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAX 100001

// https://www.geeksforgeeks.org/prefix-sum-2d-array/

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  /* Insira o codigo-fonte aqui */

  ll N, q, X, Y, Z, W, count;
  ll r_top_x, r_top_y, l_bot_x, l_bot_y, result;
  string line;

  scanf("%lli", &N);

  ll SIZE = N * N;

  vector<ll> line_count(SIZE, 0);

  for (ll i = 0; i < N; i++)
  {
    count = 0;
    cin >> line;

    for (ll j = 0; j < N; j++)
    {
      if (line[j] == 'F')
      {
        count++;
      }
      line_count[i * N + j] = count;
      // printf("%lli ", line_count[i*N+j]);
    }
    // printf("\n");
    line.clear();
  }

  scanf("%lli", &q);

  for (ll i = 0; i < q; i++)
  {
    count = 0;
    scanf("%lli %lli %lli %lli", &X, &Y, &Z, &W);
    X--;
    Y--;
    Z--;
    W--;

    for (ll j = X; j <= Z; j++)
    {
      if (Y == 0)
      {
        count += line_count[j * N + W];
      }
      else
      {
        count += line_count[j * N + W] - line_count[j * N + Y - 1];
      }
    }

    printf("%lli\n", count);
  }

  return 0;
}
