#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool palin(string str){
    for(int a = 0; a < (int)str.size(); a++){
        if(str[a] != str[str.size() - a - 1]){
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

    int best = 0;

    for(int a = 0; a < (int)str.size(); a++){
        if(!palin(str.substr(0, a + 1))){
            best = max(best, a + 1);
        }
        if(!palin(str.substr(str.size() - a - 1, a + 1))){
            best = max(best, a + 1);
        }
    }

    cout << best;
}
