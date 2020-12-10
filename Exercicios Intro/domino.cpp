#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){

  int m,n, area;
  int domino_area = 2, covered;

  scanf("%d %d", &m, &n);

  area = m*n;
  covered = area/domino_area;

  printf("%d\n", covered);

  return 0;
}
