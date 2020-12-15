#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){

  std::ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,i;
  string element;
  map<int, string> original;
  map<string, int> sorted;
  vector<pair<string, int>> v;
  cin >> n;

  for(i=0 ; i<n; i++){
    cin >> element;
    original[i] = element;
    v.pb(mp(element, i));
  }

  sort(v.begin(), v.end());

  for(i=0 ; i<n; i++){
    sorted[v[i].first]= i;
  }

  for(i=0 ; i<n-1; i++){
    cout << sorted[original[i]] << " ";
  }

  cout << sorted[original[i]] << endl;

  return 0;
}
