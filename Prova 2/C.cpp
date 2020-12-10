#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define THENUMBER 1000000007

void reverse(string &str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string hex;
	ll dec = 0, aux;
	vector<ll> base_mod(10005, 16);

	cin >> hex;

	base_mod[0] = 1;

	for (ll i = 2; i < base_mod.size(); i++)
	{
		base_mod[i] = (base_mod[i - 1] % THENUMBER) * 16;
		base_mod[i] %= THENUMBER;
	}

	reverse(hex);

	for (ll i = 0; i < hex.size(); i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			aux = (hex[i] - '0') % THENUMBER;
			aux *= base_mod[i];
			aux %= THENUMBER;
		}

		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			aux = (hex[i] - 'A' + 10) % THENUMBER;
			aux *= base_mod[i];
			aux %= THENUMBER;
		}

		dec += (aux % THENUMBER);
		dec %= THENUMBER;
	}

	cout << dec << "\n";

	return 0;
}
