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
  
  string expressao;
  int count = 0;
  int flag=0;
  int i=0;

  cin >> expressao;

  while(expressao[i] != '\0'){
    if(expressao[i] == '('){
      count++;
    }
    else if(expressao[i] == ')'){
      count--;
    }

    if(count < 0){
      count = -1;
      break;
    }
    i++;
  }

  count == 0 ? cout << "sim" << endl : cout << "nao" << endl;

  return 0;
}
