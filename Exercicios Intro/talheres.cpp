#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
    
    int N,G,F,C;

    scanf("%d %d %d %d", &N, &G, &F, &C);
    int garfo_faca = min(G,F);

    if(N-C < garfo_faca){
      printf("%d\n", N);
    }

    else{
      printf("%d\n", C + garfo_faca);
    }

    return 0;
}
