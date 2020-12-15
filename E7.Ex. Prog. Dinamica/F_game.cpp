#include <bits/stdc++.h>
using namespace std;

vector<int> saved(10001, -1);
vector<int> values;
map<int, int> occurance;
int N;

int dp(int k){
    if(k > 10000){
        return 0;
    }

    if(saved[k] != -1){
        return saved[k];
    }

    int escolher = k * occurance[k] + dp(k + 2);
    int pular = dp(k + 1);

    saved[k] = max(escolher, pular);
    return saved[k];

}

int main(){
    int aux;
    

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &aux);
        values.push_back(aux);
        occurance[aux]++;
    }

    printf("%d\n", dp(1));

    return 0;
}