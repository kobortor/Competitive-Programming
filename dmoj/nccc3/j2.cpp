#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool palin(string str){
    for(int a = 0; a < (int)str.size(); a++){
        if(str[a] != str[str.size() - 1 - a]){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;
    for(int a = 1; a < (int)str.size(); a++){
        if(palin(str.substr(0, a)) && palin(str.substr(a, -1))){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
