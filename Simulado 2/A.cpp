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

  /* Insira o codigo-fonte aqui */
  ll N, M;
  ll digit;

  cin >> N >> M;

  digit = N;

  if(M == 0){
    cout << "1\n";
    return 0;
  }

  for (ll i = 1; i < M; i++)
  {
    digit = (N%10) *(digit%10);
    digit %=10;
  }

  cout << digit << '\n';

  return 0;
}
