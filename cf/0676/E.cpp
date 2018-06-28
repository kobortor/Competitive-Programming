#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, K;

string val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    int unknown = 0, cnt = 0;

    for(int a = 0; a <= N; a++) {
        cin >> val[a];
        unknown += (val[a] == "?");
    }

    cnt = N + 1 - unknown;

    if(unknown == 0){
        if(K == 0){
            cout << (stoi(val[0]) == 0 ? "Yes" : "No");
        } else {
            ll tmp = 0;
            for(int a = 0; a <= N; a++){
                if(tmp % K != 0){
                    cout << "No";
                    return 0;
                }
                tmp /= K;
                tmp += stoi(val[a]);
            }
            if(tmp != 0){
                cout << "No";
                return 0;
            }
            cout << "Yes";
        }
    } else if (cnt % 2 == 0){ //computer
        if(K == 0){
            cout << (val[0] == "?" || stoi(val[0]) != 0 ? "No" : "Yes");
        } else {
            cout << (unknown % 2 == 1 ? "No" : "Yes");
        }
    } else { //player
        if(K == 0){
            cout << (val[0] == "?" || stoi(val[0]) == 0 ? "Yes" : "No");
        } else {
            cout << (unknown % 2 == 1 ? "Yes" : "No");
        }
    }
}
