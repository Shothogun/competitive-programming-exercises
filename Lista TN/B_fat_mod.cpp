#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAX 1000002
#define THENUMBER 1000000007

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, number;
  vector<ll> fat_mod(MAX, 1);


  for(ll i = 2; i < MAX; i++){
    fat_mod[i] = (fat_mod[i-1])*(i%THENUMBER);
    fat_mod[i] %= THENUMBER;
  }
  
  cin >> n;

  for(ll i = 0; i < n; i++){
    cin >> number;

    cout << fat_mod[number] << '\n';
  }

  return 0;
}
