#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 1e9;
ll MAX_CH, N_QUOTES;
ll ch[55];
ll sorry[55];
ll mem[1005][55];

ll countMaxSorry(ll space, ll index)
{
  ll write=-INFINITE;
  ll pass=-INFINITE;

  if(space <= 0 || index >= N_QUOTES)
  {
    return 0;
  }

  if(mem[space][index] != -1)
  {
    return mem[space][index];
  }

  if(ch[index] <= space)
  {
    write = sorry[index] + countMaxSorry(space-ch[index], index+1);
  }
  pass = countMaxSorry(space, index+1);

  mem[space][index] = max(write, pass);

  return mem[space][index];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(mem, -1, sizeof(mem));

  ll ch_p_line, n_sorry; 

  cin >> MAX_CH >> N_QUOTES;

  for (ll i = 0; i < N_QUOTES; i++)
  {
    cin >> ch_p_line >> n_sorry;
    ch[i] = ch_p_line;
    sorry[i] = n_sorry;
  }

  cout << countMaxSorry(MAX_CH, 0) << "\n";

  return 0;
}