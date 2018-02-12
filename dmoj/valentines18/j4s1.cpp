#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool palin(const string &str){
    for(int a = 0; 2 * a < (int)str.size(); a++){
        if(str[a] != str[str.size() - a - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int mid = (N + M + 1) / 2;
    for(int diff = 0;; diff++){
        if(palin(to_string(mid + diff))){
            cout << mid + diff;
            return 0;
        }
        if(palin(to_string(mid - diff))){
            cout << mid - diff;
            return 0;
        }
    }
}
