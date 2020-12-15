#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define INFINITE 1e9;
ll N;
ll D[1000005];

ll Dn(ll n)
{
  if(n < 0)
  {
    return 0;
  }

  if(n == 0)
  {
    return 1;
  }

  if(n == 1)
  {
    return 0;
  }

  if(D[n] != -1)
  {
    return D[n];
  }

  D[n] = (n-1)%1000000007*(Dn(n-1)%1000000007 + Dn(n-2)%1000000007);
  D[n] %= 1000000007;

  return D[n];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(D, -1, sizeof(D));

  cin >> N;

  cout << Dn(N) << "\n";

  return 0;
}
