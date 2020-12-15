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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int upcase = 'A' - 'a';
  string s1;
  string s2;
  string input;
  int n, j=0;
  map<char,char> teclado;

  for(int i = '0'; i<= '9'; i++){
    teclado[i] = i;
  }

  cin >> s1;
  cin >> s2;
  cin >> n;

  for(int i = 0; i < 26; i++){
    teclado[s1[i]] = s2[i];
    teclado[s1[i]+upcase] = s2[i] + upcase;
  }

  for(int i = 0; i<n; i++){
    cin >> input;
    j = 0;
    while(input[j] != '\0'){
      cout << teclado[input[j]];
      j++;
    }
    cout << endl;
  }

  return 0;
}
