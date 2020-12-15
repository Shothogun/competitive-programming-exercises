#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool subsequence(string t, string s)
{
  int counter = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == t[counter])
    {
      counter++;
    }
  }

  return (counter == t.size());
}

string new_string_remover(string s, set<int> a)
{
  string new_string = "";

  for (int i = 0; i < s.size(); i++)
  {
    if (a.find(i + 1) == a.end())
    {
      // cout << "!!!!!!!!!!!!!"<< endl;
      // cout << i << endl;
      new_string += s[i];
    }
  }

  return new_string;
}

int main()
{

  // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
  // SE HABILITADO)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r, k, m, ans, element;
  string t, p, new_string;
  vi a;
  set<int> b;

  cin >> t;
  cin >> p;

  for (int i = 0; i < t.size(); i++)
  {
    cin >> element;
    a.pb(element);
  }

  l = 0;
  r = t.size() - p.size();
  k = 0;

  while (l <= r)
  {
    m = (r + l) / 2;

    for (int i = 0; i < m; i++)
    {
      b.insert(a[i]);
    }

    new_string = new_string_remover(t, b);

    // cout << new_string << ' ' << m << endl;

    if (subsequence(p, new_string))
    {
      ans = m;
      l = m + 1;
    }

    else
    {
      r = m - 1;
    }

    b.clear();
  }

  cout << ans << endl;

  return 0;
}