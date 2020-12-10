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
  int n, l, r, k, m, ans;
  char result;
  cin >> n;

  l = 1;
  r = n;
  k = 0;

  while (l <= r)
  {
    m = (r + l) / 2;
    result = 0;

    cout << m << endl;
    cout.flush();

    cin >> result;

    if (result == '<')
    {
      r = m - 1;
    }
    else if(result == '>')
    {
      l = m + 1;
    }
    else if(result == '-'){
      ans = m;
      break;
    }
  }

  cout << "! " << ans << endl;
  cout.flush();

  return 0;
}
