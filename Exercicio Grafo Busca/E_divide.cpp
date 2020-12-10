#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define pll pair<long, long>
#define matrix vector<vector<int>>
#define DEBUG 1

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  ll op, n;

  cin >> q;

  while (q--)
  {
    cin >> n;
    op = 0;
    while (n % 2 == 0)
    {
      n /= 2;
      op++;
    }
    while (n % 3 == 0)
    {
      n /= 3;
      op += 2;
    }
    while (n % 5 == 0)
    {
      n /= 5;
      op += 3;
    }

    if (n == 1)
    {
      cout << op << "\n";
    }
    else
    {
      cout << "-1\n";
    }
  }

  return 0;
}