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

  ll N, M, j = 2, flag = 1;
  ll N_orig, M_orig;
  cin >> N >> M;
  N_orig = N;
  M_orig = M;

  while (N > 1 && M > 1)
  {
    if (N % j == 0 && M % j == 0)
    {
      if(j == min(N_orig, M_orig)){
        flag = 0;
        break;
      }

      while (N % j == 0)
      {
        N /= j;
      }

      while (M % j == 0)
      {
        M /= j;
      }
    }

    if ((N % j == 0 && M % j != 0) ||
        (N % j != 0 && M % j == 0))
    {
      flag = 0;
      break;
    }

    j++;
  }

  if (flag)
  {
    cout << "Sim\n";
  }

  else
  {
    cout << "Nao\n";
  }

  return 0;
}
