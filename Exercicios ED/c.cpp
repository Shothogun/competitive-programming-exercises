#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int,int>

int main(){
        
    // Uso de somente cin e cout com eficiencia(NAO USAR SCANF E PRINTF
    // SE HABILITADO)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // -1 formiga, 0 ra, 1 serpente
    map<char, int> m;
    int eaten = 0;
    int total = 0;
    int i = 0;

    cin >> line;

    while(line[i]!='\0'){
      if(line[i] == 'r'){
        eaten = 0;
        m['r'] = 1; 
      }

      else if(line[i] == '.' && m['r'] > 0){
        eaten++;
        total++;
      }

      else if(line[i] == 's' && m['r'] > 0){
        m['r'] = 0;
        total -= eaten;
        eaten = 0;
      }

      i++;
    }    

    cout << total << endl;

    return 0;
}
