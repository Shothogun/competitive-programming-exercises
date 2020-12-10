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
	ll n_lights;
	ll state = 0;
	vector<ll> divisors;

	cin >> n_lights;

	for (ll i = 1; i*i <= n_lights; i++)
	{
		ll q = n_lights/i;
		if(n_lights%i == 0){
			divisors.pb(i);

			if(q != i){
				divisors.pb(q);
			}
		}
		
	}

	if(divisors.size()%2 == 0){
		cout << "desligada\n";
	}

	else{
		cout << "ligada\n";
	}

	return 0;
}
