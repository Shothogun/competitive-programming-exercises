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
	vector<ll> divisors;
	ll n, sum = 1;

	cin >> n;

	for (ll i = 2; i * i <= n; i++)
	{
		ll q = n / i;
		if (n % i == 0)
		{
			divisors.pb(i);

			if (q != i)
			{
				divisors.pb(q);
			}
		}
	}

	for (auto u = divisors.begin(); u != divisors.end(); ++u)
	{
		sum += *u;
	}

	if (sum == n)
	{
		cout << "1\n";
	}

	else{
		cout << "0\n";
	}

	return 0;
}
