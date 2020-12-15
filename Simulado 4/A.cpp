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
ll F[1000005];
 
ll Fn(ll n)
{
  if (n == 0)
  {
    return 0;
  }
 
  if (n == 1)
  {
    return 1;
  }
 
  if(n == 2)
  {
    return 0;
  }
 
  if(F[n] != -1)
  {
    return F[n];
  }
 
  F[n] = Fn(n-1)%1000000007 + Fn(n-2)%1000000007;
  F[n] %= 1000000007;
 
  return F[n];
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  memset(F, -1,sizeof(F));
 
  cin >> N;
 
  cout <<  Fn(N) << "\n";
 
  return 0;
}