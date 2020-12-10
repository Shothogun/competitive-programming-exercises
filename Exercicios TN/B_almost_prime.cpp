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

	ll N, counter=0, number, j;

	scanf("%lli", &N);

	vector<ll> lp(N + 2, -1);

	for (ll x = 2; x < N; x++)
	{
		if (lp[x] == -1)
		{
			for(ll m = x+x; m <= N; m += x){
				if(lp[m] == -1){
					lp[m] = 0;
				}

				lp[m]++;
			}
		}
	}

	for (ll x = 2; x <= N; x++){
		if(lp[x] == 2){
			counter++;
		}
	}

	printf("%lli\n", counter);



	return 0;
}
