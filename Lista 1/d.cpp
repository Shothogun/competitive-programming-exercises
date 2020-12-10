#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
  int i, y, flag = 0, number,
      divider;
  vi digits (4,0);
  vi detect (10,0);

  scanf("%d", &y);

  while(!flag){

    y++;
    number = y;

    divider = 1000;
    digits.clear();

    for(i = 0; i < 4; i++){
      digits.pb(number/divider);
      number %= divider;
      divider /= 10;
    }

    detect[digits[0]] += 1;
    detect[digits[1]] += 1;
    detect[digits[2]] += 1;
    detect[digits[3]] += 1;

    if(detect[digits[0]] < 2 && detect[digits[1]] < 2 &&
       detect[digits[2]] < 2 && detect[digits[3]] < 2){
         flag = 1;
       }

    detect[digits[0]] = 0;
    detect[digits[1]] = 0;
    detect[digits[2]] = 0;
    detect[digits[3]] = 0;
  }

  printf("%d\n", y);

  return 0;
}
