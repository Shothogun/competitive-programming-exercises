#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

ll sum_digits(ll n)
{
  ll sum = 0;
  ll number = n;

  while (number > 0)
  {
    sum += number % 10;
    number /= 10;
  }

  //cout << number << '\n';

  return sum;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k, x, j, result;

  cin >> n;


  for (ll i = 0; i < n; i++)
  {
    cin >> k >> x;
    cout << (k-1)*9 + x << '\n';

  }

  return 0;
}
