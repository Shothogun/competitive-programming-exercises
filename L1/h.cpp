#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  int N,A,B,i,j,base=1, number;
  unsigned int digits_sum, sequence_sum = 0;

  scanf("%d %d %d", &N, &A, &B);

  for(i = 1; i <= N; i++){
    if(i/base >= 10){ 
      base *= 10;
    }

    digits_sum = 0;
    number = i;

    for(j = base; j >= 1; j /= 10){
      digits_sum += number/j;
      number %= j;
    }


    if(digits_sum >= A && digits_sum <= B){
      sequence_sum += i;
    }
  }

  printf("%u\n", sequence_sum);

  return 0;
}
