#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main()
{

	// Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
	// SE HABILITADO)
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	/* Insira o codigo-fonte aqui */

	set<ll> divisors;
	ll X;

	scanf("%lli", &X);

	for (ll i = 1; i * i <= X; i++)
	{
		if (X % i == 0)
		{
			divisors.insert(i);
			divisors.insert(X / i);
		}
	}

	printf("%lu\n", divisors.size());

	return 0;
}
