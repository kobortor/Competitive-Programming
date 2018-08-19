#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string S;
    cin >> S;

    int K;
    cin >> K;

    for(int a = 0; a < K; a++){
        if(S[a] != '1'){
            cout << S[a];
            return 0;
        }
    }

    cout << '1';
}
